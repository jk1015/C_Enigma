#include "Mapping.hpp"
#include <vector>
#include <map>

#ifndef ROTOR_H
#define ROTOR_H

class Rotor: public Mapping
{
  public:
    Rotor (std::vector<int>& v);
    void map(int& value);
    void invert(int& value);
    bool rotate();
  private:
    void behaviour(int& value, std::map<int, int> map);
    std::map<int, int> config;
    std::map<int, int> inverse_config;
    int rotation;
};

#endif
