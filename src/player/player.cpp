#include "player.h"

Player::Player(int Mana, int Money, int Color, const Zone& zone) 
	: mana(Mana), money(Money), color(Color), base(std::make_shared<Base>(Color)), zone(zone){}

int Player::getMana() const {
    return mana;
}
int Player::getMoney() const {
    return money;
}
int Player::getColor() const {
    return color;
}

bool Player::isInsideZone(int x, int y) {
    return (x >= zone.getMinX() && 
        x <= zone.getMaxX() && 
        y >= zone.getMinY() && 
        y <= zone.getMaxY());
}

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

void Player::changeMana(int points) {
    mana += points;
}
