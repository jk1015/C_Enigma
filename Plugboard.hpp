#include "Mapping.hpp"
#include <vector>
#include <map>
using namespace std;

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard: public Mapping
{
  public:
    Plugboard(vector<int>& v);
    void map(int& value);
    void invert(int& value);
  private:
    std::map<int, int> config;
};

#endif
