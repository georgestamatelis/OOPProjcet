#pragma once

#include <iostream>
#include <sstream>
#include <limits>

namespace Read{
	/*static std::string line;
	static std::stringstream ss(line);
	int Int(){
		int ret;
		do{
			ret=0;
			std::cin.clear();
	    	std::getline(std::cin,line);
	    	ss.str("");
	    	ss.clear();
	    	ss<<line;
    	}while( !(ss>>ret) && !(ss.eof()) ); 
    	std::cout << "!!"<< ret << std::endl;
    	return ret;    	
	}*/
	inline void Int(int &ret){
		while(!(std::cin >> ret)){
			//if(input.size()!=ret/10+1) continue;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//std::cout << "!!"<< ret << std::endl;
    	}
    	//std::cout << "!!"<< ret << std::endl;
	}
	inline int Int(){
		int ret;
		Int(ret);
		return ret;
	}
}