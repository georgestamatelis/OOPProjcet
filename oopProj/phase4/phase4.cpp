#include <iostream>
#include "phase4.h"
#include "../player/Player.h"

using namespace std;

phase4::phase4(Player &player){
	cout<<"start of phase 2"<<endl;

	cout<<"Economy phase\n"<<"Provinces:"<<endl;
	player.printProvinces();
}

phase4::~phase4(){
	cout<<"End of phase 2"<<endl;
}