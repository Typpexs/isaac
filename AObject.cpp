#include "includes/AObject.hpp"

AObject::AObject() 
{
    _numObject = 0;
}

AObject::~AObject() {}

int     AObject::getObject()
{
    return _numObject;
}