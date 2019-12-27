#pragma once
#include <string>
#include <iostream>
using namespace std;
class Card{
private:
string name;
int cost;
bool isDead;
bool isTapped;
public:
  Card(string n,int c,bool is=false)
  :name(n),cost(c),isTapped(is),isDead(false){}
  void Untap(){
    if(!isDead)
    isTapped=false;
  }

  bool canUse(){
    return (!isTapped && !isDead);
  }
  void tap(){
    isTapped=true;
  }
  void Kill()
  {
    isDead=true;
  }
  virtual void print()=0;
  //getters
  string getname(){
    return name;
  }
  int GetCost(){return cost;}
};
