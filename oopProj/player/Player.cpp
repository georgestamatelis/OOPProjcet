#include <iostream>
#include "Player.h"

using namespace std;

Player::Player():life_points(4),money(0),numberOfProvinces(4),Honour("Perdikopanis"){
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
	int i;
	for(i=0; i<fateDeck.size(); i++){
		fateDeck[i]->Utap();
	}
	for(i=0; i<dynastyDeck.size(); i++){
		dynastyDeck[i]->Utap();
	}
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL){
			hand[i]->Utap();
		}
	}
	for(i=0; i<Holdings.size(); i++){
		Holdings[i]->Utap();
	}
	for(i=0; i<army.size(); i++){
		army[i]->Utap();
	}
}

greenCard* Player::drawFateCard(){
	greenCard *FateCard=fateDeck.front();
	if(PlaceInHand(*FateCard)==true){
		fateDeck.erase(fateDeck.begin());
		return FateCard;
	}else return NULL;
}

void Player::printHand(){
	for(int i=0; i<6; i++){
		if(hand[i]!=NULL) hand[i]->print();
	}
}

void Player::printProvinces(){
	for (vector<blackCard*>::iterator CurentCard = dynastyDeck.begin() ; CurentCard != dynastyDeck.end(); ++CurentCard)
    	(*CurentCard)->print();
}

Player::~Player(){
	for(int i=0; i<6; i++){
		//if(hand[i]!=NULL) delete hand[i];
	}
	delete[] hand;
}