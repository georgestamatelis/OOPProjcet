#include "gameboard.h"
#include <iostream>

gameboard::gameboard()
{
  rounds=0;
  cout<<"Initializing GameBoard"<<endl;
  cout<<"How many players ? :";
  cin>>num_of_players;
  players =new Player *[num_of_players];
  for(int i=0;i<num_of_players;i++)
    players[i]=new Player;
  P1=new phase1(players,num_of_players);
  P3=new phase3(players,num_of_players);
  std::vector<Player*> v;
  for(int i=0;i<num_of_players;i++)
    v.push_back(players[i]);
    cout<<v.size();
  P2=new phase2(v);
  P4=new phase4(players,num_of_players);
  P5=new phase5(players,num_of_players);

  gamePlay();
}
bool gameboard::isWinner(){
  int sum=0;
  for(int i=0;i<num_of_players;i++){
    if(players[i]->isAlive())
      sum++;
  }
  if(sum==1)
    return true;
  return false;
}
void gameboard:: printGameStatistics()
{
  rounds++;
  cout<<"Round: "<<rounds<<endl;
  int sum=0;
  for(int i=0;i<num_of_players;i++){
    if(players[i]->isAlive())
      sum++;
  }
  cout<<"Total alive Players: "<<sum<<"  Total dead players : "<<num_of_players-sum<<endl;
}
void gameboard:: gamePlay()
{
  do{
    cout<<"GamePlay Begins"<<endl;
    P1->play();
    P2->play();
    P3->play();
    P4->play();
    P5->play();
    printGameStatistics();
  }while(!isWinner());

}
gameboard:: ~gameboard(){
  cout<<"Destroying GameBoard game over"<<endl;
  delete P1;
  delete P2;
  delete P3;
  delete P4;
  for (int i=0;i<num_of_players;i++)
    delete players[i];
  delete players;
}
