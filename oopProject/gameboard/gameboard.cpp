#include "gameboard.h"
#include <sstream>
#include "../dependencies/Read.hpp"
#include <iostream>

gameboard::gameboard()
{
  rounds=0;
  string line;
  cout<<"Initializing GameBoard"<<endl;
  cout<<"How many players ? :";
 num_of_players=Read::Int();
 while(num_of_players<=1 || num_of_players>8)
 {
   cout<<"Sorry the rules say there must be 2-8 players  Try again"<<endl;
   num_of_players=Read::Int();
   //cout<<num_of_players<<" "<<line<<endl;
 }
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
  cout<<"END OF ROUND: "<<rounds-1<<endl;
  int sum=0;
  cout<<"Player:\t HP:\t Money:\n";
  for(int i=0; i<num_of_players;i++){
    if(players[i]->isAlive())
      {
        sum++;
        cout<<i+1<<"\t "<<players[i]->getHP()<<"\t"<<players[i]->getMoney()<<endl;

      }

  }
  cout<<"Total alive Players: "<<sum<<"  Total dead players : "<<num_of_players-sum<<endl;
  cout<<"START OF ROUND: "<<rounds<<endl;

}
void gameboard:: gamePlay()
{
  cout<<"GamePlay Begins"<<endl;
  do{   
    P1->play();
    P2->play();
    P3->play();
    P4->play();
    P5->play();
    printGameStatistics();
    for(int i=0;i<num_of_players;i++){
      players[i]->add_money();
    }
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
