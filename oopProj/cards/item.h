#pragma once
#include "greencard.h"

class Item:public greenCard
{
private:
  int durability;
public:
  Item(string name,int cost,int AB,int DB,int mh,int eb,int ec,int durability,string t="item")
  :greenCard(name,cost,AB,DB,mh,eb,ec,t),durability(durability)
  {}
};
