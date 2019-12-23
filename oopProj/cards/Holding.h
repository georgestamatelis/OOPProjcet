#pragma once
#include "blackcard.h"

class Holding:public blackCard
{
private:
  int harvestValue;//returns per round
  bool upperHolding,subHolding;
public:
  Holding(string name,int c,bool b1,bool b2,int hv,bool upH=false,bool subH=false)
  :blackCard(name,c,b1,b1),harvestValue(hv),upperHolding(upH),subHolding(subH)
  {}
  Holding(string name,int cost,int Harvest)
  :blackCard(name,cost,false,false),harvestValue(Harvest),upperHolding(false),subHolding(false)
  {}
};
