#ifndef MAPPING_H
#define MAPPING_H

//Provides to basic methods for an invertible, conjugable, rotatable map.
//The last map in a sequence will always reflect, in our machine we always
//set this mapping to the reflector mapping.
class Mapping
{
  public:
    Mapping();
    virtual ~Mapping();
    virtual void map(int& value) = 0;
    virtual void invert(int& value) = 0;
    virtual bool rotate();
    void conjugateMap(int& value);
    void conjugateInverse(int& value);
    void conjugateRotate();
    void setNext(Mapping* next);
    void setPrev(Mapping* prev);
    void resetNext();
    void resetPrev();
  protected:
    Mapping* next;
    Mapping* prev;
    bool hasNext;
    bool hasPrev;
};

#endif
