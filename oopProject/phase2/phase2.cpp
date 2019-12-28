#include <limits>
#include <iostream>
#include "phase2.h"
#include "../dependencies/Read.hpp"

using namespace std;

bool phase2::YesOrNo(){
	char answer;
	cin >> answer;
	while(answer!='y' && answer!='n'){
		cout << "Please type 'y' for yes and 'n' for no:" << endl;
		cin >> answer;
	}
	return (answer=='y')? true : false;
}

phase2::phase2(vector <Player*> &giver_players):players(&giver_players){
	cout<<"Start of phase 2"<<endl;
}

void phase2::play(){
	int i=1;
	for(vector <Player*>::iterator CurentPlayer = players->begin(); CurentPlayer != players->end(); CurentPlayer++){
		cout << "Player number " << i << "\n\nWould you like to equip your army with cards from your army? (y/n)" << endl;
		if(YesOrNo()==true)	equipPhase(**CurentPlayer);
		cout << "Would you like to Buy A Personality? (y/n)" << endl;
		if(YesOrNo()==true)	BuyPersonality(**CurentPlayer);
		i++;
	}
}

void phase2::equipPhase(Player &player){
	if(player.HasArmy()==false) {cout << "Sorry, you dont have an army to equip." << endl; return;}
	string name;
	int num;
	cout << "Your hand cards:" << endl;
	player.printHand();
	cout << "Your army: " << endl;
	player.printArmy();
	cout << "Please type the name of the personality and the number of the item you want to equip him with" << endl;
	cout << "Name of personality: "; 
	cin >> name;
	while(player.CheckName(name)==false){
		cout << "The name you gave does not exist, please retype the name of the personality you want to equip" << endl;
		cin >> name;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Number of card in hand: ";
	Read::Int(num);
	while(player.CheckInHand(num)==false){
		cout << "The number of the card you typed does not exist please retype the number of the card you want from hand" << endl;
		Read::Int(num);
	}
	player.EquipPersonality(name,num);
	cout << "Would you like to Equip any other BuyPersonalities? (y/n): ";
	if(YesOrNo()==true){
		equipPhase(player);
	}
}

void phase2::BuyPersonality(Player &player){
	Attacker *att;	Defender *defend;	Champion *champ;	Chancellor *chancel;	Shogun *shog;
	int input;
	cout << "\nAvailable personalities to buy:\n 	1. Attacker price::"<<5<<"| 2. Defender price: "<<5<<" | 3. Champion price: "<< 30 <<" | 4. Chancellor price: "<< 15<<" | 5. Shogun price: " << 15<< endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	Read::Int(input);
	while(input<0 || input>5){
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
	    		} else UpgradePersonality(player,att);
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
	    		} else UpgradePersonality(player,defend);
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
	    		} else UpgradePersonality(player,champ);
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
	    		} else UpgradePersonality(player,chancel);
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
	    		} else UpgradePersonality(player,shog);
	    	}else{
				cout << "Not enough money or/and honor!" << endl;
				delete shog;
			}
			break;
	}
	cout << "Would you like to buy any other personalities? (y/n):" << endl;
	if(YesOrNo()==true) BuyPersonality(player);
}

void phase2::UpgradePersonality(Player &player,Personality *personality){
	char answer;
	cout << "Would you like to upgrade this personality? [cost 69$] (y/n)" << endl;
	cin >> answer;
	while(answer!='y' && answer!='n'){
		cout << "Please type 'y' for yes and 'n' for no:" << endl;
		cin >> answer;
	}
	if(answer=='n') return;
	//upgrade card here !!!! do not forget!!!!
	if(player.CheckHonor(personality->getHonour())){
		if(player.GetMoney(/*personality->getHonour()????*/69)==true){
			/*personality->upgradeAtack or/and defense idk()*/
		}
	}
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}
