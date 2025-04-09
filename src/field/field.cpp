#include "field.h"

Field::Field() : grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH, nullptr)) {}

bool Field::placeNewCharacter(Player& player, const std::shared_ptr<Coordinates>& coords, std::shared_ptr<Object> character) {
    int x = coords->getX() - 1;
    int y = coords->getY() - 1;

    if (grid[y][x] != nullptr) {
        std::cout << "Cell is occupied!\n";
        pause();
        return false;
    }

    character->setColor(player.color);
    character->setLocation(coords);

    grid[y][x] = character;

    auto characterPtr = std::dynamic_pointer_cast<Character>(character);
    if (characterPtr) {
        player.charactersOnGrid.push_back(characterPtr);
    }

    return true;
}
bool Field::moveCharacter(Player& player, const std::shared_ptr<Coordinates>& from, std::shared_ptr<Coordinates>& to) {
    int fromX = from->getX() - 1;
    int fromY = from->getY() - 1;
    int toX = to->getX() - 1;
    int toY = to->getY() - 1;


    auto& sourceCell = grid[fromY][fromX];
    auto& destCell = grid[toY][toX];

    destCell = sourceCell;
    destCell->setLocation(to);
    sourceCell.reset();

    return true;
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

