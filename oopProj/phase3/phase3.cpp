
#include "phase3.h"
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
 cout<<"In which provinces ?"<<endl;
 cin>>enemyPr;
}
void phase3:: defence_Choise(int plindex){
  if(plindex>=num_of_players)
      return;
  Player *temp=players[plindex];
  string prDef;
  unordered_map<string,Holding*> provinces=temp->GetProvinces();
  cout<<"Which province do you wanna defend?"<<endl;
  cin>>prDef;
  Holding * underAttack=provinces[prDef];
}
void phase3:: play(){
  for(int i=0;i<num_of_players;i++){
    cout<<"Player "<<i+1<<"turn:"<<endl;
    cout<<"Type 1 for attack options ,2 for defence options, 3 to end your turn"<<endl;
    int choice;
    cin>>choice;
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
       break;
    }

  }
}
phase3:: ~phase3(){
  cout<<"End of phase3"<<endl;
}
