#ifndef FLOOR_HH_
#define FLOOR_HH_

#include "Nothing.hpp"

class Floor
{
public:
    Floor(int, int);
    ~Floor();

    const std::vector<std::vector<AObject*> >  &getFloor() const;
    int     getFloorAt(int,int);
    void    printFloor();
private:
    std::vector<std::vector<AObject*> >  _floor;
    int     _width;
    int     _height;

    void    createFloor();    
};

#endif /* !FLOOR_HH_ */