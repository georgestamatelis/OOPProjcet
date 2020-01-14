#include <limits>
#include <iostream>
#include <string>
#include <sstream>
#include "../player/Player.hpp"

using namespace std;

bool YesOrNo(char a, char b,string message){
	char answer;
	cin >> answer;
	while(answer!=a && answer!=b){
		cout << message << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> answer;
	}
	return (answer==a)? true : false;
}

int Honorcompare(const void * p1, const void * p2){
	return ((Player*)p1)->GetPlayerHonour() - ((Player*)p2)->GetPlayerHonour();
}

void ReadInt(int &ret){
		while(!(std::cin >> ret)){
			//if(input.size()!=ret/10+1) continue;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//std::cout << "!!"<< ret << std::endl;
    	}
    	//std::cout << "!!"<< ret << std::endl;
	}

int ReadInt(){
		int ret;
		ReadInt(ret);
		return ret;
}
string ReadString(){
	char array[50];
	cin.getline(array,50);
	string answer(array);
	return answer;
}
