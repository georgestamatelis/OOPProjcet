#include <iostream>
#include "phase4.hpp"
#include "../player/Player.hpp"
#include "../player/Player.hpp"
#include "../cards/item.hpp"
#include "../cards/follower.hpp"
#include "../cards/Properties.hpp"
#include "../dependencies/Functionalities.hpp"
using namespace std;

phase4::phase4(Player **player,int num_of_players)
:players(player),num_of_players(num_of_players){}

void phase4::play(){
	bool FirstPurchase;
	string province;
	SetToYellow();
	cout<<"Phase 4 [Economy phase]"<<endl;
	SetToDefault();
	qsort(players,num_of_players,sizeof(Player*),Honorcompare);
	for(int i=0;i<num_of_players;i++){
		SetToYellow();
		cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
		SetToDefault();
		cout<<"Economy phase\n"<<"Provinces:"<<endl;
		FirstPurchase=true;
		players[i]->printProvinces();
		cout<<"would you like to buy any provinces? (y/n): ";
		while(YesOrNo()==true){
			if(FirstPurchase==false) {
				players[i]->printProvinces();
			}else FirstPurchase=false;
			cout<<"Which one: ";
			province=ReadString();
			while(players[i]->AddProvince(province)==false){
				cout << "Unable to buy this province, please type another: ";
				province=ReadString();
			}
			cout<<"would you like to buy any other province? (y/n): ";
		}
	}
}

phase4::~phase4(){
	cout<<"End of phase 4"<<endl;
}
