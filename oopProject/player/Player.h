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
#include "../cards/greencard.h"

class Player
{
private:
	list <greenCard*> *fateDeck;
	list <blackCard*> *dynastyDeck;
	greenCard **hand;
	bool lost;
	list<Personality*> army;
	unordered_map<string,Holding*> provinces;
	unsigned int life_points,money,numberOfProvinces,honor_points;
	StrongHold Honor;
public:
	Player();
	bool PlaceInHand(greenCard &Card);

	unordered_map<string,Holding*>& GetProvinces(){return provinces;}

	void untapEverything();
	void drawFateCard();
	void revealProvinces() {printProvinces();};
  void performSeppuku();
	void printHand();
	void printProvinces();
	void discardSurplusFateCards();

	bool AddPersonality(Personality *personality);
	bool EquipPersonality(std::string name);
	bool AddProvince(Holding *province);
	void printArmy();
	bool GetMoney(unsigned int amount);
	bool CheckHonor(unsigned int amount){(amount<=honor_points)? true : false;}
  list<Personality*>& getArmy(){return army;}
	int getInitalDefense(){return Honor.getInitialDefense();}
	void looseDefencePersonalities(string provinceName);
	void loosePersonalty(string name);
	void looseProvince(string name);
	int getPersonalityDamage(string name);
	inline int isAlive(){ return !lost;}
	//int get
	~Player();
};
