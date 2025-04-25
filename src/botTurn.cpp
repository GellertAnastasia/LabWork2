#include "botTurn.h"

BotTurn::BotTurn(Field& field, Player& player) : field(field), ai(player, field) {}

void BotTurn::start(Player& player, Player& enemy)
{
    player.changeMana(2);
    field.processFarmsIncome(player);
    for(auto& c : player.charactersOnGrid)
    {
        c->hasActed = false;
    }
    ai.makeMove(enemy);
    ai.makeActionsMove(enemy);
}
