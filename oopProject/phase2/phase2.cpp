#include <iostream>
#include <sstream>
#include <limits>
#include "phase2.hpp"
#include "../cards/Items.hpp"
#include "../player/Player.hpp"
#include "../dependencies/Functionalities.hpp"
using namespace std;

phase2::phase2(Player** GP,int NumOP):GivenPlayers(GP),NumOfPlayers(NumOP){}

void phase2::play(){
	cout<<"Start of phase 2"<<endl;
	//sort
	qsort(GivenPlayers,NumOfPlayers,sizeof(Player*),Honorcompare);
	for(int i=0; i<NumOfPlayers; i++){
		cout << "Player number " << i;
		if( GivenPlayers[i]->HasArmy()==true ){
			cout << "\n\nWould you like to buy cards from your hand? (y/n)" << endl;
			if(YesOrNo()==true)	equipPhase(*GivenPlayers[i]);
		}else cout << " does not have a army to equip!" << endl;
		i++;
	}
}

void phase2::equipPhase(Player &player){
	bool equiping=true,equiped;
	string name;
	int num;
	const Personality *pers;
	do{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Your hand cards:" << endl;
		player.printHand();
		cout << "Number of card in hand: ";
		ReadInt(num);
		while(player.CheckInHand(num)==false){
			cout << "The number of the card you typed does not exist, please retype the number of the card you want from hand" << endl;
			ReadInt(num);
		}

		if( player.GetMoney(player.SeeHandCard(num)->GetCost())==true) {
			greenCard *card=player.DrawFromHand(num);

			cout << "Would you like to upgrade this card? (y/n): " <<endl;
			if(YesOrNo()==true){
				if(player.CheckHonor(card->get_minumumHonor())){
					if(player.GetMoney(card->get_bonus_cost())==true){
						card->upgrade();
					}else cout <<"Upgrade of card  failed not enough money!"<< endl;
				}else cout <<"Upgrade of card  failed not enough honor!"<< endl;
			}

			do{
				equiped=false;
				player.printArmy();
				cout << "Please type the number of the personality you want to equip" << endl;
				cout << "Number of personality: ";
				ReadInt(num);
				while( (pers=player.GetPersonality(num))==NULL ){
					cout << "Invalid number of personality, please type the correct one: ";
					ReadInt(num);
				}

				while(player.EquipPersonality(num,card)==false){
					cout << "Would you like to equip another? (y/n)" << endl;
					if(YesOrNo()){
						equiped=true;
					}else{
						player.PlaceInHand(*card);
						equiped=false;
					}
				}

			}while(equiped);

		}else cout << "Not enough money!!" << endl;

		cout << "Would you like to Equip any other personalities? (y/n): ";
		equiping=YesOrNo();
	}while(equiping);
}

string phase2::GetPersonalityName(Player &player){
	string name;
	name=ReadString();
	while(player.CheckName(name)==false){
		cout << "The name you gave does not exist, please retype the name of the personality you want to equip" << endl;
		name=ReadString();
	}
	return name;
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}
