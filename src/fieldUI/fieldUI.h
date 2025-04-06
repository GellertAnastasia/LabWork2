#ifndef FIELDUI_H
#define FIELDUI_H
#include <sstream> 
#include <iomanip> 
#include <algorithm>
#include "../../include/constants.h"
#include "../field/field.h"

class FieldUI {
private:
    Field& field;
public:
    FieldUI(Field& field);
    void draw(Player& player, Player& enemy);
};

#endif
