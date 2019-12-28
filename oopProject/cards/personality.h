#pragma once
#include "blackcard.h"
#include "follower.h"
#include "item.h"
#include <vector>

class Personality:public blackCard
{
private:
  int attack,defense,honour;
  bool isDead;
  vector <follower*> guards;
  vector <Item*> equipment;
public:
  int getDefence(){return defense;}
  int getHonour(){return honour;}
  int getAttack(){return attack;}
  Personality(string name,int c,bool b1,bool b2,int attack,int defense,int honour,bool isDead)
  :blackCard(name,c,b1,b2),attack(attack),defense(defense),honour(honour),isDead(false)
  {

  }
  bool check_dead(){
    return isDead;
  }

  void Attack(){
    if (!canUse())
      {
        cout<<"Card is tapped you can't use it in this round"<<endl;
        return;
      }
    //attack
  }
  void Defend(){
    if (!canUse())
      {
        cout<<"Card is tapped you can't use it in this round"<<endl;
        return;
      }
  }
  void print()
  {
    cout<<"Personality :"<<this->getname()<<endl;
  }
  void Equip(follower *guard){ guards.push_back(guard); }
  void Equip(Item *it){ equipment.push_back(it); }
  void addFollower(follower *guard){ guards.push_back(guard);}
  void addEquipment(Item *it){ equipment.push_back(it);  }
};
