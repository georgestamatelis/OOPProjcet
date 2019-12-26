#include <iostream>
#include "Player.h"
#include "../dependencies/DeckBuilder.hpp"
using namespace std;

Player::Player():life_points(4),money(0),numberOfProvinces(4),Honor("Perdikopanis"),honor_points(1){
	static DeckBuilder db;
	fateDeck=db.createFateDeck();
	dynastyDeck=db.createDynastyDeck();
	int i;
	hand= new greenCard*[6];
	for(i=0; i<6; i++){
		hand[i]=NULL;
	}
  money=Honor.getInitialMoney();
	honor_points=Honor.getInitialMoney();
	provinces["farm"]= new Farmland("farm");
	provinces["mine"]=new Mine("mine");
	provinces["gold"]= new GoldMine("gold");
	provinces["crystal"]= new CrystalMine("crystal");

}
void Player::loosePersonalty(string name){

std::list<Personality* >::const_iterator iterator;
for (iterator = army.begin(); iterator != army.end(); ++iterator)
{ cout<<"Killing Personality with name: "<<name<<endl;
	if((*iterator)->getname()==name)
		(*iterator)->Kill();
}
}
int Player::getPersonalityDamage(string name){
	std::list<Personality* >::const_iterator iterator;
	for (iterator = army.begin(); iterator != army.end(); ++iterator)
	{
		if((*iterator)->getname()==name)
			return (*iterator)->getAttack();
	}
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
	for(list <Personality*> :: iterator it = army.begin(); it != army.end(); ++it){
		(*it)->Untap();
	}
}

void Player::drawFateCard(){
	greenCard *FateCard=fateDeck->front();
	if(PlaceInHand(*FateCard)==true){
		fateDeck->erase(fateDeck->begin());
	}else cout << "Hand full!!!" << endl;
}

void Player::printHand(){
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL) hand[i]->print();
	}
}

void Player::printProvinces(){
	for(auto x:provinces)
		x.second->print();
}

bool Player::AddPersonality(Personality *personality){
	if(army.size()>60) return false;
	army.push_front(personality);
	return true;
}
bool Player::EquipPersonality(std::string name){
	for (list<Personality*>::iterator CurentCard = army.begin() ; CurentCard != army.end(); ++CurentCard){
    	if(name.compare((*CurentCard)->getname())==0){

				 return true;
    	}
	}
	return false;
}

bool Player::AddProvince(Holding *province){
	if(provinces.size()>60) return false;
	provinces[province->getname()]=province;
	return true;
}
void Player::printArmy(){
	for (list<Personality*>::iterator CurentCard = army.begin() ; CurentCard != army.end(); ++CurentCard)
    	(*CurentCard)->print();
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
	cout<<"Player(name) got Fucked in the ass "<<endl;
}
void Player::looseProvince(string name)
{
	provinces[name]->Kill();
	provinces.erase(name);
	if (honor_points<=0){
		performSeppuku();
	}
}
