#ifndef ACTIONSPHASE_H
#define ACTIONSPHASE_H
#include "fieldUI.h"
#include "wizard.h"

class ActionsPhase
{
private:
    Field& field;
    FieldUI fieldUI;
public:
    ActionsPhase(Field& field);
    void start(Player& player, Player& enemy);
    bool moveCharacter(size_t choice, Player& player, Player& enemy);
    bool attack(size_t choice, Player& player, Player& enemy);
};

#endif
