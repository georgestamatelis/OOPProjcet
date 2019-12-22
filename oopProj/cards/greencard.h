#pragma once
#include "card.h"

class greenCard:public Card
{
private:
  int AttackBonus;
  int defenseBonus;
  int minimumHonor,effectBonus,effectCost;
  string cardtext;
public:
  greenCard(string name,int cost,int AB,int DB,int mh,int eb,int ec,string t,bool b=false)
  :Card(name,cost,b),AttackBonus(AB),defenseBonus(DB),minimumHonor(mh),effectBonus(eb),
  effectCost(ec),cardtext(t)
  {

  }

};
