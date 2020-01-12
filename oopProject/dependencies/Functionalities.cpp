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