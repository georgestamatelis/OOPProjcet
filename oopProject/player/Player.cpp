#include <iostream>
#include "Player.hpp"
#include "../dependencies/DeckBuilder.hpp"
using namespace std;

void merge(Holding *up,Holding *sub){
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
Player::Player():life_points(4),money(0),numberOfProvinces(4),Honor("Perdikopanis"),honor_points(1){
	static DeckBuilder db;
	fateDeck=db.createFateDeck();
	lost=false;
	dynastyDeck=db.createDynastyDeck();
	int i;
	hand= new greenCard*[6];
	for(i=0; i<6; i++){
		hand[i]=NULL;
	}
	for(i=0; i<4; i++){
		army[i]=NULL;
	}
  	money=Honor.getInitialMoney();
	honor_points=Honor.getInitialMoney();
	provinces["tester"]=new Plain("tester");
	provinces["farm"]= new Farmland("farm");
	provinces["mine"]=new Mine("mine");
	provinces["gold"]= new GoldMine("gold");
	provinces["crystal"]= new CrystalMine("crystal");

}
void Player::loosePersonalty(string name){
	int i=0,y;
	while(army[i]!=NULL && i<4){
		if( (army[i]->getname()).compare(name)==0 ){
			army[i]->Kill();
			army[i]=NULL;
			for(y=i; y<3; y++){
				if(army[y+1]!=NULL){
					army[y]=army[y+1];
					army[y+1]=NULL;
				}
			}
		}
		i++;	
	}
}
int Player::getPersonalityDamage(string name){
	int i=0;
	while(army[i]!=NULL && i<4){
		if( (army[i]->getname()).compare(name)==0 )
			return army[i]->getAttack();	
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
	
	int i;
	while(army[i]!=NULL && i<4){
		army[i]->Untap();	
		i++;
	}
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
	for(auto x:provinces)
	 if(x.second->canUse())
		x.second->print();
}

bool Player::AddPersonality(Personality *personality){
	for(int i=0; i<4; i++){
		if(army[i]==NULL){
			army[i]=personality;
			return true;
		}
	}
	return false;
}

greenCard *Player::SeeHandCard(int CardIndex){
	if(CardIndex<6) return hand[CardIndex];
	return NULL;
}

bool Player::EquipPersonality(const std::string &name,greenCard * equipment){
	//asuming that name and cad index are valiable
	int i;
	while(army[i]!=NULL && i<4){
	    if(name.compare(army[i]->getname())==0){
    		army[i]->Equip(equipment);
			return true;
    	}
		i++;
	}
	return false;
}

bool Player::AddProvince(Holding *province){
	if(provinces.size()>60) return false;
	for(auto x: provinces)
	{
		if(Compatible(x.second,province))
		{
			if(x.second->return_type() >province->return_type())
				merge(x.second,province);
			else
				merge(province,x.second);
		}
	}
	provinces[province->getname()]=province;
	return true;
}
void Player::printArmy(){
	int i=0;
	while(army[i]!=NULL && i<4){
    	army[i]->print();
    	i++;
	}
}

bool Player::GetMoney(unsigned int amount){
	if(amount<=money){
		money=money-amount;
		return true;
	} else return false;
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
void Player::looseDefencePersonalities(string provinceName){
	unordered_map<string,Holding*>::iterator province;
	province=provinces.find(provinceName);
	if (province != provinces.end()){// Check if iterator points to end of map
		province->second->Kill();
	}else cout << "Error!! province: " << provinceName << " does not exist" << endl;
}
void Player:: performSeppuku(){
	lost=true;
	cout<<"Player(name) got Fucked in the ass "<<endl;
}
void Player::looseProvince(string name)
{	cout <<"Kiling province "<<name;
	provinces[name]->Kill();
	provinces.erase(name);
	if (honor_points<=0){
		performSeppuku();
	}
}
void Player:: discardSurplusFateCards(){

}
void Player:: add_money(){
	for(auto x: provinces)
		money+=x.second->get_harvest_value();
}
bool Player::CheckName(const string &name){
	int i=0;
	while(army[i]!=NULL && i<4){
		if(name.compare(army[i]->getname())==0){
			return true;
		}
		i++;
	}
	return false;
}
