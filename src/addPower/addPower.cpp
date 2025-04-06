#include "addPower.h"

void AddPower::setPoints(char value) {
    points = value;
}
int AddPower::getPoints() const {
    return points;
}
std::string AddPower::getName() const {
        return "Add +"+ std::to_string(getPoints()) + POWER;
}

void AddPower::addPoints(std::shared_ptr<Character>& character) {
    character->power += getPoints();
    std::cout << "+" + std::to_string(getPoints()) + POWER;
    std::cout << character->getName()+"\n";
}
