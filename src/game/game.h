#ifndef GAME_H
#define GAME_H
#include "../playerTurn/playerTurn.h"
#include "../zone/zone.h"


class Game {
public:
    Field field;
    Zone zone1;
    Zone zone2;
    Player player1;
    Player player2;
    PlayerTurn playerTurn;
    
    Game();
    void start();
};

#endif
