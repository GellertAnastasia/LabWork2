#ifndef WIZARD_H
#define WIZARD_H
#include "../character/character.h"

class Wizard: public Character
{
public:
    std::string getName() const override;
};

#endif
