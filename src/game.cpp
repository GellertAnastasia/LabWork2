/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "game.h"

Game::Game() :
    zone1(1, 10, 7, 10),
    zone2(1, 10, 1, 4),
    player1(3, 3, 94, zone1),
    player2(5, 3, 32, zone2),
    playerTurn(field),
    botTurnEasy(field, player2),
    botTurnNormal(field, player2)
{
    field.grid[9][4] = player1.base;
    field.grid[9][5] = player1.base;
    field.grid[0][4] = player2.base;
    field.grid[0][5] = player2.base;

    for(int i = 0; i < 2; i++)
    {
        player1.inventory.push_back(generateCard(&player1));
        player2.inventory.push_back(generateCard(&player2));
    }
}

void Game::startA()
{
    int turn = 0;
    while (player1.base->getHealth() > 0 && player2.base->getHealth() > 0)
    {
        turn += 1;
        if (turn % 2 == 1)
        {
            player1.inventory.push_back(generateCard(&player1));
            clearScreen();
            std::cout << "Turn player №1\n";
            pause_();
            playerTurn.start(player1, player2);
        }
        else
        {
            player2.inventory.push_back(generateCard(&player2));
            clearScreen();
            std::cout << "Turn player №2\n";
            pause_();
            playerTurn.start(player2, player1);
        }
    }

    if (player1.base->getHealth() <= 0)
    {
        showGameOverScreen("\033["+ std::to_string(player2.getColor()) +"m Player\033[0m\n");
    }
    else
    {
        showGameOverScreen("\033["+ std::to_string(player1.getColor()) +"m Player\033[0m\n");
    }
}

void Game::startB1()
{
    int turn = 0;
    while (player1.base->getHealth() > 0 && player2.base->getHealth() > 0)
    {
        turn += 1;
        if (turn % 2 == 1)
        {
            player1.inventory.push_back(generateCard(&player1));
            clearScreen();
            std::cout << "Turn player\n";
            pause_();
            playerTurn.start(player1, player2);
        }
        else
        {
            player2.inventory.push_back(generateCard(&player2));
            clearScreen();
            std::cout << "Turn bot\n";
            pause_();
            botTurnEasy.start(player2, player1);
        }
    }

    clearScreen();
    std::cout << "Game over\n";
    if (player1.base->getHealth() <= 0)
    {
        showGameOverScreen("\033["+ std::to_string(player2.getColor()) +"m Bot\033[0m\n");
    }
    else
    {
        showGameOverScreen("\033["+ std::to_string(player1.getColor()) +"m Player\033[0m\n");
    }
}

void Game::startB2()
{
    int turn = 0;
    while (player1.base->getHealth() > 0 && player2.base->getHealth() > 0)
    {
        turn += 1;
        if (turn % 2 == 1)
        {
            player1.inventory.push_back(generateCard(&player1));
            clearScreen();
            std::cout << "Turn player\n";
            pause_();
            playerTurn.start(player1, player2);
        }
        else
        {
            player2.inventory.push_back(generateCard(&player2));
            clearScreen();
            std::cout << "Turn bot\n";
            pause_();
            botTurnNormal.start(player2, player1);
        }
    }

    clearScreen();
    std::cout << "Game over\n";
    if (player1.base->getHealth() <= 0)
    {
        showGameOverScreen("\033["+ std::to_string(player2.getColor()) +"m Bot\033[0m\n");
    }
    else
    {
        showGameOverScreen("\033["+ std::to_string(player1.getColor()) +"m Player\033[0m\n");
    }
}
