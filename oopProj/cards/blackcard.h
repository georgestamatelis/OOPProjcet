#pragma once
#include "card.h"

class blackCard:public Card
{
private:
 bool isRevealed;

public:
  blackCard(string n,int c ,bool b1,bool b2=false)
  :Card(n,c,b2),isRevealed(b1){}
};
