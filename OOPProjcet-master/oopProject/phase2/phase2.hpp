#pragma once
#include <iostream>
#include <vector>
#include "../player/Player.hpp"

class phase2{
	private:
		Player** GivenPlayers;
		int NumOfPlayers;
		void equipPhase(Player &player);
	public:
		phase2(Player** players,int NumOP);
		void play();
		~phase2();
};
