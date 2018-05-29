#include "Plugboard.hpp"
#include "Util.hpp"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//Construct a Plugboard from an int vector
//Error if |v| is not even or mapping is invalid
Plugboard::Plugboard(vector<int>& v)
{
  if(v.size() % 2 == 1)
  {
    throw invalid_argument("Plugboard mappings must contain an even number of values");
  }
  for (unsigned i = 0; i < v.size(); i += 2)
  {
    if(v[i] >= alphabet_size || v[i] < 0 || v[i + 1] >= alphabet_size || v[i + 1] < 0)
    {
      throw invalid_argument("Invalid value in plugboard mapping values must be in {0,..,25}");
    }
    //check if key already exists
    if(config.count(v[i]) || config.count(v[i + 1]))
    {
      throw invalid_argument("Value mapped multiple times in plugboard");
    }
    config[v[i]] = v[i + 1];
    config[v[i + 1]] = v[i];
  }

  for (int i = 0; i < alphabet_size; i++)
  {
    if(!config.count(i))
    {
      config[i] = i;
    }
  }
}

void Plugboard::map(int& value)
{
  value = config[value];
}

void Plugboard::invert(int& value)
{
  map(value);
}
