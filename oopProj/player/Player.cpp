#include <iostream>
#include "Player.h"

using namespace std;

Player::Player():life_points(4),money(0),numberOfProvinces(4),Honour("Perdikopanis"){
	hand= new greenCard*[6];
}

Player::~Player(){
	delete[] hand;
}