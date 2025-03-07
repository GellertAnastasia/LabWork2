#include "../include/constants.h"
#include "player/player.h"
#include "field/field.h"
#include "fighter/fighter.h"
#include "wizard/wizard.h"
#include "archer/archer.h"

void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}


int main() {
    while (true) {
        clearScreen();

        std::cout << "Меню игры:\n";
        std::cout << "1. Start\n";
        std::cout << "2. Exit\n";
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            Field field;
            Player player(5,0);
            player.inventory.push_back(std::make_shared<Fighter>());
            player.inventory.push_back(std::make_shared<Wizard>());
            player.inventory.push_back(std::make_shared<Archer>());

            for (int turn = 1; turn <= 10; turn++) {
                clearScreen();
                drawField(field, player);

                std::cout << "Choose an action:\n";
                std::cout << "1. Play a card\n";
                std::cout << "2. Move character\n";
                std::cout << "Your choice: ";
                std::cin >> choice;

                if (choice == 1) {
                    clearScreen();
                    drawField(field, player);

                    player.printInventory();

                    std::cout << "Your choice: ";
                    std::cin >> choice;

                    clearScreen();
                    drawField(field, player);
                    int x,y;
                    std::cout << "Write the coordinates: ";
                    std::cin >> x >> y;
                    Coordinates coordinates(x,y);
                    field.addObject(player, coordinates, player.inventory[choice-1]);
                    player.mana -= 1;
                    player.inventory.erase(player.inventory.begin() + choice-1);
                    clearScreen();
                    drawField(field, player);
                    player.printInventory();
                    continue;

                } else if (choice == 2) {
                    clearScreen();
                    drawField(field, player);
                    std::cout << "Choose a character\n";
                    field.printCharactersOnGrid();
                    std::cin >> choice;
                    clearScreen();
                    drawField(field, player);
                    std::cout << "Write the coordinates: ";
                    int x, y;
                    std::cin >> x >> y;
                    Coordinates coordinates(x,y);
                    field.addObject(player, coordinates, field.charactersOnGrid[choice-1]);
                    field.deleteObject(choice);
                    clearScreen();
                    drawField(field, player);
                    
                    continue;
                } else {
                    std::cout << "Неверный выбор! Попробуйте снова.\n";
                }
                break;
            }
        } else if (choice == 2) {
            std::cout << "Выход из игры.\n";
            break;
        } else {
            std::cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    return 0;
}
