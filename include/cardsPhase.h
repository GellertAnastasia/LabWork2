#ifndef CARDSPHASE_H
#define CARDSPHASE_H
#include <iostream>
#include "fieldUI.h"
#include "base.h"
#include "generateCard.h"

class CardsPhase
{
private:
    Field& field;
    FieldUI fieldUI;
public:
    CardsPhase(Field& field);
    void start(Field& field, Player& player, Player& enemy);
    void playCard(Field& field, Player& player, Player& enemy);
    void buyCard(Player& player);
};

#endif
