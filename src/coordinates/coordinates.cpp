#include "coordinates.h"

Coordinates::Coordinates(int X, int Y) : x(X), y(Y) {}
    
bool Coordinates::operator==(const Coordinates& other) const {
    return x == other.x && y == other.y;
}
int Coordinates::getX() const {
    return x;
}
void Coordinates::setX(int newX) {
    x = newX;
}
int Coordinates::getY() const {
    return y;
}
void Coordinates::setY(int newY) {
    y = newY;
}

void Coordinates::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

