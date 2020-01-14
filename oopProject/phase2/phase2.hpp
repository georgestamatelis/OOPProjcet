#pragma once
#include <iostream>
#include <vector>
#include "../player/Player.hpp"

class phase2{
	private:
		Player** GivenPlayers;
		int NumOfPlayers;
		void BuyCards(Player &player);
		void BuyItem(Player &player);
		void BuyFollower(Player &player);
		void equipPhase(Player &player);
		void UpgradeCard(Player &player,greenCard *card);
		std::string GetPersonalityName(Player &player);
	public:
		phase2(Player** players,int NumOP);
		void play();
		~phase2();
};
