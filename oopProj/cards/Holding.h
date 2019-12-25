#pragma once
#include "blackcard.h"
#include "personality.h"
#include <vector>

class Holding:public blackCard
{
private:
  int harvestValue;//returns per round
  bool upperHolding,subHolding;
  vector<Personality *>defendants;
public:
  Holding(string name,int c,bool b1,bool b2,int hv,bool upH=false,bool subH=false)
  :blackCard(name,c,b1,b1),harvestValue(hv),upperHolding(upH),subHolding(subH)
  {}
  Holding(string name,int cost,int Harvest)
  :blackCard(name,cost,false,false),harvestValue(Harvest),upperHolding(false),subHolding(false)
  {}
  void print(){
    cout<<"Holding : "<<this->getname()<<endl;
  }
  void addDefandant(Personality* name){
    //cout<<"fack yes"<<endl;
    defendants.push_back(name);
  }
  int getDefenerPoints(){
    int sum=0;
    for(int i=0;i<defendants.size();i++){
      sum+=defendants[i]->getDefence();
    }
    return sum;
  }
};
