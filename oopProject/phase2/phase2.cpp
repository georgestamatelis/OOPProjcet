#include <iostream>
#include <sstream>
#include <limits>
#include "phase2.hpp"
#include "../cards/Items.hpp"
#include "../player/Player.hpp"
#include "../dependencies/Functionalities.hpp"
using namespace std;

string phase2::GetPersonalityName(Player &player){
	string name;
	name=ReadString();
	while(player.CheckName(name)==false){
		cout << "The name you gave does not exist, please retype the name of the personality you want to equip" << endl;
  //  cin.ignore();
		name=ReadString();
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return name;
}

phase2::phase2(Player** GP,int NumOP):GivenPlayers(GP),NumOfPlayers(NumOP){}

void phase2::play(){
	cout<<"Start of phase 2"<<endl;
	//sort
	qsort(GivenPlayers,NumOfPlayers,sizeof(Player*),Honorcompare);
	for(int i=0; i<NumOfPlayers; i++){
	//for(vector <Player*>::iterator CurentPlayer = players->begin(); CurentPlayer != players->end(); CurentPlayer++){
		cout << "Player number " << i;
		if( GivenPlayers[i]->HasArmy()==true ){
			cout << "\n\nWould you like to equip your army with cards from your hand? (y/n)" << endl;
			if(YesOrNo()==true)	equipPhase(*GivenPlayers[i]);
			cout << "Would you like to buy cards to equip your army? (y/n)" << endl;
			if(YesOrNo()==true)	BuyCards(*GivenPlayers[i]);
		}else cout << " does not have a army to equip!" << endl;
		i++;
	}
}

void phase2::equipPhase(Player &player){
	bool equiping=true;
	string name;
	int num;
	do{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//if(player.hppasArmy()==false) {cout << "Sorry, you dont have an army to equip." << endl; return;}
		cout << "Your hand cards:" << endl;
		player.printHand();
		cout << "Your army: " << endl;
		player.printArmy();
		cout << "Please type the name of the personality and the number of the item you want to equip him with" << endl;
		cout << "Name of personality: ";
		name=GetPersonalityName(player);
		cout << "Number of card in hand: ";
		ReadInt(num);
		while(player.CheckInHand(num)==false){
			cout << "The number of the card you typed does not exist, please retype the number of the card you want from hand" << endl;
			ReadInt(num);
		}
		player.EquipPersonality(name,player.SeeHandCard(num));
		cout << "Would you like to Equip any other personalities? (y/n): ";
		equiping=YesOrNo();
	}while(equiping);
}

void phase2::BuyCards(Player &player){
	bool buying=true;
	do{
		cout << "Would you like to buy: (a) Item or (b) Follower" << endl << "Please type 'a' or 'b': ";
		if(YesOrNo('a','b',"Please type 'a' for Item or 'b' for Follower: ")==true){
			BuyItem(player);
		}else BuyFollower(player);
		cout << "Would you like to buy any other Cards to equip your army? (y/n): " << endl;
		buying=YesOrNo();
	}while(buying);
}

void phase2::BuyItem(Player &player){
	greenCard *new_card;
	int input;
	string name;
	cout << "\nAvailable Items to buy:\n 	1. Katana price::"<<5<<"| 2. Spear price: "<<5<<" | 3. Bow price: "<< 30 <<" | 4. Ninjato price: "<< 15<<" | 5. Wakizashi price: " << 15<< endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	ReadInt(input);
	while(input<0 || input>5){
		cout << "Wrong number!, please enter a number in 0-5" << endl;
		ReadInt(input);
	}
	switch(input) {
		case 0:
	    	return;
	    case 1:
	    	new_card = new Katana("Name");
			break;
		case 2:
			new_card = new Spear("Name");
			break;
		case 3:
			new_card = new Bow("Name");
			break;
		case 4:
			new_card = new Ninjato("Name");
			break;
		case 5:
			new_card = new Wakizashi("Name");
			break;
	}
	if( player.GetMoney(new_card->GetCost())==true) {
		cout << "Would you like to upgrade this card? (y/n): " <<endl;
		if(YesOrNo()==true) UpgradeCard(player,new_card);
	   	cout << "Your army: " << endl;
		player.printArmy();
	   	cout << "Type the name of the personality you want to equip with this card: ";
	   	name=GetPersonalityName(player);
	   	if(player.EquipPersonality(name,new_card)==false){
					//check
			}
	}else{
		cout << "Not enough money!!" << endl;
		delete new_card;
	}
}

void phase2::BuyFollower(Player &player){
	greenCard *new_card;
	int input;
	string name;
	cout << "\nAvailable Followers to buy:\n 	1. Footsoldier price::"<<5<<"| 2. Archer price: "<<5<<" | 3. Sieger price: "<< 30 <<" | 4. Cavalry price: "<< 15
		 <<" | 5. Atakebune price: " << 15<< "| 6. Bushido price :" << endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	ReadInt(input);
	while(input<0 || input>6){
		cout << "Wrong number!, please enter a number in 0-5" << endl;
		ReadInt(input);
	}
	switch(input) {
		case 0:
	    	return;
	    case 1:
	    	new_card = new Footsoldier("Name");
			break;
		case 2:
			new_card = new Archer("Name");
			break;
		case 3:
			new_card = new Sieger("Name");
			break;
		case 4:
			new_card = new Cavalry("Name");
			break;
		case 5:
			new_card = new Atakebune("Name");
			break;
		case 6:
			new_card = new Bushido("Name");
			break;
	}

	if( player.GetMoney(new_card->GetCost())==true) {
		cout << "Would you like to upgrade this card? (y/n): " <<endl;
		if(YesOrNo()==true) UpgradeCard(player,new_card);
	   	cout << "Your army: " << endl;
		player.printArmy();
	   	cout << "Type the name of the personality you want to equip with this card: ";
	   	name=GetPersonalityName(player);
	   	player.EquipPersonality(name,new_card);
	}else{
		cout << "Not enough money!!" << endl;
		delete new_card;
	}
}

void phase2::UpgradeCard(Player &player,greenCard *card){
	if(player.CheckHonor(card->get_minumumHonor())){
		if(player.GetMoney(card->get_bonus_cost())==true){
			card->upgrade();
		}else cout <<"Upgrade of card  failed not enough money!"<< endl;
	}else cout <<"Upgrade of card  failed not enough honor!"<< endl;
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}
