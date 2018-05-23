#include "Mapping.hpp"
#include <vector>
#include <map>
using namespace std;

#ifndef MACHINE_H
#define MACHINE_H

class Machine: public Mapping
{
  public:
    Machine(vector<Mapping*> maps);
    void map(int& value);
    void invert(int& value) {};
    void rotate() {};
};

#endif
