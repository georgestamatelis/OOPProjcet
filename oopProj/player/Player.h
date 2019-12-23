#pragma once
#include <stack>
#include <vector>
#include "../cards/item.h"
#include "../cards/Holding.h"
#include "../cards/personality.h"
#include "../cards/Stronghold.h"
#include "../cards/follower.h"
#include "../cards/greenCard.h"

class Player
{
private:
	stack <greenCard> fateDeck;
	stack <blackCard> dynastyDeck;//provinces
	greenCard **hand;
	vector<Holding> Holdings;//limits
	vector<Personality> army;

	StrongHold Honour;

	unsigned int life_points,money,numberOfProvinces;

	void untapEverything();
	greenCard* drawFateCard();
	void revealProvinces();
	void printHand();
	void printProvinces();
public:
	Player();
	~Player();	
};
