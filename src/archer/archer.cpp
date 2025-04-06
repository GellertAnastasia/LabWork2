#include "archer.h"

Archer::Archer() {
    setCell("➶");
    setDirectionOfMove({
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    });
    setDirectionOfAttack({
        {1, 1},
    });
}

std::string Archer::getName() const {
    if (getLocation() != nullptr) {
        return "Archer" + getLocation()->get() + ": "+ std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    } else {
        return "Archer: "+ std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    }
}


