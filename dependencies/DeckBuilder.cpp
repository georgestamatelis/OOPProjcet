#include "DeckBuilder.hpp"

using namespace std;

DeckBuilder::DeckBuilder()
{
	black = new list<blackCard *>();
	green = new list<greenCard *>();
	srand(unsigned(time(NULL)));
}

DeckBuilder::~DeckBuilder()
{
	//No need for the deckbuilder to free any memory everything is handled from the player class
	/*list<blackCard *>::iterator it;
	list<greenCard *>::iterator it2;
	for (it = black->begin(); it != black->end(); it++)
	{
		black->remove((*it));
		delete *it;
		it = black->begin();
	}
	for (it2 = green->begin(); it2 != green->end(); it2++)
	{
		green->remove((*it2));
		delete *it2;
		it2 = green->begin();
	}
	delete black;
	delete green;*/
}

list<greenCard *> *DeckBuilder::createFateDeck()
{
	int i;
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		green->push_back(new Footsoldier("Peasants"));
	for (i = 0; i < NO_ARCHER; i++)
		green->push_back(new Archer("Elite Troops"));
	for (i = 0; i < NO_SIEGER; i++)
		green->push_back(new Sieger("Immortal Bushi"));
	for (i = 0; i < NO_CAVALRY; i++)
		green->push_back(new Cavalry("Unicorn Horses"));
	for (i = 0; i < NO_NAVAL; i++)
		green->push_back(new Atakebune("Yomi Ships"));
	for (i = 0; i < NO_BUSHIDO; i++)
		green->push_back(new Bushido("7 Samurai"));

	for (i = 0; i < NO_KATANA; i++)
		green->push_back(new Katana("Daijtso"));
	for (i = 0; i < NO_BOW; i++)
		green->push_back(new Bow("Yumi"));
	for (i = 0; i < NO_SPEAR; i++)
		green->push_back(new Spear("Kama"));
	for (i = 0; i < NO_NINJATO; i++)
		green->push_back(new Ninjato("Butterfly Dagger"));
	for (i = 0; i < NO_WAKIZASHI; i++)
		green->push_back(new Wakizashi("Kusanagi"));

	return green;
}

list<blackCard *> *DeckBuilder::createDynastyDeck()
{
	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for (i = 0; i < NO_DEFENSIVE; i++)
		black->push_back(new Defender("Footsoldiers"));
	//NO_ATTACKING 10
	for (i = 0; i < NO_ATTACKING; i++)
		black->push_back(new Attacker("Steadfast bushi"));
	//NO_SHOGUN	2
	black->push_back(new Shogun("Akodo Kaneka"));
	black->push_back(new Shogun("Isawa Shi en"));
	//NO_CHANCELLOR 2
	black->push_back(new Chancellor("Hida Shozen"));
	black->push_back(new Chancellor("Mirimuto Enishi"));
	//NO_CHAMPION 1
	black->push_back(new Champion("Hida Kisada"));
	//Create holdings
	for (i = 0; i < NO_PLAIN; i++)
		black->push_back(new Plain("Rice Fields"));
	for (i = 0; i < NO_FARMS; i++)
		black->push_back(new Farmland("Fish Farms"));
	for (i = 0; i < NO_MINE; i++)
		black->push_back(new Mine("Ashio Copper Mine"));
	for (i = 0; i < NO_GOLD_MINE; i++)
		black->push_back(new GoldMine("Konomai Gold Mine"));
	for (i = 0; i < NO_CRYSTAL_MINE; i++)
		black->push_back(new CrystalMine("Ichinokawa Crystal Mine"));
	for (i = 0; i < NO_SOLO; i++)
		black->push_back(new GiftsandFavour("Gifts and Favors"));

	return black;
}

void DeckBuilder::deckShuffler(list<blackCard *> *black)
{
	if(black->size() <5 ){//If the cards in the deck are about to end, or have ended.
		delete black;//Delete the current deck
		black=createDynastyDeck();//And replace it with a new one
		return; //the end the function since the new deck is already shuffled
	}
	vector<blackCard *> vect;
	list<blackCard *>::iterator it;
	for (it = black->begin(); it != black->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	black->clear();

	vector<blackCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		black->push_back((*it2));
}

void DeckBuilder::deckShuffler(list<greenCard *> *green)
{
	vector<greenCard *> vect;
	list<greenCard *>::iterator it;
	for (it = green->begin(); it != green->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	green->clear();

	vector<greenCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		green->push_back((*it2));
}
