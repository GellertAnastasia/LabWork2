#include "barrier.h"

Barrier::Barrier() {
    setCell("≡");
}

std::string Barrier::getName() const {
    if (getLocation() != nullptr) {
        return "Barrier" + getLocation()->get() + ": " + std::to_string(health) + HEALTH;
    } else {
        return "Barrier: " + std::to_string(health) + HEALTH;
    }
}
