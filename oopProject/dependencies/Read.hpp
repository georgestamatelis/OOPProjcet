
#pragma once

#include <iostream>
#include <sstream>
#include <limits>

namespace Read{
	inline void Int(int &ret){
		while(!(std::cin >> ret)){
			//if(input.size()!=ret/10+1) continue;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "!!"<< ret << std::endl;
    	}
    	std::cout << "!!"<< ret << std::endl;
	}
	inline int Int(){
		int ret;
		Int(ret);
		return ret;
	}
}
