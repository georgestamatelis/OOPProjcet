#pragma once
#include "card.h"

class greenCard:public Card
{
private:
  int AttackBonus;
  int defenseBonus;
  int minimumHonor,effectBonus,effectCost;
  string cardtext;
public:
  greenCard(string name,int cost,int AB,int DB,int mh,int eb,int ec,string t,bool b=true)
  :Card(name,cost,b),AttackBonus(AB),defenseBonus(DB),minimumHonor(mh),effectBonus(eb),
  effectCost(ec),cardtext(t)
  {

  }
 int get_minumumHonor(){return minimumHonor;}
 int get_bonus_cost(){
   return effectCost;
 }
 int get_attack_bonus(){
   //we assume the user has checked if he can update
   return AttackBonus;
 }
 int get_defence_bonus(){
   return defenseBonus;
 }
 virtual std::string GetType() =0;
};
