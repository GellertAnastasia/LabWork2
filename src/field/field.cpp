#include "field.h"

Field::Field() : grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH, nullptr)) {}

bool Field::addCharacter(Player& player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Object> character) {
    int x = coordinates->getX() - 1;
    int y = coordinates->getY() - 1;
    if (x < player.zone.getMinX() || x > player.zone.getMaxX() || y < player.zone.getMinY() || y > player.zone.getMaxY()) {
        std::cout << "Coordinates out of your zone\n";
        pause();
        return false;
    } else if (grid[y][x] != nullptr) {
        std::cout << "Cell is occupied!\n";
        pause();
        return false;
    } else {
         character->setColor(player.color);
         character->setLocation(coordinates);
         grid[y][x] = character;
         auto characterPtr = std::dynamic_pointer_cast<Character>(character);
         if (characterPtr) {
             player.charactersOnGrid.push_back(characterPtr);
         }
         return true;
    }
}

void Field::deleteObject(const std::shared_ptr<Coordinates>& coords, Player& player) {
    int x = coords->getX()-1;
    int y = coords->getY()-1;

    if (isWithinBounds(coords)) {
        auto it = std::find(player.charactersOnGrid.begin(), 
                          player.charactersOnGrid.end(), 
                          grid[y][x]);
        if (it != player.charactersOnGrid.end()) {
            player.charactersOnGrid.erase(it);
        }
        grid[y][x] = nullptr;
    }
}

int Field::processFarmsIncome(Player& player) {
    int totalProfit = 0;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell) {
                auto farm = std::dynamic_pointer_cast<Farm>(cell);
                if (farm && farm->owner == &player) {
                    totalProfit += farm->bringMoney();
                }
            }
        }
    }
    return totalProfit;
}

