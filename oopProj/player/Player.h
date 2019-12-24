#pragma once
#include <stack>
#include <vector>
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
	vector <greenCard*> fateDeck;
	vector <blackCard*> dynastyDeck;//provinces
	greenCard **hand;
	vector<Holding*> Holdings;//limits
	vector<Personality*> army;
	unsigned int life_points,money,numberOfProvinces;
	StrongHold Honour;	
public:
	Player();
	bool PlaceInHand(greenCard &Card);
	
	void untapEverything();
	greenCard* drawFateCard();
	void revealProvinces() {printProvinces();};

	void printHand();
	void printProvinces();
	~Player();	
};
