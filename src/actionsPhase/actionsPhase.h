#ifndef ACTIONSPHASE_H
#define ACTIONSPHASE_H
#include "../fieldUI/fieldUI.h"

class ActionsPhase {
private:
    Field& field;
    FieldUI fieldUI;
public:
    ActionsPhase(Field& field);
    void start(Field& field, Player& player, Player& enemy);
    void moveCharacter(size_t choice, Player& player, Player& enemy, Field& field);
    void attack(size_t choice, Player& player, Player& enemy, Field& field);
};

#endif
