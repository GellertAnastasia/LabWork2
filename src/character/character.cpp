#include "character.h"

void Character::calculateMovement(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<bool>> full)
{
    int x = coordinates->getX();
    int y = coordinates->getY();
    auto coord = std::make_shared<Coordinates>(x-1,y);
    coord->setX(x-1);
    coord->setY(y);
    if (isWithinBounds(coord) && isFree(coord, full)) {
        movement.push_back(std::make_shared<Coordinates>(x-1,y));
    }
    coord->setX(x);
    coord->setY(y-1);
    if (isWithinBounds(coord) && isFree(coord, full)) {
        movement.push_back(std::make_shared<Coordinates>(x,y-1));
    }
    coord->setX(x+1);
    coord->setY(y);
    if (isWithinBounds(coord) && isFree(coord, full)) {
        movement.push_back(std::make_shared<Coordinates>(x+1,y));
    }
    coord->setX(x);
    coord->setY(y+1);
    if (isWithinBounds(coord) && isFree(coord, full)) {
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
/*
void Character::calculateAttack(std::shared_ptr<Coordinates> coordinates, std::vector<std::shared_ptr<Coordinates>> location)
{
    int x = coordinates->getX();
    int y = coordinates->getY();
    auto coord = std::make_shared<Coordinates>(x-1,y);
    coord->setX(x-1);
    coord->setY(y);
    if (isWithinBounds(coord) && isFree(coord, attack)) {
        attack.push_back(std::make_shared<Coordinates>(x-1,y));
    }
    coord->setX(x);
    coord->setY(y-1);
    if (isWithinBounds(coord) && isFree(coord, attack)) {
        attack.push_back(std::make_shared<Coordinates>(x,y-1));
    }
    coord->setX(x+1);
    coord->setY(y);
    if (isWithinBounds(coord) && isFree(coord, attack)) {
        attack.push_back(std::make_shared<Coordinates>(x+1,y));
    }
    coord->setX(x);
    coord->setY(y+1);
    if (isWithinBounds(coord) && isFree(coord, attack)) {
        attack.push_back(std::make_shared<Coordinates>(x,y+1));
    }
}

void Character::printAttack() {
    for (size_t i = 0; i < attack.size(); ++i) {
        if (attack[i]) {
            std::cout << i + 1 << ". ";
            attack[i]->print();
            std::cout << "\n";
        }
    }
}
*/
std::string Character::getName() const
{
    return "empty";
}

