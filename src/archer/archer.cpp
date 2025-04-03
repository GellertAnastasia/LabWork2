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
        return "Archer (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}


