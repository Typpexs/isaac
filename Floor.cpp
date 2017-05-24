#include "includes/Floor.hh"

Floor::Floor(int w, int h)
{
    _width = w;
    _height = h;
    createFloor();
}

Floor::~Floor() {}

const std::vector<std::vector<AObject*> >  &Floor::getFloor() const
{
    return _floor;
}

void    Floor::createFloor()
{
    for (int i=0; i<_height; i++)
    {
        std::vector<AObject*> tmp;
        for (int k=0; k < _width; k++)
            tmp.push_back(new Nothing());
        _floor.push_back(tmp);
    }
}

int     Floor::getFloorAt(int x, int y)
{
    return _floor[x][y]->getObject();
}

void    Floor::printFloor()
{
    for (int i=0; i<_floor.size(); i++)
    {
        for (int j=0; j<_floor[i].size(); j++)
            std::cout << _floor[i][j]->getObject();
        std::cout << std::endl;
    }
}