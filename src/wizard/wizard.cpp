#include "wizard.h"

Wizard::Wizard() {
    setCell('W');
}

std::string Wizard::getName() const {
     return "Wizard (hp: "+ std::to_string(health) +", power: "+ std::to_string(power) +")";
}
