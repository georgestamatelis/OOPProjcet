#pragma once
#include "greencard.h"

class follower:public greenCard
{
private:
  std::string type;
public:
  follower(string name,int cost,int aB,int dB,int mh,int eb,int ec,string text="follower")
  :greenCard(name,cost,aB,dB,mh,eb,ec,text)
  {
    type="follower";
  }
  void print(){
    cout<<"Follower: "<<getname()<<endl;
  }
  std::string GetType(){return type;}
};
