#include "func.h"


bool isWithinBounds(std::shared_ptr<Coordinates> coordinates) {
    int x = coordinates->getX();
    int y = coordinates->getY();
    return (x >= 1 && x <= WIDTH && y >= 1 && y <= HEIGHT);
}

bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<std::shared_ptr<Object>>> grid) {
    int x = coordinates->getX();
    int y = coordinates->getY();
    if ((y == 1 || y == 10) && (x == 5 || x == 6)) {
        return false;
    } else if (grid[y-1][x-1] == nullptr) {
        return true;
    } else {
        return false;
    }
}
