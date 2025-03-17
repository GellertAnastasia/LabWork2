#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../include/constants.h"
#include "../player/player.h"
#include "../field/field.h"
#include "../fighter/fighter.h"
#include "../wizard/wizard.h"
#include "../archer/archer.h"
#include "../addHealth/addHealth.h"

void playCard(Player& player, Player& enemy, Field& field);
void moveCharacter(int choice, Player& player, Player& enemy, Field& field);
void attack(int choice, Player& player, Player& enemy, Field& field);
#endif
