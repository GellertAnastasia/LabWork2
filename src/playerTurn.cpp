#include "playerTurn.h"

PlayerTurn::PlayerTurn(Field& field) : field(field), cardsphase(field), actionsPhase(field) {}

void PlayerTurn::start(Player& player, Player& enemy)
{
    player.changeMana(2);
    int profit = field.processFarmsIncome(player);
    if (profit > 0)
    {
        std::cout << "Farm brought you money: " << profit << "\n";
        pause();
    }
    cardsphase.start(player, enemy);
    for (auto& c : player.charactersOnGrid)
    {
        if (c)
        {
            c->hasActed = false;
        }
        else
        {
            std::cerr << "Warning: nullptr detected in charactersOnGrid!" << std::endl;
        }
    }
    actionsPhase.start(player, enemy);
}

