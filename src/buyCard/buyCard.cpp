#include "buyCard.h"

void buyCard(Player& player) {
    if (player.money >= 1) {
        player.money -= 1;
        auto character = generateCard(&player);
        player.inventory.push_back(character);
        std::cout << character->getName() << " added to inventory\n";
    } else {
       std::cout << "not enough money\n";
    }
}
