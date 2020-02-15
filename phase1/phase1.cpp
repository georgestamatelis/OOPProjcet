#include "phase1.hpp"
#include "../dependencies/Functionalities.hpp"

phase1:: phase1(Player **pl,int n):players(pl),num_of_players(n){}

void phase1:: play(){
  SetToYellow();
  cout<<"Phase 1 [Start phase]"<<endl;
  SetToDefault();
  qsort(players,num_of_players,sizeof(Player*),Honorcompare);
  for(int i=0;i<num_of_players;i++){
    SetToYellow();
    cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
    SetToDefault();
    players[i]->untapEverything();
    players[i]->drawFateCard();
    players[i]->revealProvinces();
    players[i]->printHand(false);
    players[i]->printProvinces();
  }
}

phase1::~phase1(){
  cout<<"End of phase 1"<<endl;
}
