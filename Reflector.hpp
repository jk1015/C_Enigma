#include "Mapping.hpp"

#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector: public Mapping
{
  public:
    Reflector();
    void map(int& value);
    void invert(int& value);
    void rotate() {};
  protected:
    void resetNext();
    void resetPrev();
  private:
    Mapping nullmap;
};

#endif
