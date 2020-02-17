#pragma once
#include "greencard.hpp"

class follower : public greenCard{
  private:
    std::string type;

  public:
    follower(std::string name, int cost, int aB, int dB, int mh, int eb, int ec, std::string text = "follower")
        :greenCard(name, cost, aB, dB, mh, eb, ec, text){
      type = "follower";
    }

    std::string GetType() { return type; }
};
