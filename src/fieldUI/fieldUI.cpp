#include "fieldUI.h"

FieldUI::FieldUI(Field& field) : field(field){}

void FieldUI::draw(Player& player, Player& enemy) {
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

