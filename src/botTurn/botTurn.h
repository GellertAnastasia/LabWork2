#ifndef BOTTURN_H
#define BOTTURN_H
#include "../aiController/aiController.h"

class BotTurn {
public:
    Field& field;
    AIController ai;
    
    BotTurn(Field& field, Player& player);
    void start(Player& player, Player& enemy, Field& field);
};

#endif
