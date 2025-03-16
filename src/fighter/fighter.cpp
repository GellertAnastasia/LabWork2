#include "fighter.h"

Fighter::Fighter() {
    setCell('F');
}

std::string Fighter::getName() const {
        return "Fighter (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}
