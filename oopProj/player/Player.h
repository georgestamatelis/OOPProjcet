#pragma once
#include <list>
#include <unordered_map>
#include "../cards/item.h"
#include "../cards/Holding.h"
#include "../cards/personality.h"
#include "../cards/Personalities.h"
#include "../cards/Stronghold.h"
#include "../cards/follower.h"
#include "../cards/Followers.h"
#include "../cards/greenCard.h"

class Player
{
private:
	list <greenCard*> *fateDeck;
	list <blackCard*> *dynastyDeck;
	greenCard **hand;
	list<Holding*> Holdings;//limits
	list<Personality*> army;
	unordered_map<string,Holding*> provinces;
	unsigned int life_points,money,numberOfProvinces;
	StrongHold Honour;	
public:
	Player();
	bool PlaceInHand(greenCard &Card);
	
	unordered_map<string,Holding*>& GetProvinces(){return provinces;}

	void untapEverything();
	void drawFateCard();
	void revealProvinces() {printProvinces();};

	void printHand();
	void printProvinces();

	void AddPersonality(Personality *personality);
	void printArmy();
	bool GetMoney(unsigned int amount);
	~Player();	
};
