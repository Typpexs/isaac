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
    Room *one = new Room(15, 10, _RoomPlaced+1);
    while (_RoomPlaced < _numRoom)
        checkFace((*one));
}

void    Maze::printMap()
{
    std::cout << "Maze de " << _numRoom << " room. "<< std::endl;

    for (std::vector<Room *>::iterator ite = _vecRoom.begin(); ite != _vecRoom.end(); ite++)
    {
        std::cout << "Room " << (*ite)->getNumRoom() << " : " << std::endl;
        (*ite)->printAllDors();
        std::cout << std::endl << " -------- " << std::endl;
    }

    // for (std::map<Room*, std::map<std::string, Room*> >::iterator ite = _mapRoom.begin(); ite != _mapRoom.end(); ite++)
    // {
    //     std::cout << "Room " << ite->first->getNumRoom() << " : " << std::endl;
    //     ite->first->printAllDors();
    //     // for (std::map<std::string, Room*>::iterator iteRoom = ite->second.begin(); iteRoom != ite->second.end(); iteRoom++)
    //     //     std::cout << " \t -- Coté : " << iteRoom->first << " --> " << iteRoom->second->getNumRoom() << std::endl;
    //     std::cout << std::endl << " -------- " << std::endl;
    // }
}

bool    Maze::inVector(int act)
{
    for (std::vector<Room *>::iterator ite = _vecRoom.begin(); ite != _vecRoom.end(); ite++)
    {
        if (act == (*ite)->getNumRoom())
            return false;
    }
    return true;
}

Room    *Maze::getRoom(int act)
{
    for (std::vector<Room *>::iterator ite = _vecRoom.begin(); ite != _vecRoom.end(); ite++)
    {
        if (act == (*ite)->getNumRoom())
            return (*ite);
    }
}

void    Maze::checkFace(Room &room)
{
    std::vector<std::string> nameFace;
    nameFace.push_back("top");
    nameFace.push_back("right");
    nameFace.push_back("bot");
    nameFace.push_back("left");

    std::vector<std::string>::iterator ite = nameFace.begin();
    if (room.getNumberDors() == 4)
        {
            std::map<int, std::string> faceInt;
            faceInt[1] = "top";
            faceInt[2] = "right";
            faceInt[3] = "bot";
            faceInt[4] = "left";
            int num = rand()% 4 + 1;
            checkFace((*getRoom(room.getDorsAt(faceInt[num]))));
        }
    while (ite != nameFace.end())
    {
        if (room.getDorableFace((*ite)))
        {
            if (_RoomPlaced >= _numRoom)
                break;
            if ((rand()%100 + 1) < 20)
            {
                room.addDorsFace((*ite));
                room.changeDorableFace((*ite), false);
                if (inVector(room.getNumRoom()))
                    _vecRoom.push_back(&room);
                Room *nextRoom = createNewRoom((*ite), room.getNumRoom());
                // _mapRoom[&room][(*ite)] = nextRoom;
                if (inVector(nextRoom->getNumRoom()))
                    _vecRoom.push_back(nextRoom);
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