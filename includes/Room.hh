#ifndef ROOM_HH_
#define ROOM_HH_

#include "Wall.hh"
#include "Floor.hh"

class Room
{
public:
    Room(int const, int const, int const);
    ~Room();

    void    display();
    bool    getDorableFace(std::string);
    void    changeDorableFace(std::string, bool);
    void    addDorsFace(std::string);
    int     getNumRoom();
    void    createDorsToRoom(std::string, int);
    void    changeDorsFaceToNewRoom(std::string, int);
    void    printAllDors();
    int     getNumberDors();
    int     getDorsAt(std::string);

private:
    int     _width;
    int     _height;
    int     _numRoom;
    std::map<std::string, Wall*> _mapWall;
    Floor   *_floor;

    void   initMapWall();
    void   printMap(std::string);
};

#endif /* !ROOM_HH_ */