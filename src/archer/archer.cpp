#include "archer.h"

Archer::Archer() {
    setCell('A');
}

std::string Archer::getName() const {
        return "Archer (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}


