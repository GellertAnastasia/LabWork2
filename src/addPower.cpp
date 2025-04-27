/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "addPower.h"

std::string AddPower::getName() const
{
    return "Add +"+ std::to_string(getPoints()) + POWER;
}

void AddPower::addPoints(std::shared_ptr<Character>& character)
{
    character->setPower(character->getPower() + getPoints());
    std::cout << "+" + std::to_string(getPoints()) + POWER + " for ";
    std::cout << character->getName()+"\n";
}
