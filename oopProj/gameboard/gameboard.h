#pragma once
#include "../cards/item.h"
#include "../cards/Holding.h"
#include "../cards/personality.h"
#include "../cards/Stronghold.h"
#include "../cards/follower.h"

class gameboard
{
private:
  void deckbuilder();
public:
  gameboard();
  void printGameStatistics();
  void gamePlay();
  ~gameboard();


};
