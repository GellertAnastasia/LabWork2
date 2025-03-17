#include "character.h"

void Character::calculateMovement(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid) 
{
    movement.clear();
    const int currentX = coordinates->getX();
    const int currentY = coordinates->getY();
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    for (const auto& [dx, dy] : directions) {
        const int newX = currentX + dx;
        const int newY = currentY + dy;
        auto newCoords = std::make_shared<Coordinates>(newX, newY);
        if (isWithinBounds(newCoords) && isFree(newCoords, grid)) {
            movement.push_back(newCoords);
        }
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

bool Character::isWithinAttackRange(int targetX, int targetY, const std::shared_ptr<Coordinates>& coordinates) {
    const int currentX = coordinates->getX();
    const int currentY = coordinates->getY();
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    int dx = std::abs(targetX - currentX);
    int dy = std::abs(targetY - currentY);

    return (dx == 1 && dy == 0) || (dy == 1 && dx == 0);
    for (const auto& [x, y] : directions) {
        if (dx == x && dy == y) {
            return true;
        }
    }
    return false;
}   
    

void Character::calculateAttack(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid) 
{
    for (size_t y = 0; y < grid.size(); y++) {         
        for (size_t x = 0; x < grid[y].size(); x++) {
             if ((grid[y][x] != nullptr) && (grid[y][x]->color != color) && isWithinAttackRange(x, y, coordinates)) {                 
                 attack.push_back(grid[y][x]);
             }
        }
    }
}

void Character::printAttack() {
    for (size_t i = 0; i < attack.size(); ++i) {
        if (attack[i]) {
            std::cout << i + 1 << ". " << attack[i]->getName() << "\n";
        }
    }
}

std::string Character::getName() const
{
    return "empty";
}

