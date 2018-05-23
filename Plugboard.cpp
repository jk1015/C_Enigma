#include "Plugboard.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;

//Construct a Plugboard from an int vector
//Error if |v| is not even or mapping is invalid
Plugboard::Plugboard(vector<int>& v)
{
  this->setNext(&nullmap);
  this->setPrev(&nullmap);

  for (int i = 0; i < 26; i++)
  {
    config[i] = i;
  }

  if(v.size() % 2 == 1)
  {
    cerr <<
    "Plugboard mappings must contain an even number of values"
    << endl;
    exit(1);
  }
  for (unsigned i = 0; i < v.size(); i += 2)
  {
    if(v[i] >= 26 || v[i] < 0 || v[i + 1] >= 26 || v[i + 1] < 0)
    {
      cerr <<
      "Invalid value in plugboard mapping, must have p:{0,..,25} -> {0,..,25}"
      << endl;
      exit(1);
    }
    config[v[i]] = v[i + 1];
    config[v[i + 1]] = v[i];
  }

}

void Plugboard::map(int& value)
{
  value = config[value];
  next->map(value);
}

void Plugboard::invert(int& value)
{
  value = config[value];
  prev->invert(value);
}

void Plugboard::rotate()
{
  next->rotate();
}

void Plugboard::resetNext()
{
  this->next = &nullmap;
}

void Plugboard::resetPrev()
{
  this->prev = &nullmap;
}
