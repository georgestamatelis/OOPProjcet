#pragma once
#include <iostream>
#include <vector>
#include "../player/Player.h"

class phase2{
	private:
		vector <Player*> *players;
		void BuyCards(Player &player);
		void BuyItem(Player &player);
		void BuyFollower(Player &player);
		void equipPhase(Player &player);
		void UpgradeCard(Player &player,greenCard *card);
		std::string GetPersonalityName(Player &player);
	public:
		phase2(vector <Player*> &players);
		void play();
		~phase2();
};
