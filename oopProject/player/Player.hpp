#pragma once
#include <list>
#include <unordered_map>
#include "../cards/item.hpp"
#include "../cards/Holding.hpp"
#include "../cards/personality.hpp"
#include "../cards/Personalities.hpp"
#include "../cards/Stronghold.hpp"
#include "../cards/follower.hpp"
#include "../cards/Followers.hpp"
#include "../cards/greencard.hpp"
#include <vector>
class Player
{
private:
	list <greenCard*> *fateDeck;
	list <blackCard*> *dynastyDeck;
	greenCard **hand;
	bool lost;
	std::vector<Personality *>army;
	std::vector<Holding *> Holdings;
	unordered_map<string,blackCard*> provinces;
	unsigned int life_points,money,numberOfProvinces,honor_points;
	StrongHold Honor;
public:
	Player();
	bool PlaceInHand(greenCard &Card);

	unordered_map<string,blackCard*>& GetProvinces(){return provinces;}

	void untapEverything();
	void drawFateCard();
	void revealProvinces() {printProvinces();};
  void performSeppuku();
	void printHand();
	void printProvinces();
	void discardSurplusFateCards();

	void AddPersonality(Personality *personality);
	greenCard *SeeHandCard(int CardIndex);
	bool EquipPersonality(const std::string &name,greenCard * equipment);
	bool AddProvince(string name);
	void printArmy();
	bool GetMoney(unsigned int amount);
	bool CheckHonor(unsigned int amount){(amount<=honor_points)? true : false;}
	vector<Personality* >getArmy(){return army;}
	int getInitalDefense(){return Honor.getInitialDefense();}
	void looseDefencePersonalities(string provinceName,int);
	void loosePersonalty(string name);
	void looseProvince(string name);
	int getPersonalityDamage(string name);
	void looseHonor(){honor_points-=1;}
	inline int isAlive(){ return !lost;}
	void add_money();
	inline bool HasArmy(){ (army[0]==NULL)? false : true;};
	bool CheckName(const std::string &name);
	inline bool CheckInHand(int index){if(index>=6) return false; return (hand[index]==NULL)? false : true;}
	greenCard* DrawFromHand(int index);
	void AddHolding(Holding * province);
	//int get
	~Player();
};
