#include <iostream>
#include "constants.h"
#include "character.h"


bool Character::attack()
{
    return true;
}

void Character::calculateMovement(std::shared_ptr<Coordinates> coordinates) 
{
    int x = coordinates->x;
    int y = coordinates->y;
    if (x-1 > 0 && x-1 <= WIDTH && y > 0 && y <= HEIGHT) {
        movement.push_back(std::make_shared<Coordinates>(x-1,y));
    }
    if (x > 0 && x <= WIDTH && y-1 > 0 && y-1 <= HEIGHT) {
        movement.push_back(std::make_shared<Coordinates>(x,y-1));
    }
    if (x+1 > 0 && x+1 <= WIDTH && y > 0 && y <= HEIGHT) {
        movement.push_back(std::make_shared<Coordinates>(x+1,y));
    }
    if (x > 0 && x <= WIDTH && y+1 > 0 && y+1 <= HEIGHT) {
        movement.push_back(std::make_shared<Coordinates>(x,y+1));
    }
}

void Character::printMovement() {
    for (size_t i = 0; i < movement.size(); ++i) {
        if (movement[i]) {
            std::cout << i + 1 << ". ";
            movement[i]->print();
            std::cout << "\n";
        }
    }
}

std::string Character::getName() const
{
    return "empty";
}

