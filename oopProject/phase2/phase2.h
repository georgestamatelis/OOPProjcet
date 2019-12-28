#pragma once
#include <iostream>
#include <vector>
#include "../player/Player.h"

class phase2{
	private:
		vector <Player*> *players;
		void BuyPersonality(Player &player);
		void equipPhase(Player &player);
		void UpgradePersonality(Player &player,Personality *personality);
		bool YesOrNo();
	public:
		phase2(vector <Player*> &players);
		void play();
		~phase2();
};
