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
 while(enemyIndex <0 || enemyIndex ==plindex || enemyIndex >=num_of_players){
    cout<<"Wrong input : ";
    enemyIndex=ReadInt();
    enemyIndex-=1;
  }
  cout<<"Enemy Players Provinces are :"<<endl;
  players[enemyIndex]->printProvinces();
  cout<<"Which one do you want to attack : ";
  string answer;
  answer=ReadString();
  while(answer!="a" && answer !="b" && answer!="c" && answer!="d" ){
    cout<<"Sorry no such province.Try again :";
    cin>>answer;
  }
 blackCard * underAttack=players[enemyIndex]->GetProvinces()[answer];
 if(underAttack->isKilled())
  return;
 cout<<"Your available army is :"<<endl;
 players[plindex]->printArmy();
 //cout<<"Which personalitiew do you want to use?"<<endl;
 bool input=false;
 vector <int>attackersVector;
 vector <Personality *>army=players[plindex]->getArmy();
 while(!input)
 {
   int attackers;
   string answer;
   cout<<"Which personality do you wanna use?"<<endl;
   attackers=ReadInt();
   if(attackers>=1 && attackers<=army.size())
    attackersVector.push_back(attackers-1);
   cout<<"Do you wanna use more personalities?? (y/n)"<<endl;
   cin>>answer;
   if(answer=="n" )
     input=true;
  /*right code for lines 47-49
   input=!YesOrNo();
  */
 }
 //time for attack
 int totaldamage=0;
 for(int i=0;i<attackersVector.size();i++)
 {
   if(army[attackersVector[i]]->canUse())
    totaldamage+=army[attackersVector[i]]->getAttack();
 }

 bool loss=false;
 int provinceDefence=players[enemyIndex]->getInitalDefense();
 int personalityDefence=underAttack->getDefence();
 cout<<"Total Damage "<<totaldamage<<"prD "<<provinceDefence<<"personD "<<personalityDefence<<endl;
 if(totaldamage >= (personalityDefence+provinceDefence))
 {
    //attacker wins
    cout<<"ATTACKER WINS THE BATTLE"<<endl;
      players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence+provinceDefence);
      players[enemyIndex]->looseProvince(answer);
      return;
 }
 else if (totaldamage >=personalityDefence && totaldamage< personalityDefence+provinceDefence)
 { //lose some attackers and all defenders
   loss=true;
   players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence+provinceDefence);
   int totalLoss=totaldamage-personalityDefence;//+provincedefence;
    for(int i=0;i<attackersVector.size();i++)
     {
        totalLoss-=army[attackersVector[i]]->getAttack();
        players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());
        if(totalLoss <=0)
          break;
     }

}
 else if(totaldamage ==personalityDefence)
 {
   //lose
   loss=true;
   players[enemyIndex]->looseDefencePersonalities(answer,personalityDefence);//loose all defenders
   //+loose all attackeras
   for (int i=0;i<attackersVector.size();i++){
     players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());

   }
 }
 else if(totaldamage < personalityDefence){
   loss=true;
   for (int i=0;i<attackersVector.size();i++){
     players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());
   }

   int totalLoss=personalityDefence-totaldamage;
   underAttack->loosePersonalties(totalLoss);
 }
 if(loss){
       players[plindex]->looseHonor();
       for(int i=0;i<attackersVector.size();i++){
         if(!army[attackersVector[i]]->isKilled()){
          army[attackersVector[i]]->tap();
          army[attackersVector[i]]->looseHonor();
          army[attackersVector[i]]->hurtItems();
       }}
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
  cout<<"available army is: " <<endl;
  players[plindex]->printArmy();
  blackCard * underAttack=(blackCard *)provinces[prDef];
  bool endinput=false;
  vector<int >defencePers;
  vector <Personality*> army=temp->getArmy();
  while(!endinput){
    int defendant;
//    string defendant,answer;
    cout<<"Which personalities will defend it??"<<endl;
    defendant=ReadInt();
    if(defendant >=1 && defendant<=army.size())
    defencePers.push_back(defendant-1);
    cout<<"Do you wanna use more personalities?? (y/n)"<<endl;
    if(!YesOrNo())
      break;
  }
  //done with input now time to add defendants to province
  for(int i=0;i<defencePers.size();i++)
    if(army[defencePers[i]]->canUse() )
      underAttack->addDefandant(army[i]);


}
void phase3:: play(){
  SetToYellow();
  cout<<"PHASE 3  [Battle phase]"<<endl;
  SetToDefault();
  cin.clear();
  string line;int choice=0; //stringstream ss;
  //qsort(players,num_of_players,sizeof(Player*),Honorcompare);
  for(int i=0;i<num_of_players;i++){
    cout<<"Player "<<players[i]->GetName()<<" turn:"<<endl;
    cout<<"Type 1 for attack options ,2 for defence options, 3 to end your turn: "<<endl;
    choice=ReadInt();
    while(choice<1 || choice>3)
    {
      cout<<"Type a number between 1 and 3 ,Try again"<<endl;
      choice=ReadInt();
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
