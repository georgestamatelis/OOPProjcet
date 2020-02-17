#pragma once
#include "Holding.hpp"

class Plain : public Holding{
  public:
    Plain(std::string name) : Holding(name, 2, 2){}
};

class Farmland : public Holding{
  public:
    Farmland(std::string name) : Holding(name, 3, 4) {}
};

class Mine : public Holding{
  public:
    Mine(std::string name) : Holding(name, 5, 3) {}
    int return_type() { return 1; }
};

class GoldMine : public Holding{
  public:
    GoldMine(std::string name) : Holding(name, 7, 5) {}
    int return_type() { return 2; }
};

class CrystalMine : public Holding{
  public:
    CrystalMine(std::string name) : Holding(name, 12, 6) {}
    int return_type() { return 3; }
};

class GiftsandFavour : public Holding{
  public:
    GiftsandFavour(std::string name) : Holding(name, 0, 0) {}
};
