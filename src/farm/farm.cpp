#include "farm.h"

Farm::Farm(Player* owner) : owner(owner) {
    setCell('M');
}

std::string Farm::getName() const {
        return "Farm (hp: "+ std::to_string(health)+")";
}

void Farm::bringMoney() {
    if (owner) {
        owner->addMoney(profit);
        clearScreen();
        std::cout << "Farm brought you money: " << profit << "\n";
        pause();
    }
}

