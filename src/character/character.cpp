#include "character.h"


const std::vector<std::pair<int, int>>& Character::getDirectionOfMove() const {
    return directionOfMove;
}
void Character::setDirectionOfMove(const std::vector<std::pair<int, int>>& newDirections) {
    directionOfMove = newDirections;
}
const std::vector<std::pair<int, int>>& Character::getDirectionOfAttack() const {
    return directionOfAttack;
}
void Character::setDirectionOfAttack(const std::vector<std::pair<int, int>>& newDirections) {
    directionOfAttack = newDirections;
}

void Character::calculateMovement(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid) 
{
    movement.clear();
    const int currentX = coordinates->getX();
    const int currentY = coordinates->getY();

    for (const auto& [dx, dy] : directionOfMove) {
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
            std::cout << i + 1 << ". " << movement[i]->get() << "\n";
        }
    }
}

bool Character::isWithinAttackRange(int targetX, int targetY, const std::shared_ptr<Coordinates>& coordinates) {
    const int currentX = coordinates->getX()-1;
    const int currentY = coordinates->getY()-1;
    int dx = std::abs(targetX - currentX);
    int dy = std::abs(targetY - currentY);
    for (const auto& [x, y] : directionOfAttack) {
        if (dx == x && dy == y) {
            return true;
        }
    }
    return false;
}   
    

void Character::calculateAttack(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid) 
{
    attack.clear();
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

