#include "game/game.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        clearScreen();

        std::cout << "Меню игры:\n";
        std::cout << "1. Start\n";
        std::cout << "2. Rules\n";
        std::cout << "3. Exit\n";
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            Game game;
            game.start();
        } else if (choice == 2) {
            std::cout << "Rules\n";
            //printRules();
            break;
        } else if (choice == 3) {
            std::cout << "Exit...\n";
            break;
        } else {
            continue;
        }
    }

    return 0;
}

