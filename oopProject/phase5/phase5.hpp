#pragma once
#include "../player/Player.hpp"

class phase5
{
private:
    Player **players;
    int num_of_players;
public:
   phase5(Player **players,int num_of_players);
   void play();
   ~phase5();
};
