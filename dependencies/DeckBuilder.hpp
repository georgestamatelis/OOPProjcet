#ifndef _DECKBUILDER_HPP_
#define _DECKBUILDER_HPP_

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

#include "../cards/card.hpp"
#include "../cards/Stronghold.hpp"
#include "../cards/personality.hpp"
#include "../cards/Holding.hpp"
#include "../cards/follower.hpp"
#include "../cards/item.hpp"
#include "../cards/Personalities.hpp"
#include "../cards/Properties.hpp"
#include "../cards/Followers.hpp"
#include "../cards/Items.hpp"

#define DECKSIZE          40
#define MAXDECKSIZE       60

#define NO_PERSONALITIES  25
#define NO_DEFENSIVE      10
#define NO_ATTACKING      10
#define NO_SHOGUN         2
#define NO_CHANCELLOR     2
#define NO_CHAMPION       1

#define NO_HOLDINGS       17
#define NO_PLAIN          3
#define NO_MINE           3
#define NO_GOLD_MINE      3
#define NO_CRYSTAL_MINE   3
#define NO_FARMS          3
#define NO_SOLO           2

#define NO_FOLLOWERS      28
#define NO_FOOTSOLDIER    6
#define NO_ARCHER         6
#define NO_SIEGER         4
#define NO_CAVALRY        5
#define NO_NAVAL          5
#define NO_BUSHIDO        2

#define NO_ITEMS          12
#define NO_KATANA         4
#define NO_SPEAR          3
#define NO_BOW            2
#define NO_NINJATO        2
#define NO_WAKIZASHI      1

class DeckBuilder
{
	private:
		std::list<greenCard*>* green;
		std::list<blackCard*>* black;
	public:
		DeckBuilder();
		~DeckBuilder();
		std::list<greenCard *>* createFateDeck();
	 	std::list<blackCard *>* createDynastyDeck();

	 	void deckShuffler(std::list<blackCard *> *black);
		void deckShuffler(std::list<greenCard *> *green);
};

#endif
