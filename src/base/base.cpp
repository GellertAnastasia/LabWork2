#include "base.h"

Base::Base() {
    setCell('B');
}

std::string Base::getName() const {
        return "Base (hp: "+ std::to_string(health)+")";
}
