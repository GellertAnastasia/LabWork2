#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include "../../include/constants.h"
#include "../character/character.h"

class Field
{
public:
    Field();
    std::vector<std::vector<Object>> grid;
    std::vector<std::vector<bool>> full;
    
    void addObject(int x, int y);
};

void drawField(Field field);

#endif
