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




bool isWithinBounds(std::shared_ptr<Coordinates> coordinates) {
    int x = coordinates->getX();
    int y = coordinates->getY();
    return (x >= 1 && x <= WIDTH && y >= 1 && y <= HEIGHT);
}

bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<bool>> full) {
    int x = coordinates->getX();
    int y = coordinates->getY();
    if ((y == 1 || y == 10) && (x == 5 || x == 6)) {
        return false;
    } else {
        return !(full[y-1][x-1]);
    }
}
