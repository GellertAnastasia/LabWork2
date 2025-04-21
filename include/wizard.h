#ifndef WIZARD_H
#define WIZARD_H
#include "character.h"

class Wizard: public Character
{
public:
    Wizard();
    std::string getName() const override;
};

#endif
