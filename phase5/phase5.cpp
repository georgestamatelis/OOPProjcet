#include "phase5.hpp"
#include "../dependencies/Functionalities.hpp"

using namespace std;

phase5::phase5(Player **players, int num_of_players) : players(players), num_of_players(num_of_players){}

void phase5::play(){
  SetToYellow();
  cout<<"┌─────────────────────┐\n"
	  <<"│ Phase 5 [End phase] │\n"
	  <<"V                     V\n"<<endl;
  cout << "Phase 5 [End phase]" << endl;
  SetToDefault();
  qsort(players, num_of_players, sizeof(Player *), Honorcompare);
  for (int i = 0; i < num_of_players; i++)
  {
    players[i]->discardSurplusFateCards();
  }
  for (int i = 0; i < num_of_players; i++)
  {
    SetToYellow();
    cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
    SetToDefault();
    players[i]->printHand();
    players[i]->printProvinces();
    players[i]->PrintHoldings();
  }
}

phase5::~phase5(){
  cout << "End of phase 5" << endl;
}
