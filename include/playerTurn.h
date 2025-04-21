#ifndef PLAYERTURN_H
#define PLAYERTURN_H
#include "cardsPhase.h"
#include "actionsPhase.h"

class PlayerTurn
{
public:
    Field& field;
    CardsPhase cardsphase;
    ActionsPhase actionsPhase;

    PlayerTurn(Field& field);
    void start(Player& player, Player& enemy, Field& field);
};

#endif
