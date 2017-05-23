#include "includes/Room.hh"

Room::Room(int const w, int const h)
{
    _width = w;
    _height = h;
    initMapWall();
    _floor = new Floor(w, h);
}

Room::~Room() 
{
    delete _floor;
}

void    Room::initMapWall()
{
    _mapWall["top"] = new Wall(_width);
    _mapWall["bot"] = new Wall(_width);
    _mapWall["left"] = new Wall(_height);
    _mapWall["right"] = new Wall(_height);
}

void    Room::printMap(std::string cote)
{
    std::vector<AObject>::iterator ite = _mapWall[cote]->getWall().begin();
    std::cout << "Size : " << _mapWall[cote]->getWall().size() << std::endl;
    while (ite != _mapWall[cote]->getWall().end())
    {
        std::cout << (*ite).getObject();
        ite++;
    }
    std::cout << std::endl;
}

void    Room::display()
{
    std::cout << "AVANT" << std::endl;
    printMap("top");
    std::cout << "ICI" << std::endl;

    int i, k = 0;
    std::vector<AObject>::iterator gauche = _mapWall["left"]->getWall().begin();
    std::vector<AObject>::iterator droite = _mapWall["right"]->getWall().begin();
    gauche++;
    droite++;
    
    while (i < _height)
    {
        k = 0;
        std::cout << (*gauche).getObject();
        while (k < _width)
        {
            std::cout << _floor->getFloor()[i][k].getObject();
            k++;
        }
        std::cout << (*droite).getObject() << std::endl;
        if (gauche != _mapWall["left"]->getWall().end() && droite != _mapWall["right"]->getWall().end())
        {
            gauche++;
            droite++;
        }
    }
    printMap("bot");
}