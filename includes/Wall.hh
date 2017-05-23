#ifndef WALL_HH_
#define WALL_HH_

#include "Rock.hpp"
#include "Dors.hpp"

class Wall
{
public:
    Wall(int);
    ~Wall();

    void                    addDors(int);
    void                    setDorable(bool);
    std::vector<AObject>    getWall();

private:
    std::vector<AObject> _wall;
    bool                _isDorable;
};

#endif /* !WALL_HH_ */