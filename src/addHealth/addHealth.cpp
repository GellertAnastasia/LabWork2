#include "addHealth.h"

void AddHealth::setPoints(char value) {
    points = value;
}
int AddHealth::getPoints() const {
    return points;
}
std::string AddHealth::getName() const {
        return "+"+ std::to_string(getPoints()) + " health";
}

void AddHealth::addPoints(std::shared_ptr<Character>& character) {
    character->health += getPoints();
    std::cout << "+" + std::to_string(getPoints()) +" health\n";
    std::cout << character->getName()+"\n";
} 
