#include "farm.h"

Farm::Farm(Player* owner) : owner(owner) {
    setCell('M');
}

std::string Farm::getName() const {
        return "Farm (hp: "+ std::to_string(health)+")";
}

int Farm::bringMoney() {
    if (owner) {
        owner->addMoney(profit);
        clearScreen();
        return profit;
    }
    return 0;
}

