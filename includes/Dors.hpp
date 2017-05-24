#ifndef DORS_HH_
#define DORS_HH_

#include "AObject.hpp"

class Dors: public AObject
{
public:
    Dors() {_numObject = 2; _dorsTo = 0;}

    void    changeDorsTo(int);
    int     getDorsTo();
private:
    int     _dorsTo;
};

#endif /* !DORS_HH_ */