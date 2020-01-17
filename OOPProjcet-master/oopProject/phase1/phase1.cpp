#include "phase1.hpp"
phase1:: phase1(Player **pl,int n)
:players(pl),num_of_players(n)
{

}
void phase1:: play(){
  for(int i=0;i<num_of_players;i++){
    players[i]->untapEverything();
    players[i]->drawFateCard();
    players[i]->revealProvinces();
    players[i]->printHand();
    players[i]->printProvinces();
  }
}
phase1::~phase1()
{
  cout<<"End of phase1"<<endl;
}
