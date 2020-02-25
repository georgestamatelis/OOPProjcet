#include <iostream>
#include "phase4.hpp"
#include "../player/Player.hpp"
#include "../player/Player.hpp"
#include "../cards/item.hpp"
#include "../cards/follower.hpp"
#include "../cards/Properties.hpp"
#include "../dependencies/Functionalities.hpp"
using namespace std;

phase4::phase4(Player **player,int num_of_players):players(player),num_of_players(num_of_players){}

void phase4::play(){
	bool FirstPurchase;
	string province;
	
	SetToYellow();
	cout<<"┌─────────────────────────┐\n"
	    <<"│ Phase 4 [Economy phase] │\n"
	    <<"V                         V\n"<<endl;
	cout<<"Phase 4 [Economy phase]"<<endl;
	SetToDefault();
	
	qsort(players,num_of_players,sizeof(Player*),Honorcompare);//Sorting players by honor
	
	for(int i=0;i<num_of_players;i++){
		SetToYellow();
		cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
		SetToDefault();
		cout<<"Provinces:"<<endl;
		FirstPurchase=true;
		players[i]->printProvinces();
		cout<<"Would you like to buy any provinces? (y/n): ";
		while(YesOrNo()==true){//While player wants to buy provinces
			if(FirstPurchase==false) {//If this is not the first purchase the provinces are re-printed to the user
				players[i]->printProvinces();
			}else FirstPurchase=false;
			cout<<"Which one: ";
			province=ReadString();
			while(players[i]->AddProvince(province)==false){//Loop until the user is able to buy a province
				cout << "Unable to buy this province, please type another: ";
				province=ReadString();
			}
			std::unordered_map<std::string,blackCard*>& prs =players[i]->GetProvinces();
			int uselesssum=0;
			for(auto x: prs)
				if(!x.second->canUse() && x.second->is_Revealed())
				  uselesssum++;
			if(uselesssum >=4){//If the player cant buy any more provinces
				cout<<"No more provinces available"<<endl;
				break;//The bying loop ends
			}
			cout<<"Would you like to buy any other province? (y/n): ";
		}
	}
}

phase4::~phase4(){
	cout<<"End of phase 4"<<endl;
}
