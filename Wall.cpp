#include "includes/Wall.hh"

Wall::Wall(int longueur)
{
    _isDorable = true;
    for (int i=0; i < longueur; ++i)
        _wall.push_back(Rock());
}

Wall::~Wall() 
{}

void                    Wall::addDors(int ite)
{
    if (_wall.size() > ite)
        _wall[ite] = Dors();
}

void                    Wall::setDorable(bool dora)
{
    _isDorable = dora;
}

std::vector<AObject>    Wall::getWall()
{
    return _wall;
}