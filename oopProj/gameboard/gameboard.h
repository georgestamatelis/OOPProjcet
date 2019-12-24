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
class gameboard
{
private:
 phase1 P1;
 int num_of_players;
 Player * players;
 vector <Card *> deadcards;
public:
  gameboard();
  void printGameStatistics();
  void gamePlay();
  ~gameboard();

};
