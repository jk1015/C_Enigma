#include "Machine.hpp"
#include <iostream>
#include "Mapping.hpp"
#include <vector>
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
  next->conjugateMap(value);
  next->conjugateRotate();
}
