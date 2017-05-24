#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "Includes.hh"

class AObject
{
public:
    AObject();
    AObject(const AObject&);
    ~AObject();

    int getObject() const;

    AObject     &operator=(const AObject&);

protected:
    int _numObject;
};

#endif /* !AOBJECT_HPP_ */