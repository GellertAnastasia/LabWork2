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
            auto base1 = std::make_shared<Base>();
            auto base2 = std::make_shared<Base>();
            base1->setColor(34);
            base2->setColor(31);
            field.grid[9][4] = base1;
            field.grid[9][5] = base1;
            field.grid[0][4] = base2;
            field.grid[0][5] = base2;
            Player player1(5,2, base1->getColor(), base1);
            Player player2(5,2, base2->getColor(), base2);
            for (int i = 0; i<2; i++) {
                player1.inventory.push_back(generateCard());
                player2.inventory.push_back(generateCard());
            }
            int turn = 0;
            while (player1.base->health > 0 && player2.base->health > 0) {
                turn += 1;
                if (turn % 2 == 1) {
                    player1.inventory.push_back(generateCard());
                    clearScreen();
                    std::cout << "Turn player №1\n";
                    pause();
                    playerTurn(player1, player2, field);
                } else {
                    player2.inventory.push_back(generateCard());
                    clearScreen();
                    std::cout << "Turn player №2\n";
                    pause();
                    playerTurn(player2, player1, field);
                }
            }
            
            clearScreen();
            std::cout << "Game over\n";
            if (player1.base->health <= 0) {
                std::cout << "Winner:\033["<< player2.color <<"m Player\033[0m\n";
                pause();
            } else {
                std::cout << "Winner:\033["<< player1.color <<"m Player\033[0m\n";
                pause();
            }
            
        } else if (choice == 2) {
            std::cout << "Exit...\n";
            break;
        } else {
            continue;
        }
    }

    return 0;
}

