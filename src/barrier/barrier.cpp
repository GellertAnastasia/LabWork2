#include "barrier.h"

Barrier::Barrier() {
    setCell("≡");
}

std::string Barrier::getName() const {
        return "Barrier (hp: "+ std::to_string(health)+")";
}
