#pragma once
#include "blackcard.hpp"
#include "personality.hpp"
#include <vector>

class Holding:public blackCard
{
private:
  int harvestValue;//returns per round
  bool upperHolding,subHolding;
  vector<Personality *>defendants;
  bool full_chain;
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
    defendants.push_back(name);
  }
  int getDefenerPoints(){
    int sum=0;
    for(int i=0;i<defendants.size();i++){
      sum+=defendants[i]->getDefence();
    }
    return sum;
  }
  void loosePersonalties(int sum){
    for(int i=0;i<defendants.size();i++){
      if(sum<=0)
        return;
       sum-=defendants[i]->getDefence();
       defendants[i]->Kill();
    }
  }
  int get_harvest_value(){
    int total_money=harvestValue;
    if(upperHolding){
      if(return_type()==2)
      {
        if(!subHolding)
          total_money+=5;
        else
          total_money+=harvestValue;
      }
      else if(return_type()==1)
      {
        total_money+=2;
      }
    }
////////////////////////////////////
    if(subHolding){
      if(return_type()==3)
      {
        total_money+=harvestValue;
      }
      else if(return_type()==2){
        total_money+=4;
      }
    }
    return total_money;
  }
  virtual int return_type(){return 0;}
  bool has_upperholding(){return upperHolding;}
  bool has_subholding(){return subHolding;}
  void setU(){upperHolding=true;}
  void setS(){subHolding=true;}
  void setFC(){full_chain=true;}
};
