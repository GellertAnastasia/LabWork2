#include "game.h"

Game::Game() : 
    zone1(0, 9, 6, 9),
    zone2(0, 9, 0, 3),
    player1(5, 2, 94, zone1),
    player2(5, 2, 32, zone2),
    playerTurn(field)
{
    field.grid[9][4] = player1.base;
    field.grid[9][5] = player1.base;
    field.grid[0][4] = player2.base;
    field.grid[0][5] = player2.base;

    for(int i = 0; i < 2; i++) {
        player1.inventory.push_back(generateCard(&player1));
        player2.inventory.push_back(generateCard(&player2));
    }
}

void Game::start() {
    int turn = 0;
    while (player1.base->health > 0 && player2.base->health > 0) {
        turn += 1;
        if (turn % 2 == 1) {
            player1.inventory.push_back(generateCard(&player1));
            clearScreen();
            std::cout << "Turn player №1\n";
            pause();
            playerTurn.start(player1, player2, field);
        } else {
            player2.inventory.push_back(generateCard(&player2));
            clearScreen();
            std::cout << "Turn player №2\n";
            pause();
            playerTurn.start(player2, player1, field);
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
}
