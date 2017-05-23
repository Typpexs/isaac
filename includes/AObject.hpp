#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "Includes.hh"

class AObject
{
public:
    AObject();
    ~AObject();

    int getObject();

protected:
    int _numObject;
};

#endif /* !AOBJECT_HPP_ */