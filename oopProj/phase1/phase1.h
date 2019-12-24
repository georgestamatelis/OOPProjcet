#pragma once
#include "../dependencies/DeckBuilder.hpp"
#include "../player/Player.h"

class phase1
{
private:
  int num_of_players;
  Player *players;
public:
  phase1();
  ~phase1();
  //geters
  int getNumOfPlayers(){
    return num_of_players;
  }
  Player *get_Players(){
    return players;
  }
};
