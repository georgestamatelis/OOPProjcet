#pragma once
#include "../cards/item.hpp"
#include "../cards/Holding.hpp"
#include "../cards/personality.hpp"
#include "../cards/Stronghold.hpp"
#include "../cards/follower.hpp"
#include "../cards/Followers.hpp"
#include "../player/Player.hpp"
#include "../phase1/phase1.hpp"
#include "../phase3/phase3.hpp"
#include "../phase2/phase2.hpp"
#include "../phase4/phase4.hpp"
#include "../phase5/phase5.hpp"

class gameboard{
	private:
		int rounds;
		phase1 *P1;
		phase3 *P3;
		phase2 *P2;
		phase4 *P4;
		phase5 *P5;
		int num_of_players;
		Player ** players;
		std::vector <Card *> deadcards;
		bool isWinner();
public:
		gameboard();
		void printGameStatistics();
		void gamePlay();
		~gameboard();
};
