#include "object.h"

void Object::setCell(const std::string& value)
{
    cell = value;
}
std::string Object::getCell() const
{
    return cell;
}

void Object::setColor(int value)
{
    color = value;
}
int Object::getColor() const
{
    return color;
}
void Object::setHealth(int value)
{
    health = value;
}
int Object::getHealth() const
{
    return health;
}

void Object::setLocation(const std::shared_ptr<Coordinates>& newLocation)
{
    location = newLocation;
}
std::shared_ptr<Coordinates> Object::getLocation() const
{
    return location;
}

void Object::changeHealth(int points)
{
    health += points;
}
