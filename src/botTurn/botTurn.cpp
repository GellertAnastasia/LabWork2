#include "botTurn.h"

BotTurn::BotTurn(Field& field, Player& player) : field(field), ai(player, field) {}

void BotTurn::start(Player& player, Player& enemy, Field& field) {
    field.processFarmsIncome(player);
    ai.makeMove(field, enemy);
    ai.makeActionsMove(field, enemy);
}
