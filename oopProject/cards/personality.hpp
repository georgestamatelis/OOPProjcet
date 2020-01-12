#pragma once
#include "blackcard.hpp"
#include "follower.hpp"
#include "item.hpp"
#include <vector>

class Personality:public blackCard
{
private:
  int attack,defense,honour;
  bool isDead;
  vector <follower*> guards;
  vector <Item*> equipment;
public:
  bool isPersonality(){return true;}
  int getHonour(){return honour;}
  int getDefence(){
    int sum=defense;
    for(int i=0;i<guards.size();i++)
    {
      sum+=guards[i]->get_defence_bonus();
    }
    for(int i=0;i<equipment.size();i++){
      sum+=equipment[i]->get_defence_bonus();
    }
    return sum;
    }
  int getAttack()
  {
    int sum=attack;
    for(int i=0;i<guards.size();i++)
    {
      sum+=guards[i]->get_attack_bonus();
    }
    for(int i=0;i<equipment.size();i++){
      sum+=equipment[i]->get_attack_bonus();
    }
    return sum;
  }
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
  void addFollower(follower *guard){ guards.push_back(guard);}
  void addEquipment(Item *it){
    equipment.push_back(it);
  }
  void Equip(greenCard *equipment){
		if( (equipment->GetType()).compare("item")==0 ){
			Item& eq = (Item&)(*equipment);//downcast
			addEquipment(&eq);
		}else if((equipment->GetType()).compare("follower")==0 ){
			follower& eq = (follower&)(*equipment);//downcast
			addFollower(&eq);
		}else cout << "Oh shit!!!!!!!!!!!!!!!" << endl;
	}

};
