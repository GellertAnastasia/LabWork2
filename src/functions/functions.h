#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <limits>
#include "../include/constants.h"
#include "../player/player.h"
#include "../field/field.h"
#include "../fighter/fighter.h"
#include "../wizard/wizard.h"
#include "../archer/archer.h"

void playCard(Player& player, Field& field);
void moveCharacter(int choice, Player& player, Field& field);
void attack(Player& player, Field& field);
void pause();
#endif
