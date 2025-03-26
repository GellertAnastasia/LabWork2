#include "playerTurn.h"

PlayerTurn::PlayerTurn(Field& field) : field(field), cardsphase(field), actionsPhase(field){} 

void PlayerTurn::start(Player& player, Player& enemy, Field& field) {

    cardsphase.start(field, player, enemy);
    for(auto& c : player.charactersOnGrid) {
        c->hasActed = false;
    }
    actionsPhase.start(field, player, enemy);
}

