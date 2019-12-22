#pragma once
#include <string>
#include <iostream>
using namespace std;
class Card{
private:
string name;
int cost;
bool isTapped;
public:
  Card(string n,int c,bool is=false)
  :name(n),cost(c),isTapped(is){}
};
