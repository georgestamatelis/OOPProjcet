#pragma once
#include "greencard.h"

class follower:public greenCard
{
private:

public:
  follower(string name,int cost,int aB,int dB,int mh,int eb,int ec,string text="follower")
  :greenCard(name,cost,aB,dB,mh,eb,ec,text)
  {

  }
};
