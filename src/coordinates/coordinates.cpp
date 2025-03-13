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
    return (x > 0 && x <= WIDTH && y > 0 && y <= HEIGHT);
}

bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::shared_ptr<Coordinates>> location) {
    int x = coordinates->getX();
    int y = coordinates->getY();
    if (y == 1 && (x == 5 || x == 6)) {
        return false;
    } else {
        auto it = std::find_if(location.begin(), location.end(),
        [coordinates](const std::shared_ptr<Coordinates>& coord) {
            return *coord == *coordinates; // Сравнение объектов по значениям
        });
        if (it != location.end()) {
            return false;
        } else {
            if (!location.empty() && *location.back() == *coordinates) {
                return false;
            } else {
                return true;
            }
        }
    }
}
