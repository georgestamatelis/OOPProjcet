#pragma once
#include <iostream>
#include <vector>
#include "../player/Player.h"

class phase2{
	private:
		vector <Player*> *players;
		void BuyPersonality(Player &player);
		void UpgradePersonality(Personality *personality);
	public:
		phase2(vector <Player*> &players);
		void play();
		~phase2();
};
