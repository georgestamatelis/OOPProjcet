#include <iostream>
#include "Player.hpp"
#include "../dependencies/DeckBuilder.hpp"
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
		return false;
	}
	if(a->return_type() < b->return_type()){
		if(!a->has_upperholding() && !b->has_subholding())
			return true;
		return false;
	}
}
///////////////////////////////////////////////
Player::Player():life_points(4),money(0),numberOfProvinces(4),Honor("Perdikopanis"),honor_points(4){
	static DeckBuilder db;
	fateDeck=db.createFateDeck();
	lost=false;
	dynastyDeck=db.createDynastyDeck();
	int i;
	hand= new greenCard*[6];
	for(i=0; i<6; i++){
		hand[i]=NULL;
	}
  //honor_points=Honor.getInitialMoney();
  money=Honor.getInitialMoney();
	provinces["a"]= new Farmland("farm");
	provinces["b"]=new Mine("mine");
	provinces["c"]= new Attacker("Warrior");
	provinces["d"]= new Chancellor("Palpatine");

}
void Player::loosePersonalty(string name)
{
	for(int i=0;i<army.size();i++)
	{
		if(army[i]->getname()==name)
		 { cout<<"Killing"<<army[i]->getname()<<endl;
			 army[i]->Kill();
			 army.erase(army.begin()+i);
		 return;
	 }
	}
 	//provinces[name]->Kill();
 	//provinces.erase(name);
 //delete province[name];

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
	greenCard *FateCard=fateDeck->front();
	if(PlaceInHand(*FateCard)==true){
		fateDeck->erase(fateDeck->begin());
	}else cout << "Hand full!!!" << endl;
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

void Player::printHand(){
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL){
			cout << i << ". ";
			hand[i]->print();
		}
	}
}

void Player::printProvinces(){
	if(provinces.find("a")!=provinces.end())
  cout<<"a: "<<provinces["a"]->getname()<<endl;
	if(provinces.find("b")!=provinces.end())
	cout<<"b: "<<provinces["b"]->getname()<<endl;
	if(provinces.find("c")!=provinces.end())
	cout<<"c: "<<provinces["c"]->getname()<<endl;
	if(provinces.find("d")!=provinces.end())
	cout<<"d: "<<provinces["d"]->getname()<<endl;
}

void Player::AddPersonality(Personality *personality){
	army.push_back(personality);
//	personality->tap();
}

greenCard *Player::SeeHandCard(int CardIndex){
	if(CardIndex<6) return hand[CardIndex];
	return NULL;
}

/*bool Player::EquipPersonality(const std::string &name,greenCard * equipment){
	//asuming that name and cad index are valiable
	int i;

	if(GetPersonalityHonor(name)<equipment->get_minumumHonor()){
		cout << "Not enough honor to equip this personality" << endl;
	} return false;

	for(int i=0;i<army.size();i++){
	    if(name.compare(army[i]->getname())==0){
    		army[i]->Equip(equipment);
			return true;
    	}
	}
	return false;
}

bool Player::EquipPersonality(int index,greenCard * equipment){
	//asuming that name and cad index are valiable
	if(index >army.size()) return false;

	if(army[index]->getHonour()<equipment->get_minumumHonor()){
		cout << "Not enough honor to equip this personality" << endl;
	} return false;

	army[index]->Equip(equipment);

	return false;
}*/
Personality *Player::GetPersonality(int index){
	if( index>army.size() ){
		return NULL;
	} else return army[index];

}

void Player::AddHolding(Holding * province)
{
	for(int i=0;i<Holdings.size();i++)
	{
		if(Compatible(Holdings[i],province))
		{
			if(Holdings[i]->return_type() >province->return_type())
				merge(Holdings[i],province);
			else
				merge(province,Holdings[i]);
		}
	}
	province->tap();
	Holdings.push_back(province);
}
bool Player::AddProvince(string name) //erase that province from the provinces dictionary and replace
{
	if(provinces.find(name)==provinces.end())
		return false;
	if(!provinces[name]->canUse())
		return false;
	if(provinces[name]->isPersonality())
	{
		//cout<<"Soldier"<<endl;
		Personality *temp=(Personality*)provinces[name];
		if(money <temp->GetCost() )
		{
			cout<<"Sorry Player Doesn't have enough money ,money="<<money<<"  and cost ="<<provinces[name]->GetCost() <<endl;
			return false;
		}
		money-=temp->GetCost();
		AddPersonality(temp);
  }
	else{
		if(money <provinces[name]->GetCost())
		{
			cout<<"Sorry Player Doesn't have enough money, Players money="<<money<<"  and cost ="<<provinces[name]->GetCost() <<endl;
			return false;
		}
		money-=provinces[name]->GetCost();
		AddHolding((Holding*)provinces[name]);
	}
	//provinces.erase(name);
	//provinces[name]=NULL;
	DeckBuilder db;
 	db.deckShuffler(dynastyDeck);
	blackCard *newProvince=dynastyDeck->front();
	while(provinces.find(newProvince->getname())!=provinces.end())
	{db.deckShuffler(dynastyDeck);
	blackCard *newProvince=dynastyDeck->front();}
	provinces[name]=newProvince;

	return true;
}
void Player::printArmy(){
	int i=0;
	for(int i=0;i<army.size();i++){
		if(army[i]->canUse())
		cout << i << ". " << army[i]->getname() << endl;
	}
}

bool Player::GetMoney(unsigned int amount){
	if(amount<=money){
		money=money-amount;
		return true;
	} else return false;
}

void Player::AddMoney(unsigned int amount){
	money=money+amount; 
}

Player::~Player(){
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL) delete hand[i];
	}
	delete[] hand;
	for(list <greenCard*>::iterator it = fateDeck->begin(); it != fateDeck->end(); it++){
		delete (*it);
	}
	for(list <blackCard*>::iterator it = dynastyDeck->begin(); it != dynastyDeck->end(); it++){
		delete (*it);
	}
	for (auto node : provinces){
      	delete node.second;
	}
}
void Player::looseDefencePersonalities(string provinceName,int dmg){
	for(int i=0;i<Holdings.size();i++){
		if(Holdings[i]->getname()==provinceName){
			Holdings[i]->loosePersonalties(dmg);
		}
	}
}
void Player:: performSeppuku(){
	lost=true;
	cout<<"Player(name) got Fucked in the ass "<<endl;
}
void Player::looseProvince(string name)
{
	if(provinces.find(name)==provinces.end())
		return;
	looseHonor();
	cout <<"KILLING PROVINCE "<<provinces[name]->getname();
	provinces[name]->Kill();
	provinces.erase(name);

}
void Player:: discardSurplusFateCards()
{

}
void Player:: add_money(){//not this name
	for(int i=0;i<Holdings.size();i++)
		money+=Holdings[i]->get_harvest_value();
}

bool Player::CheckName(const string &name){
	for(int i=0;i<army.size();i++)
		if(name==army[i]->getname())
			return true;

	return false;
}
void Player::looseHonor()
{

	if(honor_points<=0)
		performSeppuku();
}
