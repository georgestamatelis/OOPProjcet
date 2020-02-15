#pragma once
#include "personality.hpp"
class Attacker : public Personality{
  public:
    Attacker(string name) : Personality(name, 5, false, false, 3, 2, 1, false){}
};

class Defender : public Personality{
  public:
    Defender(string name) : Personality(name, 5, false, false, 2, 3, 2, false){}
};

class Shogun : public Personality{
  public:
    Shogun(string name) : Personality(name, 15, false, false, 10, 5, 8, false){}
};

class Chancellor : public Personality{
  public:
    Chancellor(string name) : Personality(name, 15, false, false, 5, 10, 8, false){}
};

class Champion : public Personality{
  public:
    Champion(string name)
        : Personality(name, 30, false, false, 20, 20, 12, false){}
};
