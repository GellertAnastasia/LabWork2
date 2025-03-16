#include "functions/functions.h"
#include "playerTurn/playerTurn.h"
#include "generateCard/generateCard.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
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
            Player player1(5,2, 34);
            Player player2(5,2, 31);
            for (int i = 0; i<2; i++) {
                player1.inventory.push_back(generateCard());
                player2.inventory.push_back(generateCard());
            }
            for (int turn = 1; turn <= 10; turn++) {
                if (turn % 2 == 1) {
                    player1.inventory.push_back(generateCard());
                    clearScreen();
                    std::cout << "Turn player №1\n";
                    pause();
                    playerTurn(player1, field);
                } else {
                    player2.inventory.push_back(generateCard());
                    clearScreen();
                    std::cout << "Turn player №2\n";
                    pause();
                    playerTurn(player2, field);
                }
            }
        } else if (choice == 2) {
            std::cout << "Exit...\n";
            break;
        } else {
            std::cout << "Error. Try again\n";
            pause();
            continue;
        }
    }

    return 0;
}

