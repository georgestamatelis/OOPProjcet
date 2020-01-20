#include "phase1.hpp"
#include "../dependencies/Functionalities.hpp"

phase1:: phase1(Player **pl,int n)
:players(pl),num_of_players(n)
{

}
void phase1:: play(){
  qsort(players,num_of_players,sizeof(Player*),Honorcompare);
  for(int i=0;i<num_of_players;i++){
    SetToBlue();
    cout<<"Player: "<<players[i]->GetName()<<endl;
    SetToDefault();
    players[i]->untapEverything();
    players[i]->drawFateCard();
    players[i]->revealProvinces();
    players[i]->printHand(false);
    players[i]->printProvinces();
  }
}
phase1::~phase1()
{
  cout<<"End of phase1"<<endl;
}
