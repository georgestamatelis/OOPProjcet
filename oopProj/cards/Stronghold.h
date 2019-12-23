#pragma once
#include "blackcard.h"

class StrongHold:public blackCard
{
private:
  int initialHonor;
  int initialMoney;
  int initialDefense;
public:
  StrongHold(string name,int c=0,int initialHonor=5,int initialMoney=5,int initialDefense=5)
  :blackCard(name,c),initialHonor(initialHonor),initialMoney(initialMoney),initialDefense(initialDefense)
  {

  }

  //StrongHold( int H,int M,int D,)
};
