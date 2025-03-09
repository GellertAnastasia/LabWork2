#include "coordinates.h"

Coordinates::Coordinates(int X, int Y) : x(X), y(Y) {}

void Coordinates::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
