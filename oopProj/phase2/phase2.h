#pragma once
#include <iostream>
#include <vector>
#include "../player/player.h"

class phase2{
	private:
		vector <Player> *players;
	public:
		phase2(vector <Player> &players);
		void play();
		~phase2();
};