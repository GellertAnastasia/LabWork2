/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "addHealth.h"

std::string AddHealth::getName() const
{
    return "Add +"+ std::to_string(getPoints()) + HEALTH;
}

void AddHealth::addPoints(std::shared_ptr<Character>& character)
{
    character->setHealth(character->getHealth() + getPoints());
    std::cout << "+" + std::to_string(getPoints()) + HEALTH + " for ";
    std::cout << character->getName()+"\n";
}
