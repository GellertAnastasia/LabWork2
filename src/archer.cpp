/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "archer.h"

Archer::Archer()
{
    setCell("➶");
    setHealth(2);
    setPower(2);
    setCost(2);
    setDirectionOfMove(
    {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    });
    setDirectionOfAttack(
    {
        {1, 1},
        {2, 2}
    });
}

std::string Archer::getName() const
{
    if (getLocation() != nullptr)
    {
        return "Archer" + getLocation()->get() + ": "+ std::to_string(health) + HEALTH + " " + std::to_string(getPower()) + POWER;
    }
    else
    {
        return "Archer: "+ std::to_string(health) + HEALTH + " " + std::to_string(getPower()) + POWER;
    }
}


