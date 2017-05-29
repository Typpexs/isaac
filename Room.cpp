#include "includes/Room.hh"

Room::Room(int const w, int const h, int const num)
{
    _width = w;
    _height = h;
    _numRoom = num;
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

int     Room::getNumRoom()
{
    return _numRoom;
}

bool    Room::getDorableFace(std::string face)
{
    return _mapWall[face]->getDorable();
}

void    Room::changeDorableFace(std::string face, bool dorable)
{
    _mapWall[face]->setDorable(dorable);
}

void    Room::addDorsFace(std::string face)
{
    if (face == "top" || face == "bot")
        _mapWall[face]->addDors(_width/2);
    else
        _mapWall[face]->addDors(_height/2);

}

int    Room::getDorsAt(std::string face)
{
    if (face == "top" || face == "bot")
        return _mapWall[face]->getDors(_width/2)->getDorsTo();
    else
        return _mapWall[face]->getDors(_height/2)->getDorsTo();
}

int    Room::getNumberDors()
{
    std::vector<std::string> nameFace;
    nameFace.push_back("top");
    nameFace.push_back("right");
    nameFace.push_back("bot");
    nameFace.push_back("left");

    int number = 0;

    std::vector<std::string>::iterator ite = nameFace.begin();
    while (ite != nameFace.end())
    {
        if (!getDorableFace((*ite)))
            number++;
        ite++;
    }
    return number;
}

void    Room::createDorsToRoom(std::string face, int numRoom)
{
    if (face == "top")
    {
        _mapWall["bot"]->addDors(_width/2);
        _mapWall["bot"]->getDors(_width/2)->changeDorsTo(numRoom);
        changeDorableFace("bot", false);
    }
    else if (face == "bot")
    {
        _mapWall["top"]->addDors(_width/2);
        _mapWall["top"]->getDors(_width/2)->changeDorsTo(numRoom);
        changeDorableFace("top", false);
    }
    else if (face == "right")
    {
        _mapWall["left"]->addDors(_height/2);
        _mapWall["left"]->getDors(_height/2)->changeDorsTo(numRoom);
        changeDorableFace("left", false);
    }
    else
    {
        _mapWall["right"]->addDors(_height/2);
        _mapWall["right"]->getDors(_height/2)->changeDorsTo(numRoom);
        changeDorableFace("right", false);
    }
}

void    Room::changeDorsFaceToNewRoom(std::string face, int numRoom)
{
    std::cout << face << std::endl;
    if (face == "top" || face == "bot")
        _mapWall[face]->getDors(_width/2)->changeDorsTo(numRoom);
    else
        _mapWall[face]->getDors(_height/2)->changeDorsTo(numRoom);
}

void    Room::printMap(std::string cote)
{
    std::vector<AObject*>::const_iterator ite = _mapWall[cote]->getWall().begin();
    while (ite != _mapWall[cote]->getWall().end())
    {
        std::cout << (*ite)->getObject();
        ite++;
    }
    std::cout << std::endl;
}

void    Room::display()
{
    printMap("top");
    std::vector<AObject*>::const_iterator gauche = _mapWall["left"]->getWall().begin();
    std::vector<AObject*>::const_iterator droite = _mapWall["right"]->getWall().begin();
    
    for (int i=0; i < _height; i++)
    {
        std::cout << (*gauche)->getObject();
        for(int k=0; k < _width; k++)
            std::cout << _floor->getFloorAt(i, k);
        std::cout << (*droite)->getObject() << std::endl;
        if (gauche != _mapWall["left"]->getWall().end() && droite != _mapWall["right"]->getWall().end())
        {
            gauche++;
            droite++;
        }
    }
    printMap("bot");
}

void    Room::printAllDors()
{
    std::vector<std::string> nameFace;
    nameFace.push_back("top");
    nameFace.push_back("right");
    nameFace.push_back("bot");
    nameFace.push_back("left");

    std::vector<std::string>::iterator ite = nameFace.begin();
    while (ite != nameFace.end())
    {
        if (!getDorableFace((*ite)))
        {
            if ((*ite) == "top" || (*ite) == "bot")
                std::cout << " \t -- Coté : " << (*ite) << "--> " << _mapWall[(*ite)]->getDors(_width/2)->getDorsTo() << std::endl;
            else
                std::cout << " \t -- Coté : " << (*ite) << "--> " << _mapWall[(*ite)]->getDors(_height/2)->getDorsTo() << std::endl;
        }
        ite++;
    }
}