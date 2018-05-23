#include "Mapping.hpp"

void Mapping::setNext(Mapping* next)
{
  //(this->next)->resetPrev();
  this->next = next;

  //(next->prev)->resetNext();
  next->prev = this;

}
void Mapping::setPrev(Mapping* prev)
{
  prev->setNext(this);
}

Mapping::~Mapping()
{
  prev->resetNext();
  next->resetPrev();
}
