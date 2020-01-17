#pragma once
#include "card.hpp"
#include <vector>
using namespace std;


class blackCard:public Card
{
private:
 bool isRevealed;
 vector<blackCard *>defendants;
public:
  blackCard(string n,int c ,bool b1=false,bool b2=false)
  :Card(n,c,b2),isRevealed(b1){
  }
  virtual bool isPersonality(){return false;}

  void addDefandant(blackCard *name)
  {
    defendants.push_back(name);
  }
  virtual int getDefence(){
    return getDefenerPoints();
  }
  int getDefenerPoints(){
    int sum=0;
    for(int i=0;i<defendants.size();i++){
      if(defendants[i]->canUse())
      sum+=defendants[i]->getDefence();
    }
    return sum;
  }
  void loosePersonalties(int sum){

    for(int i=0;i<defendants.size();i++){
       sum-=defendants[i]->getDefence();
       defendants[i]->Kill();
       defendants.erase(defendants.begin()+i);
       if(sum<=0)
         return;
    }
  }
  vector<blackCard*> getDefenders(){return defendants;}

};
