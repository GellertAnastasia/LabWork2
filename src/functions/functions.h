#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../include/constants.h"
#include "../player/player.h"
#include "../field/field.h"
#include "../fighter/fighter.h"
#include "../wizard/wizard.h"
#include "../archer/archer.h"

void playCard(Player& player, Player& enemy, Field& field);
void moveCharacter(size_t choice, Player& player, Player& enemy, Field& field);
void attack(size_t choice, Player& player, Player& enemy, Field& field);
#endif
