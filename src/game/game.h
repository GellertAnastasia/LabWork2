#ifndef GAME_H
#define GAME_H
#include "../playerTurn/playerTurn.h"
#include "../botTurn/botTurn.h"
#include "../zone/zone.h"
#include "../endUI/endUI.h"

class Game {
public:
    Field field;
    Zone zone1;
    Zone zone2;
    Player player1;
    Player player2;
    PlayerTurn playerTurn;
    BotTurn botTurn;
    
    Game();
    void start();
    void startB();
};

#endif
