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


    const std::string forest_green = "\033[38;5;28m";
    const std::string azure = "\033[38;2;135;206;250m";
    const std::string reset = "\033[0m";

    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << static_cast<char>('A' + y) << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if (field.grid[y][x] == nullptr) {
                if (y < 4) {
                    std::cout << forest_green << "⋅" << reset;
                } else if (y >= HEIGHT - 4) {
                    std::cout << azure << "⋅" << reset;
                } else {
                    std::cout << "⋅";
                }
            } else {
                std::cout << "\033[" << field.grid[y][x]->getColor() << ";1m" 
                          << field.grid[y][x]->getCell() << reset;
            }
            if (x != WIDTH - 1) std::cout << " ";
        }
        
        if (y == 0) {
            std::cout << "     ╎   ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌";
        } else if (y == 1) {
            std::cout << "     ╎" << "\033["<< player.color <<"m   Player\033["<< enemy.color <<"m         Player"<<"\033[0m";
        } else if (y == 2) {
            std::cout << "     ╎   base hp: " << player.base->health << "     base hp: " << enemy.base->health;
        } else if (y == 3) {
            std::cout << "     ╎   mana: " << player.mana << "\033[38;5;129m✧\033[0m       mana: " << enemy.mana << "\033[38;5;129m✧\033[0m";
        } else if (y == 4) {
            std::cout << "     ╎   money: " << player.money << "\033[38;2;255;215;0m❍\033[0m      money: " << enemy.money <<  "\033[38;2;255;215;0m❍\033[0m";
        } else {
            std::cout << "     ╎";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
