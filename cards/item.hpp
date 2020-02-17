#pragma once
#include "greencard.hpp"

class Item : public greenCard{
  private:
    int durability;
    std::string type;

  public:
    Item(std::string name, int cost, int AB, int DB, int mh, int eb, int ec, int durability, std::string t = "item")
    :greenCard(name, cost, AB, DB, mh, eb, ec, t), durability(durability){
      type = "item";
    }

    void looseDurability(){
      durability -= 1;
      if (durability <= 0)
      {
        std::cout << "Item" << getname() << "is Destroyed" << std::endl;
        Kill();
      }
    }

    std::string GetType() { return type; }
};
