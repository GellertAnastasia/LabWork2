#include "farm.h"

Farm::Farm(Player* owner) : owner(owner) {
    setCell("⛃");
    setCost(3);
}

std::string Farm::getName() const {
    if (getLocation() != nullptr) {
        return "Farm" + getLocation()->get() + ": " + std::to_string(health) + HEALTH;
    } else {
        return "Farm: " + std::to_string(health) + HEALTH;
    }
}

int Farm::bringMoney() {
    if (owner) {
        owner->addMoney(profit);
        clearScreen();
        return profit;
    }
    return 0;
}

