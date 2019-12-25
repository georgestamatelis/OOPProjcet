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
	for(list <Holding*> :: iterator it = Holdings.begin(); it != Holdings.end(); ++it){
		(*it)->Untap();
	}
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
	for (list<blackCard*>::iterator CurentCard = dynastyDeck->begin() ; CurentCard != dynastyDeck->end(); ++CurentCard)
    	(*CurentCard)->print();
}

bool Player::AddPersonality(Personality *personality){
	if(army.size()>60) return false;
	army.push_front(personality);
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
