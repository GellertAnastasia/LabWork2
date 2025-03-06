#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include "../../include/constants.h"
#include "../player/player.h"
#include "../character/character.h"
#include "../fighter/fighter.h"
#include "../coordinates/coordinates.h"

class Field
{
public:
    Field();
    std::vector<std::vector<Object>> grid;
    std::vector<std::vector<bool>> full;
    
    std::vector<std::shared_ptr<Object>> objectsOnGrid;
    std::vector<Coordinates> place;
    
    void addObject(Coordinates coordinates);
    void printObjectsOnGrid();
};

void drawField(Field field, Player player);

#endif
