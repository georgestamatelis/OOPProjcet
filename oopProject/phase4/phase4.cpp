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
	cout<<"START OF PHASE 4"<<endl;
	//APPLY THE SHORT FUNCTION HERE
	for(int i=0;i<num_of_players;i++)
	{
		cout << "Player " << players[i]->GetName() << " turn:" << endl;
		Player *player=players[i];
		cout<<"Economy phase\n"<<"Provinces:"<<endl;
		player->printProvinces();
		cout<<"would you like to buy any provinces? (y/n)" <<endl;
		if(YesOrNo()==true){
			cin.ignore();
		  cout<<"Which one??"<<endl;
			char answer[40];
			cin.getline(answer,40);
			string  str(answer);
			cout<<str<<endl;
			players[i]->AddProvince(str);

			//BuyProvince(*player);
		}
	}
}

phase4::~phase4(){
	cout<<"End of phase 2"<<endl;
}
