#pragma once
#include "blackcard.h"

class Personality:public blackCard
{
private:
  int attack,defense,honour;
  bool isDead;
  //+ folowers
public:
  Personality(string name,int c,bool b1,bool b2,int attack,int defense,int honour,bool isDead)
  :blackCard(name,c,b1,b2),attack(attack),defense(defense),honour(honour),isDead(isDead)
  {

  }
};
