#pragma once
#include <string>
#include <iostream>
using namespace std;
class Card{
private:
string name;
int cost;
bool isTapped;
protected :
 bool isDead;
public:

  Card(string n,int c,bool is=false)
  :name(n),cost(c),isTapped(is),isDead(false){}
  void Untap(){
    if(!isDead)
    isTapped=false;
  }

  virtual bool canUse(){
    if (isTapped || isDead)
      return false;
    return true;
  }
  void tap(){
    isTapped=true;
  }
  virtual void Kill()
  {
    isDead=true;
  }
  virtual void print()=0;
  //getters
  string getname(){
    return name;
  }
  int isKilled(){
    return isDead;
  }
  int GetCost(){return cost;}
};
