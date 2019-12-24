#include "phase1.h"

phase1 :: phase1()
{
  cout<<"How many players ? :";
  cin>>num_of_players;
  num_of_players-=1;
  players =new Player[num_of_players];
  for(int i=0;i<num_of_players;i++){
    players[i].untapEverything();
    players[i].drawFateCard();
    players[i].revealProvinces();
    players[i].printHand();
    players[i].printProvinces();
  }
}
phase1::~phase1()
{
  cout<<"End of phase1"<<endl;
}
