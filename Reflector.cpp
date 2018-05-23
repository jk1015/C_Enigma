#include "Reflector.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Reflector::Reflector()
{
  this->setNext(&nullmap);
  this->setPrev(&nullmap);
}

void Reflector::map(int& value)
{
  value = (value + 13) % 26;
  prev->invert(value);
}

void Reflector::invert(int& value)
{
  cerr << "Reflector should always be the last mapping in a sequence." << endl
       << "This shouldn't be called!" << endl;
  exit(1);
}

void Reflector::resetNext()
{
  this->setNext(&nullmap);
}

void Reflector::resetPrev()
{
  this->setPrev(&nullmap);
}
