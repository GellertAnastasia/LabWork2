#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include <limits>
#include "constants.h"
#include "character.h"
#include "fighter.h"
#include "farm.h"
#include "coordinates.h"
#include "player.h"

class Field
{
public:
    Field();
    std::vector<std::vector<std::shared_ptr<Object>>> grid;

    bool isEmpty(Player& player);
    bool placeNewCharacter(Player& player, const std::shared_ptr<Coordinates>& coordinates, std::shared_ptr<Object> character);
    bool moveCharacter(Player& player, const std::shared_ptr<Coordinates>& from, std::shared_ptr<Coordinates>& to);
    void deleteObject(const std::shared_ptr<Coordinates>& coords, Player& player);
    int processFarmsIncome(Player& player);
};

#endif
