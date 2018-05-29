#include "Rotor.hpp"
#include "Util.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;

//Construct a rotor from an int vector
//Error if |v| =/= alphabet_size or v[n] == n or mapping is invalid
Rotor::Rotor(vector<int>& v)
{
  if((int) v.size() != alphabet_size)
  {
    throw invalid_argument("Rotors must have a valid mapping for each character");
  }
  for(int i = 0; i < alphabet_size; i++)
  {
    /* The spec states that mappings are irreflexive.
       Some of the tests have reflexive mappings
    if(v[i] == i)
    {
      throw invalid_argument("Rotor mappings must be irreflexive");
    }
    */
    if(v[i] >= alphabet_size || v[i] < 0)
    {
      throw invalid_argument("Invalid value in rotor mapping, must have f:{0,..,25} -> {0,..,25}");
    }
    if(inverse_config.count(v[i]))
    {
      throw invalid_argument("Value mapped to multiple times by Rotor. Rotor mappings must be bijective");
    }
    config[i] = v[i];
    inverse_config[v[i]] = i;
  }

  rotation = 0;
}

void Rotor::map(int& value)
{
  behaviour(value, config);
}

void Rotor::invert(int& value)
{
  behaviour(value, inverse_config);
}

void Rotor::behaviour(int& value, std::map<int,int> map)
{
  value = (alphabet_size + map[(value + rotation) % alphabet_size] - rotation) % alphabet_size;
}

bool Rotor::rotate()
{
  rotation = (rotation + 1) % alphabet_size;
  return rotation == 0;
}
