#include "base.h"

std::string Base::getName() const {
        return "Base (hp: "+ std::to_string(health)+")";
}
