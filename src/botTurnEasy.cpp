/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "botTurnEasy.h"

BotTurnEasy::BotTurnEasy(Field& field, Player& player) : field(field), ai(player, field) {}

void BotTurnEasy::start(Player& player, Player& enemy)
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
