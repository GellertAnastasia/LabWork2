/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "fighter.h"

Fighter::Fighter()
{
    setCell("⚔︎");
    setHealth(3);
    setPower(3);
    setCost(2);
}

std::string Fighter::getName() const
{
    if (getLocation() != nullptr)
    {
        return "Fighter" + getLocation()->get() + ": " + std::to_string(health) + HEALTH + " " + std::to_string(getPower()) + POWER;
    }
    else
    {
        return "Fighter: " + std::to_string(health) + HEALTH + " " + std::to_string(getPower()) + POWER;
    }
}
