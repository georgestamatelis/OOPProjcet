#pragma once
#include "../cards/item.h"
#include "../cards/Holding.h"
#include "../cards/personality.h"
#include "../cards/Stronghold.h"
#include "../cards/follower.h"
#include "../cards/Followers.h"
#include "../player/Player.h"
#include "../phase1/phase1.h"
#include "../phase3/phase3.h"
#include "../phase2/phase2.h"
#include "../phase4/phase4.h"
#include "../phase5/phase5.h"
class gameboard
{
private:
 int rounds;
 phase1 *P1;
 phase3 *P3;
 phase2 *P2;
 phase4 *P4;
 phase5 *P5;
 int num_of_players;
 Player ** players;
 vector <Card *> deadcards;
public:
  bool isWinner();
  gameboard();
  void printGameStatistics();
  void gamePlay();
  ~gameboard();

};
