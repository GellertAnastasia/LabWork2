#ifndef ARCHER_H
#define ARCHER_H
#include "../character/character.h"

class Archer: public Character
{
public:
    Archer();
    char cell = 'A';
    std::string getName() const override;
};


#endif
