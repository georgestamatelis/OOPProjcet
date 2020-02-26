#include <iostream>
#include "Player.hpp"
#include "../dependencies/Functionalities.hpp"
#include "./PlayerDependencies.hpp"
using namespace std;

Player::Player(string n):life_points(4),money(500),numberOfProvinces(4),Honor("Castle"),honor_points(4),name(n),lost(false){
	fateDeck=deckb.createFateDeck();
	dynastyDeck=deckb.createDynastyDeck();//Decks are required, since the deck shuffler is used
	int i;
	hand= new greenCard*[7];
	for(i=0; i<7; i++){
		hand[i]=NULL;//At the begining the player does not have cards in his hand
	}

	money=Honor.getInitialMoney();
	provinces["a"]= new Farmland("farm");
	provinces["b"]=new Mine("mine");
	provinces["c"]= new Attacker("Warrior");
	provinces["d"]= new Chancellor("Palpatine");

}

/*----------Add functions----------*/
void Player::AddHolding(Holding * province){
	for(int i=0;i<Holdings.size();i++){
		if(Compatible(Holdings[i],province)){
			if(Holdings[i]->return_type() >province->return_type())
				merge(Holdings[i],province);
			else
				merge(province,Holdings[i]);
		}
	}
	Holdings.push_back(province);
}

bool Player::AddProvince(string name){//Adds province to player (if possible) and shuffles deck
	if(provinces.find(name)==provinces.end()) return false;
	if(!provinces[name]->canUse()) return false;
	
	if(provinces[name]->isPersonality()){
		Personality *temp=(Personality*)provinces[name];
		if(!tap_holdings(temp->GetCost())){
			cout<<"Sorry Player doesn't have enough money, Players money="<<money<<" and cost="<<provinces[name]->GetCost() <<endl;
			return false;//If the player is not able to buy the province, false value is returned to take of the next actions needed in this case
		}
		AddPersonality(temp);
	}else{
		if(!tap_holdings(provinces[name]->GetCost())){//takes care of money
			cout<<"Sorry Player doesn't have enough money, Players money="<<money<<" and cost="<<provinces[name]->GetCost() <<endl;
			return false;
		}
		AddHolding((Holding*)provinces[name]);
	}
 	deckb.deckShuffler(dynastyDeck);//Shufle cards, so a new one is added where the bought one was
	provinces[name]=dynastyDeck->front();
	dynastyDeck->pop_front();
	provinces[name]->tap();
	return true;
}

void Player::AddPersonality(Personality *personality){
	cout<<"Player '"<<name<<"' buys personality: "<<personality->getname()<<endl;
	army.push_back(personality);
}

/*----------Loose functions----------*/
void Player::looseDefencePersonalities(string provinceName,int dmg){
	vector <blackCard *> temp=provinces[provinceName]->getDefenders();
	provinces[provinceName]->loosePersonalties(dmg);
	for(int i=0;i<temp.size();i++){
		Personality * soldier=(Personality *)temp[i];
		for(int j=0; j<army.size();j++){
			if(dmg<=0)
				return;
			if(army[i]->getname()==soldier->getname()){
				dmg-=army[j]->getDefence();
				army[j]->Kill();
			}
		}
	}
}

void Player::loosePersonalty(string name){
	for(int i=0;i<army.size();i++){
		if(army[i]->getname()==name){
			SetToRed();
			cout<<"Player '"<< this->name <<"' Loses soldier: "<<army[i]->getname()<<endl;
			SetToDefault();
			army[i]->Kill();
			return;
		}
	}
}

void Player::looseProvince(string name){
	if(provinces.find(name)==provinces.end()) return;
	looseHonor();
	SetToRed();
	cout <<"Player '"<< this->name <<"' Loses province: "<<provinces[name]->getname() << endl;
	SetToDefault();
	provinces[name]->Kill();
	delete provinces[name];
	provinces.erase(name);

}

void Player::looseHonor(){
	cout<<"Player looses Honor, new Honor points are: "<<honor_points-1<<endl;
 	honor_points-=1;
	if(honor_points<=0)
		performSeppuku();
}

/*----------Functions to acces the hand of the player----------*/
bool Player::PlaceInHand(greenCard &Card){
	for(int i=0; i<7; i++){
		if(hand[i]==NULL){
			hand[i]=&Card;
			return true;
		}
	}
	return false;
}

greenCard* Player::DrawFromHand(int index){
	if(index>6 || hand[index]==NULL) return NULL;
	int i;
	greenCard *card=hand[index];//Hold requested card in a variable
	for(i=index; i<6; i++){
		hand[i]=hand[i+1];//All the other cards after the requested are shifted (lefts no NULL column between the cards, and removes the requested)
	}
	hand[i]=NULL;
	return card;//The requested card can be returned, (removed from the hand from above)
}

void Player::drawFateCard(){
	deckb.deckShuffler(fateDeck);
	greenCard *FateCard=fateDeck->front();
	if(PlaceInHand(*FateCard)==true){//If player can draw a card
		fateDeck->erase(fateDeck->begin());//Draws one from the fate deck
	}else{
		cout << "Hand full!!!" << endl;
	}
}

greenCard *Player::SeeHandCard(int CardIndex){//Functions to just "see" card in players hand
	if(CardIndex<7) return hand[CardIndex];
	return NULL;
}

/*----------Print various informations about the player functions----------*/
void Player::printArmy(){
	int i=0;
	for(int i=0;i<army.size();i++){
		if(army[i]->canUse()){
			cout<<i+1<<endl;
			army[i]->print();
		}
	}
}


int Player::printHand(bool numbers){
	int count=-1;
	for(int i=0; i<7; i++){
		if(hand[i]!=NULL){
			if(numbers) cout << i << ". " << endl;
			hand[i]->print();
			count++;
		}
	}
	return count;
}

void Player::PrintHoldings(){//Only the usable ones are printed
	for(int i=0;i<Holdings.size();i++)
		if(Holdings[i]->canUse())
			Holdings[i]->print();
}

void Player::printProvinces(){
	if(provinces.find("a")!=provinces.end()){
		cout<<"a:"<<endl;
  		provinces["a"]->print();
	}
	
	if(provinces.find("b")!=provinces.end()){
		cout<<"b:"<<endl;
		provinces["b"]->print();
	}

	if(provinces.find("c")!=provinces.end()){
		cout<<"c:"<<endl;
		provinces["c"]->print();
  	}

	if(provinces.find("d")!=provinces.end()){
		cout<<"d:"<<endl;
		provinces["d"]->print();
	}
}

void Player::revealProvinces(){
	for(auto x: provinces)
		if(x.second->canUse())
			x.second->reveal();
}

/*----------Functionalities----------*/
void Player::StartRound(){//Functions that prepares player for a new round
	money=Honor.getInitialMoney();//Initilizing money for player, for this round (from stronghold)
	
	//Untaping all cards
	for(list <greenCard*>::iterator it = fateDeck->begin(); it != fateDeck->end(); it++){
		(*it)->Untap();
	}
	
	for(list <blackCard*>::iterator it = dynastyDeck->begin(); it != dynastyDeck->end(); it++){
		(*it)->Untap();
	}
	
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL){
			hand[i]->Untap();
		}
	}
	
  	for(auto x: provinces)
		x.second->Untap();

	for(int i=0;i<army.size();i++)
		if(army[i]!=NULL){
			army[i]->Untap();
			army[i]->UntapFolowers();
		}
}

void Player::performSeppuku(){
	lost=true;
	cout<<"Player '"<< name <<"' performed Seppuku"<<endl;
}

void Player::discardSurplusFateCards(){
	int card;
	if(hand[6]!=NULL){//if the player has 7 cards, then from the rules he needs to through one
		SetToYellow();
		cout << "You have exceded the maximum number of cards you can have in your hand!! Your hand:"<<endl;
		SetToDefault();
		printHand();
		SetToYellow();
		cout << "You have to discard one, please type it's number: ";
		SetToDefault();
		ReadInt(card);
		delete DrawFromHand(card); //Getting the selected card from the hand and deleting it
	}
}

bool Player::tap_holdings(int sum){
	if( sum >money && Holdings.size()==0) return false;
	sum-=money;
  	money-=sum;
	for(int i=0;i<Holdings.size();i++){
		if(Holdings[i]->canUse()){
			sum-=Holdings[i]->get_harvest_value();
			Holdings[i]->tap();
		}
		if(sum<=0) break;
	}
	if(sum>0){
		for(int i=0;i<Holdings.size();i++)
			Holdings[i]->Untap();
		money+=sum;
		return false;
	}
	return true;
}

/*----------Getters----------*/
bool Player::GetMoney(unsigned int amount){
	if(amount<=money){
		money=money-amount;
		return true;
	}else return false;
}

Personality *Player::GetPersonality(int index){
	if( index>army.size() ){
		return NULL;
	}else return army[index];

}

/*----------Check properties of player----------*/
bool Player::HasArmy(){
	if(army.size()<=0) return false;
  	for(int i=0;i<army.size();i++)
		if(army[i]->canUse())
			return true;

		return false;
}

/*----------Destructor----------*/
Player::~Player(){
	for(int i=0; i<7; i++){
		if(hand[i]!=NULL) delete hand[i];
	}
	delete[] hand;

	for (auto f : *fateDeck) {
    	delete f;
	}
	delete fateDeck;

	for (auto c : *dynastyDeck) {
		delete c;
	}

	delete dynastyDeck;

	for (auto a : army) {
		delete a;
	}

	for (auto h : Holdings) {
		delete h;
	}

	for (auto& it : provinces){
    	delete it.second;
	}
}