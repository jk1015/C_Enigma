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
  Mapping nullmap;
  this->setNext(&nullmap);
  this->setPrev(&nullmap);

  if(v.size() != 26)
  {
    cerr <<
    "Rotors must have a mapping for each character"
    << endl;
    exit(1);
  }
  for(int i = 0; i < 26; i++)
  {
    if(v[i] == i)
    {
      cerr <<
      "Rotor mappings must be irreflexive"
      << endl;
      exit(1);
    }
    if(v[i] >= 26 || v[i] < 0)
    {
      cerr <<
      "Invalid value in rotor mapping, must have f:{0,..,25} -> {0,..,25}"
      << endl;
      exit(1);
    }
    config[i] = v[i];
    inverse_config[v[i]] = i;
  }

  rotation = 0;
}

//
void Rotor::map(int& value)
{
  value = config[(value + rotation) % 26];
  next->map(value);
}

void Rotor::invert(int& value)
{
  value = (inverse_config[value] - rotation) % 26;
  prev->invert(value);
}

void Rotor::rotate()
{
  rotation = (rotation + 1) % 26;
  if(rotation == 0)
  {
    next->rotate();
  }
}

void Rotor::resetNext()
{
  this->setNext(&nullmap);
}

void Rotor::resetPrev()
{
  this->setPrev(&nullmap);
}
