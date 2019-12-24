#include "gameboard.h"
#include <iostream>

gameboard::gameboard(){
cout<<"Initializing GameBoard"<<endl;
cout<<"How many players ? :";
cin>>num_of_players;

players =new Player *[num_of_players];
for(int i=0;i<num_of_players;i++)
  players[i]=new Player;
P1=new phase1(players,num_of_players);
P3=new phase3(players,num_of_players);
gamePlay();
}
bool isWinner(){
  return true;
}
void gameboard:: printGameStatistics()
{

}
void gameboard:: gamePlay()
{
  do{
    cout<<"GamePlay Begins"<<endl;
    P1->play();
    P3->play();
  }while(!isWinner());

}
gameboard:: ~gameboard(){
  cout<<"Destroying GameBoard game over"<<endl;
}
