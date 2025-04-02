#include "game/game.h"
#include "ui/ui.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        printTitle();
        printMenu();
        std::cout << "Your choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

