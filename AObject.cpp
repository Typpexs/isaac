#include "includes/AObject.hpp"

AObject::AObject() 
{
    _numObject = 0;
}

AObject::AObject(const AObject &old)
{
    _numObject = old.getObject();
}

AObject::~AObject() {}

int     AObject::getObject() const
{
    // std::cout << "Dans le getObject : " << _numObject << std::endl;
    return _numObject;
}

AObject     &AObject::operator=(const AObject &old)
{
    return (*this);
}