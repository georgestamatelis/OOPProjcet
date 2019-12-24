#include "gameboard.h"
#include <iostream>

gameboard::gameboard(){
cout<<"Initializing GameBoard"<<endl;
num_of_players=P1.getNumOfPlayers();
players=P1.get_Players();
gamePlay();
}
void gameboard:: printGameStatistics()
{

}
void gameboard:: gamePlay()
{
 cout<<"GamePlay Begins"<<endl;
}
gameboard:: ~gameboard(){
  cout<<"Destroying GameBoard game over"<<endl;
}
