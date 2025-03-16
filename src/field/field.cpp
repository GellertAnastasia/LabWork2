#include "field.h"

void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}

Field::Field() : grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH)), full(HEIGHT, std::vector<bool>(WIDTH, false)) {}

void Field::addCharacter(Player& player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Character> character) 
{
    int x = coordinates->getX();
    int y = coordinates->getY();
    character->setColor(player.color);
    if (isWithinBounds(coordinates) && isFree(coordinates, full)) {
        full[y-1][x-1] = true;
        grid[y-1][x-1] = character;
        player.charactersOnGrid.push_back(character);
        player.location.push_back(coordinates);
        //player.mana = player.mana - 1;
        
    }
}

void Field::deleteObject(int choice, Player& player)
{
    int x = player.location[choice-1]->getX();
    int y = player.location[choice-1]->getY();
    if (x >= 1 && x <= WIDTH && y >= 1 && y <= HEIGHT) {
        full[y-1][x-1] = false;
        grid[y-1][x-1] = nullptr;
        player.charactersOnGrid.erase(player.charactersOnGrid.begin() + choice-1);
        player.location.erase(player.location.begin() + choice-1);
    }
}

void drawField(Field field, Player player) {
    clearScreen();
    std::cout << "  ";
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << x + 1;
        if (x != WIDTH - 1) std::cout << " ";
    }
    std::cout << "\n";


    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << static_cast<char>('A' + y) << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if ((y == 0) && (x == 4 || x == 5)) {
                std::cout <<"\033[31;1m" << "B" << "\033[0m";
            } else if ((y == 9) && (x == 4 || x == 5)) {
                std::cout <<"\033[34;1m" << "B" << "\033[0m";
            } else if (field.full[y][x] == false) {
                std::cout << EMPTY_CELL;
            } else {
                std::cout << "\033[" << field.grid[y][x]->getColor() << ";1m" << field.grid[y][x]->getCell() << "\033[0m";
            }
            if (x != WIDTH - 1) std::cout << " ";
        }
        if (y == 1) {
        std::cout << "     " << "╎" << "   mana: " << player.mana;
        } else if (y == 2) {
        std::cout << "     " << "╎" << "   money: " << player.money;
        } else {
        std::cout << "     " << "╎";
        }
        std::cout << "\n";
    }
}

