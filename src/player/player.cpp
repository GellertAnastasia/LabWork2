#include "player.h"

Player::Player(int Mana, int Money, int Color, const Zone& zone) 
	: mana(Mana), money(Money), color(Color), base(std::make_shared<Base>(Color)), zone(zone){}
/*
bool Player::isHuman() {
    return human;
}
void Player::setHuman(bool _human) {
    human = _human;
}*/

void Player::addMoney(int profit) {
    money += profit;
}

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


