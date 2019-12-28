#include <iostream>
#include "phase4.h"
#include "../player/Player.h"
#include "../player/Player.h"
#include "../cards/item.h"
#include "../cards/follower.h"
#include "../cards/Properties.h"
#include "../dependencies/Read.hpp"

using namespace std;

phase4::phase4(Player **player,int num_of_players)
:players(player),num_of_players(num_of_players)
{


}
void phase4::play(){
	char answer;
	cout<<"START OF PHASE 4"<<endl;
	 	for(int i=0;i<num_of_players;i++){
		cout<<"player "<<i+1<<"'s turn"<<endl;
		Player *player=players[i];
		cout<<"Economy phase\n"<<"Provinces:"<<endl;
		player->printProvinces();
		cout<<"would you like to buy any provinces? (y/n)" <<endl;
		cin >> answer;
		while(answer!='y' && answer!='n'){
			cout << "Please type 'y' for yes and 'n' for no:" << endl;
			cin >> answer;
		}
		if(answer=='y'){
			BuyProvince(*player);
		}
		cout<<"Army:"<<endl;
		player->printArmy();
	}
}
void phase4::BuyProvince(Player &player){
	Farmland *far;	Mine *mine;	GoldMine *MineG;	CrystalMine *MineC;	GiftsandFavour *GaF;
	//Plain
	int input;
	char answer;
	cout << "\nAvailable provinces to buy:\n 	1. Farmland (price) | 2. Mine (price) | 3. GoldMine (price) | 4. CrystalMine (price) | 5. GiftsandFavour (price)" << endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	Read::Int(input);
	while(input <0 || input >5){
		cout << "Wrong number!, please enter a number in 0-5" << endl;
		Read::Int(input);
	}
	switch(input) {
		case 0:
	    	return;
	    case 1:
	    	far = new Farmland("Farm");
	    	if( player.GetMoney(far->GetCost())==true /*&& player.CheckHonor(far->GetHonor())==true*/) {
	    		if( player.AddProvince(far) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete far;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete far;
			}
			break;
		case 2:
			mine = new Mine("mine");
	    	if( player.GetMoney(mine->GetCost())==true /*&& player.CheckHonor(mine->GetHonor())==true*/) {
	    		if( player.AddProvince(mine) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete mine;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete mine;
			}
			break;
		case 3:
			MineG = new GoldMine("MineG");
	    	if( player.GetMoney(MineG->GetCost())==true /*&& player.CheckHonor(MineG->GetHonor())==true*/) {
	    		if( player.AddProvince(MineG) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete MineG;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete MineG;
			}
			break;
		case 4:
			MineC = new CrystalMine("MineC");
	    	if( player.GetMoney(MineC->GetCost())==true /*&& player.CheckHonor(MineC->GetHonor())==true*/) {
	    		if( player.AddProvince(MineC) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete MineC;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete MineC;
			}
			break;
		case 5:
			GaF = new GiftsandFavour("GaF");
	    	if( player.GetMoney(GaF->GetCost())==true /*&& player.CheckHonor(GaF->GetHonor())==true*/) {
	    		if( player.AddProvince(GaF) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete GaF;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete GaF;
			}
			break;
	}
	cout << "Would you like to buy any other provinces? (y/n):" << endl;
	cin >> answer;
	while(answer!='y' && answer!='n'){
		cout << "Please type 'y' for yes and 'n' for no:" << endl;
		cin >> answer;
	}
	if(answer=='y') BuyProvince(player);
}

void phase4::BuyPersonality(Player &player){
	Attacker *att;	Defender *defend;	Champion *champ;	Chancellor *chancel;	Shogun *shog;
	int input;
	char answer;
	cout << "\nAvailable personalities to buy:\n 	1. Attacker (price) | 2. Defender (price) | 3. Champion (price) | 4. Chancellor (price) | 5. Shogun (price)" << endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	Read::Int(input);
	while(input <0 || input >5){
		cout << "Wrong number!, please enter a number in 0-5" << endl;
		Read::Int(input);
	}
	switch(input) {
		case 0:
	    	return;
	    case 1:
	    	att = new Attacker("Name");
	    	if( player.GetMoney(att->GetCost())==true && player.CheckHonor(att->getHonour())==true) {
	    		if( player.AddPersonality(att) == false ) {
	    			cout << "You have exceed the number of cards you can have in the deck!!" << endl;
	    			delete att;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete att;
			}
			break;
		case 2:
			defend = new Defender("Name");
	    	if( player.GetMoney(defend->GetCost())==true && player.CheckHonor(defend->getHonour())==true ) {
	    		if( player.AddPersonality(defend) == false ){
	    			cout << "You have exceeded the number of cards you can have in the deck!!" << endl;;
	    			delete defend;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete defend;
			}
			break;
		case 3:
			champ = new Champion("Name");
	    	if( player.GetMoney(champ->GetCost())==true && player.CheckHonor(champ->getHonour())==true) {
	    		if( player.AddPersonality(champ) == false ){
	    			cout << "You have exceeded the number of cards you can have in the deck!!" << endl;
	    			delete champ;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete champ;
			}
			break;
		case 4:
			chancel = new Chancellor("Name");
	    	if( player.GetMoney(chancel->GetCost())==true && player.CheckHonor(chancel->getHonour())==true) {
	    		if( player.AddPersonality(chancel) == false ){
	    			cout << "You have exceeded the number of cards you can have in the deck!!" << endl;
	    			delete chancel;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete chancel;
			}
			break;
		case 5:
			shog = new Shogun("Name");
	    	if( player.GetMoney(shog->GetCost())==true && player.CheckHonor(shog->getHonour())==true) {
	    		if( player.AddPersonality(shog) == false ){
	    			cout << "You have exceeded the number of cards you can have in the deck!!" << endl;
	    			delete shog;
	    		}
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete shog;
			}
			break;
	}
	cout << "Would you like to buy any other personalities? (y/n):" << endl;
	cin >> answer;
	while(answer!='y' && answer!='n'){
		cout << "Please type 'y' for yes and 'n' for no:" << endl;
		cin >> answer;
	}
	if(answer=='y')	BuyPersonality(player);
}

phase4::~phase4(){
	cout<<"End of phase 2"<<endl;
}
