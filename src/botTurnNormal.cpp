/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

#include "botTurnNormal.h"


BotTurnNormal::BotTurnNormal(Field& field, Player& player) : field(field), ai(player, field) {}

void BotTurnNormal::start(Player& player, Player& enemy)
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
