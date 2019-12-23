#include <iostream>
#include "Player.h"

using namespace std;

Player::Player():life_points(0){
	hand= new greenCard*[6];
}

Player::~Player(){
	delete[] hand;
}