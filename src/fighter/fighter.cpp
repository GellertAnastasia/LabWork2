#include "fighter.h"

Fighter::Fighter() {
    setCell("⚔︎");
}

std::string Fighter::getName() const {
    if (getLocation() != nullptr) {
        return "Fighter" + getLocation()->get() + ": " + std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    } else {
        return "Fighter: " + std::to_string(health) + HEALTH + " " + std::to_string(power) + POWER;
    }
}
