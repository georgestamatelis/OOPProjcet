#pragma once
#include "../external_dependencies/DeckBuilder.hpp"
#include "../player/Player.h"

class phase3{
private:
  int num_of_players;
  Player ** players;
  void Attack_Choice(int);
  void defence_Choise(int);
public:
  phase3(Player **pls,int n);
  void play();
  ~phase3();
};
