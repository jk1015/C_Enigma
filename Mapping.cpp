#include "Mapping.hpp"
#include <iostream>

Mapping::Mapping()
{
  this->hasNext = false;
  this->hasPrev = false;
}

Mapping::~Mapping()
{
  prev->resetNext();
  next->resetPrev();
}

bool Mapping::rotate()
{
  return true;
}

void Mapping::conjugateMap(int& value)
{
  map(value);
  if(hasNext)
  {
    next->conjugateMap(value);
  }
  else if(hasPrev)
  {
    prev->conjugateInverse(value);
  }
}

void Mapping::conjugateInverse(int& value)
{
  invert(value);
  if(hasPrev)
  {
    prev->conjugateInverse(value);
  }
}

void Mapping::conjugateRotate()
{
  if(rotate() && hasNext)
  {
    next->conjugateRotate();
  }
}

void Mapping::setNext(Mapping* next)
{
  if(this->hasNext)
  {
    resetNext();
  }

  this->next = next;
  this->hasNext = true;

  if(next->hasPrev)
  {
    next->resetPrev();
  }
  next->prev = this;
  next->hasPrev = true;
}

void Mapping::setPrev(Mapping* prev)
{
  prev->setNext(this);
}

void Mapping::resetNext()
{
  if(this->hasNext)
  {
    this->hasNext = false;
    next->resetPrev();
  }
}

void Mapping::resetPrev()
{
  if(this->hasPrev)
  {
    this->hasPrev = false;
    prev->resetNext();
  }
}
