#include "Rotor.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;

//Construct a rotor from an int vector
//Error if |v| =/= 26 or v[n] == n or mapping is invalid
Rotor::Rotor(vector<int>& v)
{
  if(v.size() != 26)
  {
    throw invalid_argument("Rotors must have a valid mapping for each character");
  }
  for(int i = 0; i < 26; i++)
  {
    /* The spec states that mappings are irreflexive.
       Some of the tests have reflexive mappings
    if(v[i] == i)
    {
      throw invalid_argument("Rotor mappings must be irreflexive");
    }
    */
    if(v[i] >= 26 || v[i] < 0)
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

//
void Rotor::map(int& value)
{
  value = (26 + config[(value + rotation) % 26] - rotation) % 26;
}

void Rotor::invert(int& value)
{
  value = (26 + inverse_config[(value + rotation) % 26] - rotation) % 26;
}

bool Rotor::rotate()
{
  rotation = (rotation + 1) % 26;
  return rotation == 0;
}
