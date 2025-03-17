#include "field.h"

void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}
void pause() {
    std::cout << "Click Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

Field::Field() : grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH, nullptr)) {}

bool Field::addCharacter(Player& player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Character> character) {
    int x = coordinates->getX() - 1;
    int y = coordinates->getY() - 1;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        std::cout << "Coordinates out of bounds!\n";
        pause();
        return false;
    } else if ((grid[y][x] != nullptr) || ((y == 0 || y == 9) && (x == 4 || x == 5))) {
        std::cout << "Cell is occupied!\n";
        pause();
        return false;
    } else {
         character->setColor(player.color);
         grid[y][x] = character;
         player.charactersOnGrid.push_back(character);
         player.location.push_back(coordinates);
         return true;
    }
}

void Field::deleteObject(int choice, Player& player)
{
    int x = player.location[choice-1]->getX();
    int y = player.location[choice-1]->getY();
    if (x >= 1 && x <= WIDTH && y >= 1 && y <= HEIGHT) {
        grid[y-1][x-1] = nullptr;
        player.charactersOnGrid.erase(player.charactersOnGrid.begin() + choice-1);
        player.location.erase(player.location.begin() + choice-1);
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
            if ((y == 0) && (x == 4 || x == 5)) {
                std::cout <<"\033[31;1m" << "B" << "\033[0m";
            } else if ((y == 9) && (x == 4 || x == 5)) {
                std::cout <<"\033[34;1m" << "B" << "\033[0m";
            } else if (field.grid[y][x] == nullptr) {
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

