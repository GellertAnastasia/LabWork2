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
    std::vector<std::vector<std::shared_ptr<Object>>> grid;
    std::vector<std::vector<bool>> full;
    
    std::vector<std::shared_ptr<Character>> charactersOnGrid;
    std::vector<std::shared_ptr<Coordinates>> place;
    
    void addCharacter(Player player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Character> character);
    void printCharactersOnGrid();
    void deleteObject(int choice);
};

void drawField(Field field, Player player);

#endif
