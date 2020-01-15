#include <sstream>
#include "../dependencies/Functionalities.hpp"
#include "phase3.hpp"

phase3:: phase3(Player **pls,int n)
:players(pls),num_of_players(n)
{

}
void phase3:: Attack_Choice(int plindex)
{
  cout<<"Which Player do you want to attack  ?:";
  int enemyIndex=ReadInt();
  enemyIndex-=1;
  while(enemyIndex <0 || enemyIndex ==plindex){
    cout<<"Wrong input : ";
    enemyIndex=ReadInt();
    enemyIndex-=1;
  }
  cout<<"Enemy Players Provinces are :"<<endl;
  players[enemyIndex]->printProvinces();
  cout<<"Which one do you want to attack : ";
  string answer;
  cin>>answer;
  while(answer!="a" && answer !="b" && answer!="c" && answer!="d" ){
    cout<<"Sorry no such province.Try again :";
    cin>>answer;
  }
 blackCard * underAttack=players[enemyIndex]->GetProvinces()[answer];
 cout<<"Your available army is :"<<endl;
 players[plindex]->printArmy();
 cout<<"Which personalitiew do you want to use?"<<endl;
 bool input=false;
 vector <string>attackersVector;
 while(!input)
 {
   string attackers,answer;
   cout<<"Which personality do you wanna use?"<<endl;
   cin>>attackers;
   attackersVector.push_back(attackers);
   cout<<"Do you wanna use more personalities?? (y/n)"<<endl;
   cin>>answer;
   if(answer=="n" )
     input=true;
 }
 //time for attack
 int totaldamage=0;
 vector <Personality *>army=players[plindex]->getArmy();
 for(int i=0;i<army.size();i++)
 {
   if(find(attackersVector.begin(),attackersVector.end(),army[i]->getname())!=attackersVector.end())
      {totaldamage+=army[i]->getAttack();
    /*  cout<<"Fook";*/}
 }
 bool loss=false;
 int provinceDefence=players[enemyIndex]->getInitalDefense();
 int personalityDefence=underAttack->getDefence();
 cout<<"Total Damage "<<totaldamage<<"prD "<<provinceDefence<<"personD "<<personalityDefence<<endl;
 if(totaldamage >= personalityDefence+provinceDefence)
 {
    //attacker wins
      players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence+provinceDefence);
      players[enemyIndex]->looseProvince(answer);
 }
 else if (totaldamage >personalityDefence && totaldamage< personalityDefence+provinceDefence)
 { //lose all attackers and all defenders
   loss=true;
   players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence+provinceDefence);
   int totalLoss=totaldamage-personalityDefence;//+provincedefence;
   while(totalLoss>=0){
     for(int i=0;i<attackersVector.size();i++)
     {
        totalLoss-=players[plindex]->getPersonalityDamage(attackersVector[i]);
        players[plindex]->loosePersonalty(attackersVector[i]);
     }
     }
}
 else if(totaldamage ==personalityDefence)
 {
   //lose
   loss=true;
   players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence);
   //+loose all attackeras
   for (int i=0;i<attackersVector.size();i++){
     players[plindex]->loosePersonalty(attackersVector[i]);
   }
 }
 else if(totaldamage < personalityDefence){
   loss=true;
   for (int i=0;i<attackersVector.size();i++){
     players[plindex]->loosePersonalty(attackersVector[i]);
   }
   int totalLoss=personalityDefence-totaldamage;
   underAttack->loosePersonalties(totalLoss);
 }
 if(loss){
   players[plindex]->looseHonor();
 }
}
void phase3:: defence_Choise(int plindex)
{
  if(plindex>=num_of_players)
      return;
  Player *temp=players[plindex];
  string prDef;
  unordered_map<string,blackCard*> provinces=temp->GetProvinces();
  cout<<"Your  Province are :"<<endl;
  players[plindex]->printProvinces();
  cout<<"Which province do you wanna defend? : ";//<<endl;
  cin>>prDef;
  while(provinces.find(prDef)==provinces.end()){
    cout<<"Sorry there is no such province,try again:"<<endl;
    cin>>prDef;
  //  return;
  }
  Holding * underAttack=(Holding *)provinces[prDef];
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
  vector <Personality*>army=temp->getArmy();
  for(int i=0;i<army.size();i++){
     if(find(defencePers.begin(),defencePers.end(),army[i]->getname())!=defencePers.end())
        underAttack->addDefandant(army[i]);
 }

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
