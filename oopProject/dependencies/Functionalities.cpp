#include <limits>
#include <iostream>
#include <sstream>

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

int Honor_compare(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
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

#ifdef COLORS
	//If compiler flag allow it, ANSI color codes are used to change the consolone color to the requested one
	void SetToRed(){std::cout << "\033[" << 31 << "m";}//Using the esc sequence and the code for volor red, in a linux system the color of the latters will change
	void SetToGreen(){std::cout << "\033[" << 32 << "m";}//32 for green
	void SetToBlue(){std::cout << "\033[" << 34 << "m";}//34 for blue
	void SetToDefault(){std::cout << "\033[" << 39 << "m";}//And 33 for the default one
	#else
	//Otherwise,colors are not used sisnce the body of the functions are empty, so when the functions are called nothing happens
	void SetToRed(){}
	void SetToGreen(){}
	void SetToBlue(){}
	void SetToDefault(){}
#endif