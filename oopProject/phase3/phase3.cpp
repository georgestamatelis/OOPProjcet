#include <sstream>
#include "phase3.hpp"
phase3:: phase3(Player **pls,int n)
:players(pls),num_of_players(n)
{

}
void phase3:: Attack_Choice(int plindex)
{
  if(plindex>=num_of_players)
      return;
 Player *temp=players[plindex];
 int enemy; string enemyPr;
 cout<<"In which player do you want to attack?"<<endl;
 cin>>enemy;
 if(enemy<=0 || enemy >num_of_players)
  {
    cout<<"Sorry there is no such player"<<endl;
    return ;
  }
 enemy-=1;
 unordered_map<string,blackCard* >enemyProvinces=players[enemy]->GetProvinces();
 cout<<"In which provinces ?"<<endl;
 cin>>enemyPr;
 if(enemyProvinces.find(enemyPr)==enemyProvinces.end())
    {
      cout<<"There is no such province"<<endl;
      return;
    }
 blackCard *underAttack=players[enemy]->GetProvinces()[enemyPr];
 bool input=false;
 vector <string>attackersVector;
 while(!input){
   string attackers,answer;
   cout<<"Which personality do you wanna use?"<<endl;
   cin>>attackers;
   attackersVector.push_back(attackers);
   cout<<"Do you wanna use more personalities?? (y/n)"<<endl;
   cin>>answer;
   if(answer=="n")
     input=true;
 }
 int totaldamage=0;

	vector<Personality *>army=temp->getArmy();
	for(int i=0; i<army.size(); i++){
		if(find(attackersVector.begin(),attackersVector.end(),army[i]->getname())!=attackersVector.end())
     	if(army[i]->canUse())
        	totaldamage+=army[i]->getAttack();
      	//	cout<<army[i]->getname()<<endl;;
	}

 //int personalitydefence=underAttack->getDefenerPoints(); //get defence points from  personalities garding the provine
 int provincedefence=players[enemy]->getInitalDefense();
 bool loss=false;
 //cout<<"totaldamage ="<<totaldamage<<" provincedefence = "<<provincedefence<<" personality="<<personalitydefence<<endl;
 /*if(totaldamage >= personalitydefence+provincedefence)
 {
    //attacker wins
      players[enemy]->looseDefencePersonalities(enemyPr);
      players[enemy]->looseProvince(underAttack->getname());
 }
 else if (totaldamage >personalitydefence && totaldamage< personalitydefence+provincedefence)
 { //lose all attackers and all defenders
   loss=true;
   players[enemy]->looseDefencePersonalities(enemyPr);
   int totalLoss=totaldamage-personalitydefence;//+provincedefence;
   while(totalLoss>=0){
     for(int i=0;i<attackersVector.size();i++)
     {
        totalLoss-=temp->getPersonalityDamage(attackersVector[i]);
        temp->loosePersonalty(attackersVector[i]);
     }
     }
}
 else if(totaldamage ==personalitydefence)
 {
   //lose
   loss=true;
   players[enemy]->looseDefencePersonalities(enemyPr);
   //+loose all attackeras
   for (int i=0;i<attackersVector.size();i++){
     temp->loosePersonalty(attackersVector[i]);
   }
 }
 else if(totaldamage < personalitydefence){
   loss=true;
   for (int i=0;i<attackersVector.size();i++){
     temp->loosePersonalty(attackersVector[i]);
   }
   int totalLoss=personalitydefence-totaldamage;
   //underAttack->loosePersonalties(totalLoss);
 }
 if(loss){
   temp->looseHonor();
 }*/
}
void phase3:: defence_Choise(int plindex){
/*  if(plindex>=num_of_players)
      return;
  Player *temp=players[plindex];
  string prDef;
  unordered_map<string,blackCard*> provinces=temp->GetProvinces();
  cout<<"Which province do you wanna defend?"<<endl;
  cin>>prDef;
  if(provinces.find(prDef)==provinces.end()){
    cout<<"Sorry there is no such province"<<endl;
    return;
  }
  Holding * underAttack=provinces[prDef];
  bool endinput=false;
  vector<string>defencePers;
  while(!endinput){
    string defendant,answer;
    cout<<"Which personalities will defend it??"<<endl;
    cin>>defendant;
    cout<<"Do you wanna use more personalities?? (y/n)"<<endl;
    cin>>answer;
    defencePers.push_back(defendant);
    if(answer=="n" || answer=="N" || answer=="No")
       break;
  }
  //done with input now time to add defendants to province
  /*list<Personality*>army=temp->getArmy();
  std::list<Personality *>::const_iterator it;
  it = army.begin();
  while (it != army.end()){
    if(find(defencePers.begin(),defencePers.end(),(*it)->getname())!=defencePers.end())
        underAttack->addDefandant(*it);
       ++it;
  }*/
  /*Personality **army=temp->getArmy();
  for(int i=0; i<4; i++){
  	if(find(defencePers.begin(),defencePers.end(),army[i]->getname())!=defencePers.end())
        underAttack->addDefandant(army[i]);
  }*/
}
void phase3:: play(){
  cout<<"PHASE 3  || BATTLE PHASE"<<endl;
  cin.clear();
  string line;int choice=0; //stringstream ss;
  for(int i=0;i<num_of_players;i++){
    cout<<"Player "<<i+1<<"turn:"<<endl;
    cout<<"Type 1 for attack options ,2 for defence options, 3 to end your turn: "<<endl;
    cin>>line;
    stringstream ss(line);
    ss>>choice;
    while(choice<1 || choice>3)
    {
      cout<<"Type a number between 1 and 3 ,Try again"<<endl;
      cin.clear();
      ss.str("");
      ss.clear();
      getline(cin,line);
      ss<<line;
      ss>>choice;
    }

    switch (choice){
      case 1:
       Attack_Choice(i);
       break;
      case 2:
       defence_Choise(i);
       break;
      case 3:
        break;
      default:
        cout<<"Something is wrong with my code"<<endl;
        break;
    }

  }
}
phase3:: ~phase3(){
  cout<<"End of phase3"<<endl;
}
