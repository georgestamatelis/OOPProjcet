#include "phase2.h"

using namespace std;

phase2::phase2(vector <Player> &giver_players):players(&giver_players){
	cout<<"Start of phase 2"<<endl;	
}

void phase2::play(){
	int i=1;
	for(vector <Player>::iterator CurentPlayer = players->begin(); CurentPlayer != players->end(); CurentPlayer++){
		cout << "Player number " << i << "\n\nHand cards:" << endl;
		CurentPlayer->printHand();
		cout << "Army: " << endl;
		CurentPlayer->printArmy();

		i++;
	}
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}