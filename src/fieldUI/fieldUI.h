#ifndef FIELDUI_H
#define FIELDUI_H
#include <sstream> 
#include <iomanip> 
#include <algorithm>
#include "../field/field.h"
#include "../simbolsUI/simbolsUI.h"

class FieldUI {
private:
    Field& field;
    SimbolsUI simbolsUI;
public:
    FieldUI(Field& field);
    void draw(Player& player, Player& enemy);
};

#endif
