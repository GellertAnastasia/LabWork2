#include "playerTurn.h"

PlayerTurn::PlayerTurn(Field& field) : field(field), cardsphase(field), actionsPhase(field){} 

void PlayerTurn::start(Player& player, Player& enemy, Field& field) {
    int profit = field.processFarmsIncome(player);
    if (profit > 0) {
        std::cout << "Farm brought you money: " << profit << "\n";
        pause();
    }
    cardsphase.start(field, player, enemy);
    for(auto& c : player.charactersOnGrid) {
        c->hasActed = false;
    }
    actionsPhase.start(field, player, enemy);
}

