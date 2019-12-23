#pragma once
#include "blackcard.h"

class StrongHold:public blackCard
{
private:
  int initialHonor;
  int initialMoney;
  int initialDefense;
public:
  StrongHold(string name,int c,int b1,int b2,int initialHonor,int initialMoney,int initialDefense)
  :blackCard(name,c,b1,b2),initialHonor(initialHonor),initialMoney(initialMoney),initialDefense(initialDefense)
  {

  }
/*  StrongHold(string name)
  :blackCard(name,0,false),
  {

  }*/
  //StrongHold( int H,int M,int D,)
};
