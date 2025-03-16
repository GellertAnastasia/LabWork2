#include "object.h"

void Object::setCell(char value) {
    cell = value;
}

char Object::getCell() const {
    return cell;
}

void Object::setColor(int value) {
    color = value;
}

int Object::getColor() const {
    return color;
}
