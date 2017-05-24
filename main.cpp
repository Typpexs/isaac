#include "includes/Maze.hh"

int main()
{
    Maze maze;
    std::cout << "avant le create" << std::endl;
    maze.createMaze();
    std::cout << "après le create" << std::endl;
    maze.printMap();
    // Room room(15,10);
    // room.display();
    // std::cout << "sortie du main" << std::endl;
    return 0;
}