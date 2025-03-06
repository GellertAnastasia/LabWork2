#ifndef FIGHTER_H
#define FIGHTER_H
#include "../character/character.h"

class Fighter: public Character
{
public:
    std::string getName() const override;
};

#endif
