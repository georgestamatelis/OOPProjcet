#pragma once
#include "follower.hpp"

class Footsoldier : public follower{
  public:
    Footsoldier(std::string name)
      : follower(name, 0, 2, 0, 1, 1, 2) {}
};

class Archer : public follower{
  public:
    Archer(std::string name)
        : follower(name, 0, 0, 2, 1, 1, 2) {}
};

class Sieger : public follower{
  public:
    Sieger(std::string name)
        : follower(name, 5, 3, 3, 2, 2, 3) {}
};
class Cavalry : public follower{
  public:
    Cavalry(std::string name)
        : follower(name, 3, 4, 2, 3, 3, 4) {}
};

class Atakebune : public follower{
  public:
    Atakebune(std::string name)
        : follower(name, 3, 2, 4, 3, 3, 4) {}
};

class Bushido : public follower{
  public:
    Bushido(std::string name)
        : follower(name, 8, 8, 8, 6, 3, 8) {}
};
