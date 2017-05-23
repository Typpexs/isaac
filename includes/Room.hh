#ifndef ROOM_HH_
#define ROOM_HH_

#include "Wall.hh"
#include "Floor.hh"

class Room
{
public:
    Room(int const, int const);
    ~Room();

    void    display();
private:
    int     _width;
    int     _height;
    std::map<std::string, Wall*> _mapWall;
    Floor   *_floor;

    void   initMapWall();
    void   printMap(std::string);
};

#endif /* !ROOM_HH_ */