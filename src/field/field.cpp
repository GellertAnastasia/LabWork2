#include "field.h"

Field::Field() : grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH, nullptr)) {}

bool Field::addCharacter(Player& player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Object> character) {
    int x = coordinates->getX() - 1;
    int y = coordinates->getY() - 1;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        std::cout << "Coordinates out of bounds!\n";
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

void Field::processFarmsIncome(Player& player) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell) {
                auto farm = std::dynamic_pointer_cast<Farm>(cell);
                if (farm && farm->owner == &player) {
                    farm->bringMoney();
                }
            }
        }
    }
}


void drawField(Field& field, Player& player, Player& enemy) {
    clearScreen();
    std::cout << "  ";
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << x + 1;
        if (x != WIDTH - 1) std::cout << " ";
    }
    std::cout << "    ╎\033["<< player.color <<"m        Player\033[0m's turn\n";


    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << static_cast<char>('A' + y) << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if (field.grid[y][x] == nullptr) {
                std::cout << EMPTY_CELL;
            } else {
                std::cout << "\033[" << field.grid[y][x]->getColor() << ";1m" << field.grid[y][x]->getCell() << "\033[0m";
            }
            if (x != WIDTH - 1) std::cout << " ";
        }
        if (y == 0) {
            std::cout << "     ╎   ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌";
        } else if (y == 1) {
            std::cout << "     "<< "╎" << "\033["<< player.color <<"m   Player\033["<< enemy.color <<"m         Player"<<"\033[0m";
        } else if (y == 2) {
            std::cout << "     "<< "╎" << "   base hp: " << player.base->health << "     base hp: " << enemy.base->health;
        } else if (y == 3) {
            std::cout << "     "<< "╎" << "   mana: " << player.mana << "        mana: " << enemy.mana;
        } else if (y == 4) {
            std::cout << "     "<< "╎" << "   money: " << player.money << "       money: " << enemy.money;
        } else {
            std::cout << "     "<< "╎";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

