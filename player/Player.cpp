#include <iostream>
#include "Player.hpp"
#include "../dependencies/Functionalities.hpp"
using namespace std;

void merge(Holding *up,Holding *sub){
	//cout<<"MERGING\n"<<endl;
	sub->setU();
	up->setS();
	if(up->return_type()==3 && sub->return_type()==2 && sub->has_subholding())
		up->setFC();
}

bool Compatible(Holding *a,Holding *b){
	if(a->return_type() == b->return_type())
		return false;
	if(a->return_type() > b->return_type()){
		if(!a->has_subholding() && !b->has_upperholding())
			return true;
		else 
			return false;
	}
	if(a->return_type() < b->return_type()){
		if(!a->has_upperholding() && !b->has_subholding())
			return true;
		return false;
	}
}

///////////////////////////////////////////////
Player::Player(string n):life_points(4),money(500),numberOfProvinces(4),Honor("Castle"),honor_points(4),name(n),lost(false){
	fateDeck=deckb.createFateDeck();
	dynastyDeck=deckb.createDynastyDeck();
	int i;
	hand= new greenCard*[6];
	for(i=0; i<6; i++){
		hand[i]=NULL;
	}

	money=Honor.getInitialMoney();
	provinces["a"]= new Farmland("farm");
	provinces["b"]=new Mine("mine");
	provinces["c"]= new Attacker("Warrior");
	provinces["d"]= new Chancellor("Palpatine");

}

void Player::loosePersonalty(string name){
	for(int i=0;i<army.size();i++){
		if(army[i]->getname()==name){ 
			cout<<"Player "<<GetName()<<"Loses soldier : "<<army[i]->getname()<<endl;
			army[i]->Kill();
			/*delete army[i];//here i.c.o.b.
			army.erase(army.begin()+i);*/
			return;
		}
	}
}

int Player::getPersonalityDamage(string name){
	int i=0;
	while(army[i]!=NULL){
		if( (army[i]->getname()).compare(name)==0 )
			return army[i]->getAttack();
	}
	return -1;
}

int Player::GetPersonalityHonor(string name){
	int i=0;
	for(int i=0;i<army.size();i++){
	    if(name.compare(army[i]->getname())==0){
    		return army[i]->getHonour();
    	}
	}
	return -1;
}

bool Player::PlaceInHand(greenCard &Card){
	for(int i=0; i<6; i++){
		if(hand[i]==NULL){
			hand[i]=&Card;
			return true;
		}
	}
	return false;
}

void Player::untapEverything(){
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
		if(army[i]!=NULL)
			army[i]->Untap();
}

void Player::drawFateCard(){
	deckb.deckShuffler(fateDeck);
	greenCard *FateCard=fateDeck->front();
	//fateDeck->pop_front();
	if(PlaceInHand(*FateCard)==true){
		fateDeck->erase(fateDeck->begin());
	}else {
		cout << "Hand full!!!" << endl;
		//delete FateCard;
	}
}

greenCard* Player::DrawFromHand(int index){
	greenCard* tmp;
	int i,y;
	for(i=0; i<6; i++){
		if(hand[i]!=NULL){
			//if( name.compare(hand[i]->getname())==0 ){
				tmp=hand[i];
				for(y=i; y<5; y++){
					hand[y]=hand[y+1];
				}
				hand[y]=NULL;
				return tmp;
			//}
		}
	}
	return NULL;
}

void Player::printHand(bool numbers){
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL){
			if(numbers) cout << i << ". ";
			hand[i]->print();
		}
	}
}


void Player::printProvinces(){
	if(provinces.find("a")!=provinces.end()){
		cout<<"a:"<<endl;
  		provinces["a"]->print();}
	if(provinces.find("b")!=provinces.end()){
		cout<<"b:"<<endl;
		provinces["b"]->print();
	}

	if(provinces.find("c")!=provinces.end()){
		cout<<"c:"<<endl;
		provinces["c"]->print();
  	}

	if(provinces.find("d")!=provinces.end()){
		cout<<"d: "<<endl;
		provinces["d"]->print();
	}
}

void Player::AddPersonality(Personality *personality){
	army.push_back(personality);
//	personality->tap();
}

greenCard *Player::SeeHandCard(int CardIndex){
	if(CardIndex<6) return hand[CardIndex];
	return NULL;
}


Personality *Player::GetPersonality(int index){
	if( index>army.size() ){
		return NULL;
	} else return army[index];

}

void Player::AddHolding(Holding * province){
	for(int i=0;i<Holdings.size();i++){
		if(Compatible(Holdings[i],province)){
			if(Holdings[i]->return_type() >province->return_type())
				merge(Holdings[i],province);
			else
				merge(province,Holdings[i]);
		}
	}
	//province->tap();
	Holdings.push_back(province);
}

bool Player::AddProvince(string name) //erase that province from the provinces dictionary and replace
{
	if(provinces.find(name)==provinces.end()) return false;
	if(!provinces[name]->canUse()) return false;
	if(provinces[name]->isPersonality()){
		//cout<<"Soldier"<<endl;
		Personality *temp=(Personality*)provinces[name];
		if(!tap_holdings(temp->GetCost())){
			cout<<"Sorry Player doesn't have enough money , Players money="<<money<<"  and cost ="<<provinces[name]->GetCost() <<endl;
			return false;
		}
		AddPersonality(temp);
	}
	else{
		if(!tap_holdings(provinces[name]->GetCost())) //takes care of money
		{
			cout<<"Sorry Player doesn't have enough money, Players money="<<money<<"  and cost ="<<provinces[name]->GetCost() <<endl;
			return false;
		}
		AddHolding((Holding*)provinces[name]);
	}
	//provinces.erase(name);
	//provinces[name]=NULL;
 	deckb.deckShuffler(dynastyDeck);
	provinces[name]=dynastyDeck->front();
	dynastyDeck->pop_front();
	provinces[name]->tap();
	return true;
}
void Player::printArmy(){
	int i=0;
	for(int i=0;i<army.size();i++){
		if(army[i]->canUse()){
			cout<<i+1<<endl;
			army[i]->print();
		}
	}
}

bool Player::GetMoney(unsigned int amount){
	if(amount<=money){
		money=money-amount;
		return true;
	} else return false;
}

void Player::looseDefencePersonalities(string provinceName,int dmg){
	//cout<<"OF COURSE"<<endl;
	//cout<<"DAMAGE ="<<dmg<<"NAME IS"<<provinceName<<endl;
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
				/*delete army[i];//here i.c.o.b.
				army.erase(army.begin()+j);*/
			}
		}
	}
}
void Player:: performSeppuku(){
	lost=true;
	cout<<"Player:"<<name<<"performed Seppuku  "<<endl;
}

void Player::looseProvince(string name){
	if(provinces.find(name)==provinces.end())
		return;
	looseHonor();
	cout <<"PLAYER "<<GetName()<<"LOSES PROVINCE "<<provinces[name]->getname();
	provinces[name]->Kill();
	delete provinces[name];
	provinces.erase(name);

}

void Player::discardSurplusFateCards(){}//what the fuck is that

void Player:: add_money(){
	for(int i=0;i<Holdings.size();i++)
		money+=Holdings[i]->get_harvest_value();
}

bool Player::CheckName(const string &name){
	for(int i=0;i<army.size();i++)
		if(name==army[i]->getname() )
			return true;

	return false;
}

void Player::looseHonor(){
	cout<<"Player looses Honor, new Honor points are :"<<honor_points-1<<endl;
 	honor_points-=1;
	if(honor_points<=0)
		performSeppuku();
}

bool Player::HasArmy(){
	if(army.size()<=0) return false;
  	for(int i=0;i<army.size();i++)
		if(army[i]->canUse())//is that ok for dead?
			return true;
		else
			return false;
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
void Player:: revealProvinces(){
	for(auto x: provinces)
		if(x.second->canUse())
			x.second->reveal();
}

void Player::PrintHoldings(){
	for(int i=0;i<Holdings.size();i++)
		if(Holdings[i]->canUse())
			Holdings[i]->print();
}

Player::~Player(){
	for(int i=0; i<6; i++){
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
