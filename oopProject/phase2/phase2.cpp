#include "phase2.h"

using namespace std;

phase2::phase2(vector <Player*> &giver_players):players(&giver_players){
	cout<<"Start of phase 2"<<endl;
}

void phase2::play(){
	int i=1;
	for(vector <Player*>::iterator CurentPlayer = players->begin(); CurentPlayer != players->end(); CurentPlayer++){
		cout << "Player number " << i << "\n\nHand cards:" << endl;
	 	(*CurentPlayer)->printHand();
		cout << "Army: " << endl;
		(*CurentPlayer)->printArmy();
		BuyPersonality(**CurentPlayer);
		i++;
	}
}

void phase2::BuyPersonality(Player &player){
	Attacker *att;	Defender *defend;	Champion *champ;	Chancellor *chancel;	Shogun *shog;
	int input;
	char answer;
	cout << "\nAvailable personalities to buy:\n 	1. Attacker price::"<<5<<"| 2. Defender price: "<<5<<" | 3. Champion price: "<< 30 <<" | 4. Chancellor price: "<< 15<<" | 5. Shogun price: " << 15<< endl;
	cout << "If you would like to buy any of these type its number (0 if you wouldn't like to buy any)" << endl;
	cin >> input;
	while(input !=0 & input!=1 && input!=2 && input !=3 && input !=4 && input !=5){
		cout << "Wrong number!, please enter a number in 0-5" << endl;
		cin >> input;
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
	    		} else UpgradePersonality(att);
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
	    		} else UpgradePersonality(defend);
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
	    		} else UpgradePersonality(champ);
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
	    		} else UpgradePersonality(chancel);
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
	    		} else UpgradePersonality(shog);
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
	if(answer=='y'){
		BuyPersonality(player);
	}
}

void phase2::UpgradePersonality(Personality *personality){
	char answer;
	cout << "Would you like to upgrade this personality? (y/n)" << endl;
	cin >> answer;
	while(answer!='y' && answer!='n'){
		cout << "Please type 'y' for yes and 'n' for no:" << endl;
		cin >> answer;
	}
	if(answer=='n') return;
	//upgrade card here !!!! do not forget!!!!
}

phase2::~phase2(){
  	cout<<"End of phase 2"<<endl;
}
