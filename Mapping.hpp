#ifndef MAPPING_H
#define MAPPING_H

//Provides to basic methods for an invertible, conjugable map.
//Also an identity map for intitialisation of next and prev in child classes
class Mapping
{
  public:
    virtual ~Mapping();
    virtual void map(int& value) {};
    virtual void invert(int& value) {};
    virtual void rotate() {};
    void setNext(Mapping* next);
    void setPrev(Mapping* prev);
  protected:
    Mapping* next;
    Mapping* prev;
    virtual void resetNext() {};
    virtual void resetPrev() {};
};

#endif
