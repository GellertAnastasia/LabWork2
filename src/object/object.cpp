#include "object.h"

void Object::setCell(char value) {
    cell = value;
}
char Object::getCell() const {
    return cell;
}

void Object::setColor(int value) {
    color = value;
}
int Object::getColor() const {
    return color;
}

void Object::setLocation(const std::shared_ptr<Coordinates>& newLocation) {
    location = newLocation;
}
std::shared_ptr<Coordinates> Object::getLocation() const {
    return location;
}

void Object::addHealth(int profit) {
    health += profit;
}
