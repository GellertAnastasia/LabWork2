#include "playerTurn.h"

PlayerTurn::PlayerTurn(Field& field) : field(field), cardsphase(field), actionsPhase(field){} 

void PlayerTurn::start(Player& player, Player& enemy, Field& field) {
    int profit = field.processFarmsIncome(player);
    if (profit > 0) {
        std::cout << "Farm brought you money: " << profit << "\n";
        pause();
    }
    cardsphase.start(field, player, enemy);
for (auto& c : player.charactersOnGrid) {
    if (c) { // Проверка на валидность указателя
        c->hasActed = false;
    } else {
        std::cerr << "Warning: nullptr detected in charactersOnGrid!" << std::endl;
    }
}
    actionsPhase.start(field, player, enemy);
}

