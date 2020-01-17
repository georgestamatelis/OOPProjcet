#include "phase5.hpp"

phase5 ::phase5(Player **players,int num_of_players)
:players(players),num_of_players(num_of_players)
{


}
void phase5:: play(){
  for(int  i=0;i<num_of_players;i++)
  {
    players[i]->discardSurplusFateCards();
  }
  for(int i=0;i<num_of_players;i++)
  {
      cout<<"Player :" <<players[i]->GetName()<<endl;
      players[i]->printHand();
      players[i]->printProvinces();
      players[i]->PrintHoldings();
  }
}
phase5:: ~phase5(){

}
