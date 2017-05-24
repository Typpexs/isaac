#include "includes/Maze.hh"

Maze::Maze() 
{
    srand(time(NULL));
    _numRoom = rand()% 10 + 10;
    _actualRoom = 1;
    _RoomPlaced = 0;
}

Maze::~Maze() {}

void    Maze::createMaze()
{
    Room *one = new Room(15, 10, _actualRoom);
    while (_RoomPlaced < _numRoom)
        checkFace((*one));
}

void    Maze::checkFace(Room &room)
{
    std::vector<std::string> nameFace;
    nameFace.push_back("top");
    nameFace.push_back("right");
    nameFace.push_back("bot");
    nameFace.push_back("left");

    std::vector<std::string>::iterator ite = nameFace.begin();
    while (ite != nameFace.end())
    {
        if (room.getDorableFace((*ite)))
        {
            if ((rand()%100 + 1) < 20)
            {
                room.addDorsFace((*ite));
                room.changeDorableFace((*ite), true);
                Room *nextRoom = createNewRoom((*ite), room.getNumRoom());
                _mapRoom[&room][(*ite)] = nextRoom;
                room.changeDorsFaceToNewRoom((*ite), nextRoom->getNumRoom());
            }
        }
        ite++;
    }
}

Room    *Maze::createNewRoom(std::string face, int oldDors)
{
    _RoomPlaced++;
    Room *tmp = new Room(15, 10, _RoomPlaced+1);
    tmp->createDorsToRoom(face, oldDors);
    checkFace((*tmp));

    return tmp;
    // return tmp->getNumRoom();
}