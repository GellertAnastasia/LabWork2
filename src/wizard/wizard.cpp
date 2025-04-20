#include "wizard.h"

Wizard::Wizard()
{
    setCell("✫");
    setHealth(2);
    setPower(1);
    setDirectionOfAttack(
    {
        {0, 1},
        {1, 0},
        {1, 1},
    });
}

std::string Wizard::getName() const
{
    if (getLocation() != nullptr) {
        return "Wizard" + getLocation()->get() + ": " + std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    } else {
        return "Wizard: " + std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    }
}
