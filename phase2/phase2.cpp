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
	SetToYellow();
	cout<<"Phase 2 [Equiping phase]"<<endl;
	SetToDefault();
	qsort(GivenPlayers,NumOfPlayers,sizeof(Player*),Honorcompare);
	for(int i=0; i<NumOfPlayers; i++){
		SetToYellow();
		cout << "Player '" << GivenPlayers[i]->GetName() << "' turn:" << endl;
		SetToDefault();
		if( GivenPlayers[i]->HasArmy()==true ){
			cout << "\n\nWould you like to buy cards from your hand? (y/n): ";
			if(YesOrNo()==true)	equipPhase(*GivenPlayers[i]);
		}else cout << " Does not have a army to equip!" << endl;

	}
}

void phase2::equipPhase(Player &player){
	bool equiping=true,equiploop,upgrade;
	string name;
	int num,CardIndex,CardsCount;
	unsigned int TotalCost;
	Personality *pers;
	greenCard *card;
	do{
		TotalCost=0;
		upgrade=false;

		cout << "Your hand cards:" << endl;
		CardsCount=player.printHand();
		if(CardsCount==-1){
			cout << "Your hand is empty!!!" << endl;
			return;
		}
		cout << "Number of card in hand: ";
		ReadInt(CardIndex);
		while(CardIndex>CardsCount || player.CheckInHand(CardIndex)==false){
			cout << "The number of the card you typed does not exist, please retype the number of the card you want from hand: ";
			ReadInt(CardIndex);
		}

		card=player.SeeHandCard(CardIndex);
		if( player.SeeMoney()>=card->GetCost() ) {
			TotalCost+=card->GetCost();

			cout << "Would you like to upgrade this card? (y/n): ";
			if(YesOrNo()==true){
				if(player.CheckHonor(card->get_minumumHonor())){
					if(player.SeeMoney()>=card->get_bonus_cost() + TotalCost){
						TotalCost+=card->get_bonus_cost();
						upgrade=true;
					}else cout <<"Upgrade of card  failed not enough money!"<< endl;
				}else cout <<"Upgrade of card failed not enough honor!"<< endl;
			}

			do{
				equiploop=false;
				player.printArmy();
				cout << "Please type the number of the personality you want to equip" << endl;
				cout << "Number of personality: ";
				ReadInt(num);
				num-=1;
				while( (pers=player.GetPersonality(num))==NULL ){
					cout << "Invalid number of personality, please type the correct one: ";
					ReadInt(num);
				}
				if(pers->getHonour() >= card->get_minumumHonor()){
					player.GetMoney(TotalCost);
					card=player.DrawFromHand(CardIndex);
					pers->Equip(card);
					if(upgrade) card->upgrade();
				}else{
					cout << "Not enough honor to equip this personality, would you like to equip the card to another personality? (y/n): ";
					if(YesOrNo()){
						equiploop=true;
					} else equiploop=false;
				}
			}while(equiploop);

		}else cout << "Not enough money!!" << endl;

		cout << "Would you like to Equip any other personalities? (y/n): ";
		equiping=YesOrNo();
	}while(equiping);
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}
