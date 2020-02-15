#pragma once
#include "greencard.hpp"

class Item : public greenCard{
  private:
    int durability;
    std::string type;

  public:
    Item(string name, int cost, int AB, int DB, int mh, int eb, int ec, int durability, string t = "item")
    :greenCard(name, cost, AB, DB, mh, eb, ec, t), durability(durability){
      type = "item";
    }

    void looseDurability(){
      durability -= 1;
      if (durability <= 0)
      {
        cout << "Item" << getname() << "is Destroyed" << endl;
        Kill();
      }
    }

    std::string GetType() { return type; }
};
