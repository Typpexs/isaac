#include "includes/Floor.hh"

Floor::Floor(int w, int h)
{
    _width = w;
    _height = h;
}

Floor::~Floor() {}

std::vector<std::vector<AObject> >  Floor::getFloor()
{
    return _floor;
}

void    Floor::createFloor()
{
    for (int i=0; i<=_height; i++)
    {
        std::vector<AObject> tmp;
        for (int k=0; k <= _width; k++)
            tmp.push_back(Nothing());
        _floor.push_back(tmp);
    }
}