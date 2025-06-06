/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "barrier.h"

Barrier::Barrier()
{
    setCell("≡");
    setHealth(5);
}

std::string Barrier::getName() const
{
    if (getLocation() != nullptr)
    {
        return "Barrier" + getLocation()->get() + ": " + std::to_string(health) + HEALTH;
    }
    else
    {
        return "Barrier: " + std::to_string(health) + HEALTH;
    }
}
