#pragma once
#include "card.hpp"

class blackCard:public Card
{
private:
 bool isRevealed;

public:
  blackCard(string n,int c ,bool b1=false,bool b2=false)
  :Card(n,c,b2),isRevealed(b1){}
  virtual bool isPersonality(){return false;}
  virtual int getDefence(){ return 0;}
  virtual void loosePersonalties(int n){
    cout<<"WRONG LOOSE PERSONALITIES"<<endl;
  }
};
