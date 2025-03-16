#include "player.h"

Player::Player(int Mana, int Money, int Color) : mana(Mana), money(Money), color(Color) {}

void Player::printInventory() {
    std::cout << "Inventory:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i]) {
            std::cout << i+1 << ". " << inventory[i]->getName() << "\n";
        } else {
            std::cout << i+1 << ". empty\n";
        }
    }
}

void Player::printCharactersOnGrid() {
    for (size_t i = 0; i < charactersOnGrid.size(); ++i) {
        if (charactersOnGrid[i]) {
            std::cout << i+1 << ". " << charactersOnGrid[i]->getName() << "\n";
        } else {
            std::cout << i+1 << ". empty\n";
        }
    }
}


