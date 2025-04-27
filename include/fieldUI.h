/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @class FieldUI
 * @brief Class for graphical representation of the game field
 * 
 * Provides visualization for:
 * - Game field grid with objects
 * - Player statistics (base health, mana, money)
 * - Coordinate system
 */
#ifndef FIELDUI_H
#define FIELDUI_H

#include <sstream>
#include <iomanip>
#include <algorithm>
#include "constants.h"
#include "field.h"

class FieldUI
{
private:
    Field& field; ///< Reference to game field for rendering

public:
    /**
     * @brief Constructor initializes field binding
     * @param field Reference to Field object for visualization
     */
    FieldUI(Field& field);

    /**
     * @brief Renders complete game state
     * @param player Left player (current)
     * @param enemy Right player (opponent)
     * @details Performs:
     * 1. Screen clearing
     * 2. Coordinate grid rendering
     * 3. Field objects visualization
     * 4. Player statistics display
     */
    void draw(Player& player, Player& enemy);
};

#endif
