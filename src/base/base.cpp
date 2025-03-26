#include "base.h"

Base::Base(int value) {
    setCell('B');
    setColor(value);
}

std::string Base::getName() const {
        return "Base (hp: "+ std::to_string(health)+")";
}
