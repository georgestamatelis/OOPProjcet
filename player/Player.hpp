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
#include "../dependencies/DeckBuilder.hpp"
#include <vector>

class Player{
	private:
		std::string name;
		std::list <greenCard*> *fateDeck;
		std::list <blackCard*> *dynastyDeck;
		greenCard **hand;
		bool lost;
		std::vector<Personality*> army;
		std::vector<Holding*> Holdings;
		std::unordered_map<std::string,blackCard*> provinces;
		unsigned int life_points,money,numberOfProvinces,honor_points;
		StrongHold Honor;
		DeckBuilder deckb;
	public:
		Player(std::string n);
		
		void AddHolding(Holding *province);
		bool AddProvince(std::string name);
		void AddPersonality(Personality *personality);
		
		void looseDefencePersonalities(std::string provinceName,int);
		void loosePersonalty(std::string name);
		void looseProvince(std::string name);
		void looseHonor();
		
		bool PlaceInHand(greenCard &Card);
		greenCard *DrawFromHand(int index);
		void drawFateCard();
		greenCard *SeeHandCard(int CardIndex);
		
		void printArmy();
		int printHand(bool numbers=true);
		void PrintHoldings();
		void printProvinces();
		void revealProvinces();
		
		void StartRound();//Untaps all cards and initializes money for the player
		void performSeppuku();
		bool GetMoney(unsigned int amount); //Removes requsted amount from player (if possible returns true)
		Personality *GetPersonality(int);
		int GetPersonalityHonor(std::string name);
		int getPersonalityDamage(std::string name);
		void discardSurplusFateCards();
		bool tap_holdings(int sum);
		
		bool HasArmy();
		inline int isAlive(){ return !lost;}
		inline bool CheckInHand(int index){if(index>=6) return false; return (hand[index]==NULL)? false : true;}
		bool CheckHonor(unsigned int amount){(amount<=honor_points)? true : false;}
		bool CheckName(const std::string &name);

		//Getters
		unsigned int SeeMoney() {return money;}
		unsigned int GetPlayerHonour() const {return honor_points;}
		const std::string &GetName(){return name;}
		std::unordered_map<std::string,blackCard*>& GetProvinces(){return provinces;}
		std::vector<Personality*>& getArmy(){return army;}
		int getInitalDefense(){return Honor.getInitialDefense();}
		
		~Player();
};
