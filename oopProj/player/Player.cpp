#include <iostream>
#include "Player.h"
#include "../external dependencies/Deckbuilder.hpp"
using namespace std;

Player::Player():life_points(4),money(0),numberOfProvinces(4),Honour("Perdikopanis"){
	static DeckBuilder db; 
	fateDeck=db.createFateDeck();
	dynastyDeck=db.createDynastyDeck();
	int i;
	hand= new greenCard*[6];
	for(i=0; i<6; i++){
		hand[i]=NULL;
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
		(*it)->Utap();
	}
	for(list <blackCard*>::iterator it = dynastyDeck->begin(); it != dynastyDeck->end(); it++){
		(*it)->Utap();
	}
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL){
			hand[i]->Utap();
		}
	}
	for(list <Holding*> :: iterator it = Holdings.begin(); it != Holdings.end(); ++it){
		(*it)->Utap();
	}
	for(list <Personality*> :: iterator it = army.begin(); it != army.end(); ++it){
		(*it)->Utap();
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

void Player::AddPersonality(Personality *personality){
	army.push_front(personality);
}

void Player::printArmy(){
	for (list<Personality*>::iterator CurentCard = army.begin() ; CurentCard != army.end(); ++CurentCard)
    	(*CurentCard)->print();
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
}
