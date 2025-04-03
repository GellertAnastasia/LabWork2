#include "wizard.h"

Wizard::Wizard()
{
    setCell("✫");
    setDirectionOfAttack(
    {
        {0, 1},
        {1, 0},
        {1, 1},
    });
}

std::string Wizard::getName() const
{
    return "Wizard (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}
