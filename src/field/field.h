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
    
    std::vector<std::shared_ptr<Object>> charactersOnGrid;
    std::vector<Coordinates> place;
    
    void addObject(Player player, Coordinates coordinates, std::shared_ptr<Object> object);
    void printCharactersOnGrid();
    void deleteObject(int choice);
};

void drawField(Field field, Player player);

#endif
