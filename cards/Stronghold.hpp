#pragma once
#include "blackcard.hpp"

class StrongHold : public blackCard{
private:
  int initialHonor;
  int initialMoney;
  int initialDefense;

public:
  StrongHold(string name, int c = 0, int initialHonor = 5, int initialMoney = 50, int initialDefense = 5)
      : blackCard(name, c), initialHonor(initialHonor), initialMoney(initialMoney), initialDefense(initialDefense){}
  int getInitialHonor() { return initialHonor; }
  int getInitialMoney() { return initialMoney; }
  int getInitialDefense() { return initialDefense; }
  void print(){
    cout << "StrongHold name" << this->getname() << endl;
  }
  //StrongHold( int H,int M,int D,)
};
