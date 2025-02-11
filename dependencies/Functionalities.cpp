#include <limits>
#include <iostream>
#include <string>
#include <sstream>
#include "../player/Player.hpp"

using namespace std;

bool YesOrNo(char a, char b,string message){//This function prints a message and asks for one of two chars as awnser, one coresponds to true and one to false (default arguments: a simple yes or no question. See .hpp)
	char answer;
	cin >> answer;
	while(answer!=a && answer!=b){//While one of the two needed charactes is not typed
		cout << message;//Print the error message
		cin.clear();//Clear the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//And ignore anything else that may stayed there
		cin >> answer;
	}
	cin.clear();//Before exiting the function, clear and ingnore one more
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return (answer==a)? true : false;//Return the acording value for the given input
}

void ReadInt(int &ret){//Function that reads an int and places it to given integer
	while(!(cin >> ret)){//While not only intergers are given as input
		cout << "Please type an interger: ";
		cin.clear();//Clear and ignore the buffer, and read again
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void PressEnter(){
	cout <<"Press enter to continue...";
	ReadString();//This function ends when \n is given as input
	cout << endl;
}

int Honorcompare(const void * p1, const void * p2){//Function to compare honor of two given players, needed for qsort
	return ((Player*)p1)->GetPlayerHonour() - ((Player*)p2)->GetPlayerHonour();
}

#ifdef COLORS
	//If compiler flags allow it, ANSI color codes are used to change the consolone color to the requested one
	void SetToRed(){cout << "\033[" << 31 << "m";}//Using the esc sequence and the code for volor red, in a linux system the color of the latters will change
	void SetToGreen(){cout << "\033[" << 32 << "m";}//32 for green
	void SetToYellow(){cout << "\033[" << 33 << "m";}//33 for yellow
	void SetToBlue(){cout << "\033[" << 34 << "m";}//34 for blue
	void SetToDefault(){cout << "\033[" << 39 << "m";}//And 39 for the default one
	#else
	//Otherwise,colors are not used. And since the body of the functions is empty, when the functions are called nothing happens
	void SetToRed(){}
	void SetToGreen(){}
	void SetToYellow(){}
	void SetToBlue(){}
	void SetToDefault(){}
#endif
