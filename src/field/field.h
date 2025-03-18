#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include <limits>
#include "../../include/constants.h"
#include "../player/player.h"
#include "../character/character.h"
#include "../fighter/fighter.h"
#include "../coordinates/coordinates.h"

void clearScreen();
void pause();

class Field
{
public:
    Field();
    std::vector<std::vector<std::shared_ptr<Object>>> grid;
    
    bool addCharacter(Player& player, std::shared_ptr<Coordinates> coordinates, std::shared_ptr<Object> character);
    void deleteObject(const std::shared_ptr<Coordinates>& coords, Player& player);
};

void drawField(Field& field, Player& player, Player& enemy);

#endif
