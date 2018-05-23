#include "Mapping.hpp"
#include <vector>
#include <map>
using namespace std;

#ifndef ROTOR_H
#define ROTOR_H

class Rotor: public Mapping
{
  public:
    Rotor (vector<int>& v);
    void map(int& value);
    void invert(int& value);
    void rotate();
  protected:
    void resetNext();
    void resetPrev();
  private:
    std::map<int, int> config;
    std::map<int, int> inverse_config;
    int rotation;
    Mapping nullmap;
};

#endif