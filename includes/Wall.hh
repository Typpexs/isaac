#ifndef WALL_HH_
#define WALL_HH_

#include "Rock.hpp"
#include "Dors.hpp"

class Wall
{
public:
    Wall(int);
    Wall(const Wall&);
    ~Wall();

    void                    addDors(int);
    void                    setDorable(bool);
    const std::vector<AObject*>   &getWall() const;
    bool                    getDorable() const;
    Dors                    *getDors(int);

    Wall                    &operator=(const Wall&);

private:
    std::vector<AObject*> _wall;
    bool                _isDorable;
};

#endif /* !WALL_HH_ */