#pragma once
#include "blackcard.hpp"
#include "follower.hpp"
#include "../dependencies/Functionalities.hpp"
#include "item.hpp"
#include <vector>
#define MAXF 15
#define MAXI 15

class Personality:public blackCard
{
private:
  int max_number_of_followers;
  int max_number_of_items;
  int attack,defense,honour;
  bool isDead;
  vector <follower*> guards;
  vector <Item*> equipment;
public:
  bool CanTakeItem(){return (equipment.size()<max_number_of_items);}
  bool CanTakeFollower(){return (guards.size()<max_number_of_followers);}
  bool isPersonality(){return true;}
  int getHonour(){return honour;}
  int getDefence()
  {
    int sum=defense;
    for(int i=0;i<guards.size();i++)
    {
      sum+=guards[i]->get_defence_bonus();
    }
    for(int i=0;i<equipment.size();i++){
      sum+=equipment[i]->get_defence_bonus();
    }
    return sum+getDefenerPoints();
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
  :blackCard(name,c,b1,b2),attack(attack),defense(defense),honour(honour),isDead(false),max_number_of_items(MAXI),max_number_of_followers(MAXF)
  {

  }
  bool check_dead(){
    return isDead;
  }

  void Attack(){
    if (!canUse())
      {
        cout<<"Card is either tapped  and you can't use it in this round or it was killed in a previous round"<<endl;
        return;
      }
    //attack
  }
  void Defend(){
    if (!canUse())
      {
        cout<<"Card is either tapped  and you can't use it in this round or it was killed in a previous round"<<endl;
        return;
      }
  }
  void print()
  {
    SetToRed();
    cout<<"Personality :"<<this->getname()<<endl;
    cout<<"Attack: "<<this->getAttack()<<endl;
    cout<<"Defence: "<<this->getDefence()<<endl;
    cout<<"Honor Points: "<<this->getHonour()<<endl;
    cout<<"---------------------------------------"<<endl;
    SetToDefault();
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
   void loosePersonalties(int sum)
   {
      for(int i=0;i<guards.size();i++){
        if(sum<=0)
          return;
        sum-=guards[i]->get_defence_bonus();
        guards[i]->Kill();
      }
   }
   void looseHonor()
   {
     honour-=1;
     if(honour<=0){
       Kill();
     }
   }
   void  hurtItems()
   {
     for(int i=0;i<equipment.size();i++){
       equipment[i]->looseDurability();
     }
   }
   void tapFollowers()
   {
     for(int i=0;i<guards.size();i++)
      guards[i]->tap();
   }
   void Kill(){
     isDead=true;
    // cout<<"Personality "<<getname()<<"got fucked up real good"<<endl;
     for(int i=0;i<guards.size();i++)
      guards[i]->Kill();
    isDead=true;
   }
   ~Personality(){
	   	for (auto g : guards) {
	    	delete g;
		}
	
		for (auto e : equipment) {
			delete e;
		}
   }
};
