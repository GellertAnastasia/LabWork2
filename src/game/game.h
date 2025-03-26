#ifndef GAME_H
#define GAME_H
#include "../playerTurn/playerTurn.h"


class Game {
public:
    Field field;
    Player player1;
    Player player2;
    PlayerTurn playerTurn;
    
    Game();
    void start();
};

#endif
