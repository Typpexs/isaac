#include "includes/Wall.hh"

Wall::Wall(int longueur)
{
    _isDorable = true;
    for (int i=0; i < longueur; ++i)
        _wall.push_back(new Rock());
}

Wall::Wall(const Wall &old)
{
    _isDorable = old.getDorable();
    _wall = old.getWall();
}

Wall::~Wall() 
{}

void                    Wall::addDors(int ite)
{
    if (_wall.size() > ite)
        _wall[ite] = new Dors();
}

void                    Wall::setDorable(bool dora)
{
    _isDorable = dora;
}

const std::vector<AObject*>    &Wall::getWall() const
{
    return _wall;
}

bool                    Wall::getDorable() const
{
    return _isDorable;
}

Dors                    *Wall::getDors(int num)
{
    return (Dors*)_wall[num];
}

Wall                    &Wall::operator=(const Wall &old)
{
    return (*this);
}