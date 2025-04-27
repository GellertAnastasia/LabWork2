/**
 * @class Field
 * @brief Manages game field and object interactions
 * 
 * Contains a 2D grid for game objects placement and handles:
 * - New characters/buildings placement
 * - Object movement
 * - Object removal
 * - Economic operations (farm income)
 */
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
    /// 2D grid of game objects (HEIGHT x WIDTH)
    std::vector<std::vector<std::shared_ptr<Object>>> grid;

    /**
     * @brief Constructor creates HEIGHT x WIDTH field
     * @details Initializes all cells with nullptr
     */
    Field();

    /**
     * @brief Checks for empty cells in player's zone
     * @param player Player to check zone for
     * @return true if at least one empty cell exists
     */
    bool isEmpty(Player& player);

    /**
     * @brief Places new object on the field
     * @param player Object owner
     * @param coordinates Target coordinates (1-based)
     * @param character Object to place
     * @return true on successful placement
     * @throws logic_error If coordinates outside player's zone
     */
    bool placeNewCharacter(Player& player, 
                         const std::shared_ptr<Coordinates>& coordinates,
                         std::shared_ptr<Object> character);

    /**
     * @brief Moves object between cells
     * @param player Object owner
     * @param from Source coordinates (1-based)
     * @param to Target coordinates (1-based)
     * @return true on successful movement
     * @warning Doesn't validate movement rules for the object
     */
    bool moveCharacter(Player& player,
                      const std::shared_ptr<Coordinates>& from,
                      std::shared_ptr<Coordinates>& to);

    /**
     * @brief Removes object from field
     * @param coords Object coordinates (1-based)
     * @param player Object owner
     * @post Object removed from grid and player's characters list
     */
    void deleteObject(const std::shared_ptr<Coordinates>& coords,
                     Player& player);

    /**
     * @brief Processes income from all player's farms
     * @param player Target player
     * @return Total income for the turn
     */
    int processFarmsIncome(Player& player);
};

#endif
