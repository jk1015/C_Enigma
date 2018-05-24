#include "Reflector.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Reflector::Reflector()
{}

void Reflector::map(int& value)
{
  value = (value + 13) % 26;
}

void Reflector::invert(int& value)
{
  map(value);
}
