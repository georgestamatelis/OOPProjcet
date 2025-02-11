#pragma once
#include "card.hpp"
#include "../dependencies/Functionalities.hpp"

class greenCard : public Card{
  private:
    int AttackBonus;
    int defenseBonus;
    int minimumHonor, effectBonus, effectCost;
    std::string cardtext;

  public:
    greenCard(std::string name, int cost, int AB, int DB, int mh, int eb, int ec, std::string t, bool b = true)
        : Card(name, cost, b), AttackBonus(AB), defenseBonus(DB), minimumHonor(mh), effectBonus(eb),
          effectCost(ec), cardtext(t){}

    void upgrade(){
      //we assume check has allready been done and money removed
      AttackBonus += effectBonus;
      defenseBonus += effectBonus;
      effectBonus = 0;
    }

    void print(){
      SetToGreen();
	  std::cout << "┌─────────────────────────┐\n" 
                << "│greenCard: " << getname() << "\n"
                << "│Type: " << cardtext << "\n"
                << "│AttackBonus: " << AttackBonus << "\n"
                << "│defenseBonus: " << defenseBonus << "\n"
                << "│Upgrade Cost: " << effectCost << "\n"
                << "│minimumHonor :" << get_minumumHonor() << "\n"
                << "└─────────────────────────┘" << std::endl;
      SetToDefault();
    }

    //getters
    int get_minumumHonor() { return minimumHonor; }
    int get_bonus_cost(){return effectCost;}
    int get_attack_bonus(){
      //we assume the user has checked if he can update
      return AttackBonus;
    }
    int get_defence_bonus(){
      return defenseBonus;
    }
    virtual std::string GetType() = 0;
};
