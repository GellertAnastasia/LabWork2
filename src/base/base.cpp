#include "base.h"

Base::Base(int value) {
    setCell("☖");
    setColor(value);
}

std::string Base::getName() const {
    if (getLocation() != nullptr) {
        return "Base" + getLocation()->get() + ": " + std::to_string(health) + HEALTH;
    } else {
        return "Base: " + std::to_string(health) + HEALTH;
    }
}
