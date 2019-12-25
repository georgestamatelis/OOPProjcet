#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

#include "../cards/card.h"
#include "../cards/blackcard.h"
#include "../cards/follower.h"
#include "../cards/Followers.h"
#include "../cards/footsoldier.h"
#include "../cards/greencard.h"
#include "../cards/Holding.h"
#include "../cards/item.h"
#include "../cards/items.h"
#include "../cards/personality.h"
#include "../cards/Personalities.h"
#include "../cards/Properties.h"
#include "../cards/Stronghold.h"


class TypeConverter
{
public:
	TypeConverter();
	void getCorrectType(BlackCard *card, Personality **person, Holding **hold);
	void getCorrectType(GreenCard *card, Follower **follow, Item **item);
	Personality *getPersonality(BlackCard *d);
	Holding *getHolding(BlackCard *d);
	Follower *getFollower(GreenCard *d);
	Item *getItem(GreenCard *d);
};

#endif
