#include "player.h"

Player::Player(int Mana, int Money) : mana(Mana), money(Money) {}

void Player::printInventory() {
    std::cout << "Инвентарь:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i]) {
            std::cout << i+1 << ". " << inventory[i]->getName() << "\n";
        } else {
            std::cout << i+1 << ". empty\n";
        }
    }
}
