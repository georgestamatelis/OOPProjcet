#pragma once
#include "../dependencies/Functionalities.hpp"
#include "blackcard.hpp"
#include "personality.hpp"
#include <vector>

class Holding : public blackCard{
  private:
    int harvestValue; //returns per round
    bool upperHolding, subHolding;
    bool full_chain;

  public:
    Holding(std::string name, int c, bool b1, bool b2, int hv, bool upH = false, bool subH = false)
        : blackCard(name, c, b1, b1), harvestValue(hv), upperHolding(upH), subHolding(subH){}

    Holding(std::string name, int cost, int Harvest)
        : blackCard(name, cost, false, false), harvestValue(Harvest), upperHolding(false), subHolding(false){}

    void print(){
      SetToRed();
	  std::cout << "┌─────────────────────────┐\n"
                << "│Holding : " << this->getname() << "\n"
                << "│harvestValue: " << this->harvestValue << "\n"
				<< "└─────────────────────────┘" << std::endl;
      SetToDefault();
    }

    int get_harvest_value(){
      int result=harvestValue;
        switch (return_type()) //no need for break statements cause tha function terminates anyways
        {

          case 0:
            return 0;
          case 1:
            if(upperHolding)
              result+=2;
            return result;
          case 2:
             if(upperHolding  && ! subHolding){
              result+=4;
             }
             else if(!upperHolding && subHolding){
               result+=5;
             }
             else if( (upperHolding && subHolding) || full_chain){
                result*=2;
             }
             return result;
          case 3:
            if(subHolding && !full_chain)
              return 2*result;
            else if(full_chain)
              return 3*result;
            return result;
          default:
            return 0;
        }
    }
    virtual int return_type()
    { return 0;
      //return type is
      // 0 for everything else
      //1 for Mine
      //2 for gold Mine
      //3 for crystal mine
    }
    bool has_upperholding() { return upperHolding; }
    bool has_subholding() { return subHolding; }
    void setU() { upperHolding = true; }
    void setS() { subHolding = true; }
    void setFC() { full_chain = true; }
};
