#ifndef ARCHER_H
#define ARCHER_H
#include "../character/character.h"

class Archer: public Character
{
public:
    Archer();
    std::string getName() const override;
};


#endif
