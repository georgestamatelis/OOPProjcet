#include <limits>
#include <iostream>
#include <string>
#include <sstream>
#include "../player/Player.hpp"

using namespace std;

bool YesOrNo(char a, char b,string message){//This function prints a message and asks for two chars as awnser, one coresponds to true and one to false (default arguments a simple ues or no question)
	char answer;
	cin >> answer;
	while(answer!=a && answer!=b){//While one of the two needed charactes is not typed
		cout << message;//Print the error message
		cin.clear();//Clear the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//And ignore anything else that may has stayed there
		cin >> answer;
	}
	cin.clear();//Before exiting the function, clear and ingnore one more
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return (answer==a)? true : false;//Return the acording value for the given input
}

void ReadInt(int &ret){//Function that reads an int and places it to given integer
	while(!(std::cin >> ret)){//While not only intergers are given as input
		std::cin.clear();//Clear and ignore the buffer, and read again
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cin.ignore();
}

int ReadInt(){//Function that reads an int and returns it
	int ret;
	ReadInt(ret);//Read int with above function
	return ret;//return the result
}

string ReadString(){
	string str;
	getline(cin,str);//	Get the whole buffer as string input
	return str;//and return it
}

int Honorcompare(const void * p1, const void * p2){
	return ((Player*)p1)->GetPlayerHonour() - ((Player*)p2)->GetPlayerHonour();
}

#ifdef COLORS
	//If compiler flag allow it, ANSI color codes are used to change the consolone color to the requested one
	void SetToRed(){cout << "\033[" << 31 << "m";}//Using the esc sequence and the code for volor red, in a linux system the color of the latters will change
	void SetToGreen(){cout << "\033[" << 32 << "m";}//32 for green
	void SetToYellow(){cout << "\033[" << 33 << "m";}
	void SetToBlue(){cout << "\033[" << 34 << "m";}//34 for blue
	void SetToDefault(){cout << "\033[" << 39 << "m";}//And 33 for the default one
	#else
	//Otherwise,colors are not used sisnce the body of the functions are empty, so when the functions are called nothing happens
	void SetToRed(){}
	void SetToGreen(){}
	void SetToYellow(){}
	void SetToBlue(){}
	void SetToDefault(){}
#endif
