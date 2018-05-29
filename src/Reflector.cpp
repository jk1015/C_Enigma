#include "Reflector.hpp"
#include "Util.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Reflector::Reflector()
{}

void Reflector::map(int& value)
{
  value = (value + alphabet_size/2) % alphabet_size;
}

void Reflector::invert(int& value)
{
  map(value);
}
