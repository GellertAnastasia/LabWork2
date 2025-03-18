#include "levelUp.h"

void LevelUp::setPoints(char value) {
    points = value;
}
int LevelUp::getPoints() const {
    return points;
}
std::string LevelUp::getName() const {
        return "+"+ std::to_string(getPoints()) + " level";
}

void LevelUp::addPoints(std::shared_ptr<Character>& character) {
    character->level += getPoints();
    std::cout << "+" + std::to_string(getPoints()) +" level\n";
    std::cout << character->getName()+"\n";
}
