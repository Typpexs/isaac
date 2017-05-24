#ifndef MAZE_HH_
#define MAZE_HH_

#include "stdlib.h"
#include "time.h"
#include "Room.hh"

class Maze
{
public:
    Maze();
    ~Maze();

    void    createMaze();
    void    printMap();

private:
    // std::vector<std::vector<Room *> > _vecRoom;
    std::map<Room*, std::map<std::string, Room *> > _mapRoom;
    std::vector<Room*> _vecRoom;
    int     _numRoom;
    int     _actualRoom;
    int     _RoomPlaced;

    void    checkFace(Room &);
    Room    *createNewRoom(std::string,int);
    bool    inVector(int);
    Room    *getRoom(int);
};

#endif /* !MAZE_HH_ */

