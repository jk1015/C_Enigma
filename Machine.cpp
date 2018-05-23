#include "Machine.hpp"
#include "Mapping.hpp"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

Machine::Machine(vector<Mapping*> maps)
{
  Mapping* current_map = this;
  for (unsigned i = 0; i < maps.size(); i++)
  {
    maps[i]->setPrev(current_map);
    current_map = maps[i];
  }
}


void Machine::map(int& value)
{
  next->map(value);
  next->rotate();
}
