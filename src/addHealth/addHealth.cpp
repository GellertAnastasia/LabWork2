#include "addHealth.h"

void addHealth(std::shared_ptr<Object> object, int hp) {
    object->health += hp;
}
void addHealth(Base& base, int hp) {
    base.health += hp;
}
