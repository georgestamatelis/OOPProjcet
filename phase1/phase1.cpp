#include "phase1.hpp"
#include "../dependencies/Functionalities.hpp"

using namespace std;

phase1:: phase1(Player **pl,int n):players(pl),num_of_players(n){}

void phase1:: play(){
  SetToYellow();
  cout<<"┌───────────────────────┐\n"
	  <<"│ Phase 1 [Start phase] │\n"
	  <<"V                       V\n"<<endl;
  SetToDefault();
  qsort(players,num_of_players,sizeof(Player*),Honorcompare);
  for(int i=0;i<num_of_players;i++){
    SetToYellow();
    cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
    SetToDefault();
    players[i]->StartRound();//untap cards and initialize money for player
    players[i]->drawFateCard();
    players[i]->revealProvinces();
    players[i]->printHand(false);
    players[i]->printProvinces();
	PressEnter();
  }
}

phase1::~phase1(){
  cout<<"End of phase 1"<<endl;
}
