#pragma once
#include "item.hpp"

class Katana:public Item
{
public:
  Katana(string name)
  :Item(name,0,2,0,1,1,2,3)
  {}
};
class Spear:public Item
{
public:
  Spear(string name)
  :Item(name,0,0,2,1,1,2,3)
  {}
};
class Bow:public Item
{
public:
 Bow(string name)
 :Item(name,2,2,2,2,3,4,5)
 {}
};
class Ninjato:public Item
{
public:
  Ninjato(string name)
  :Item(name,4,3,3,3,2,2,4)
  {}
};
class Wakizashi:public Item
{
public:
 Wakizashi(string name)
 :Item(name,8,5,5,3,3,3,8)
 {}
};
