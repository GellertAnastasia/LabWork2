#include "fighter.h"

Fighter::Fighter() {
    setCell("⚔︎");
}

std::string Fighter::getName() const {
        return "Fighter (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}
