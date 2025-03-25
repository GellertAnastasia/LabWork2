#ifndef ARCHER_H
#define ARCHER_H
#include "../character/character.h"

class Archer: public Character
{
public:
    Archer();
    std::vector<std::pair<int, int>> directionOfMove = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };
    std::string getName() const override;
};


#endif
