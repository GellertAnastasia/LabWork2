/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @file func.h
 * @brief General-purpose utility functions
 * 
 * Contains utilities for console operations, coordinate validation, and game field state checks.
 */

#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <algorithm>
#include <vector>s
#include <memory>
#include <limits>
#include "coordinates.h"
#include "object.h"
#include "constants.h"

/**
 * @brief Clears console using ANSI escape codes
 * @details Sends "\033c" sequence for full screen clear
 */
void clearScreen();

/**
 * @brief Pauses execution until Enter is pressed
 * @warning Blocks execution thread until user input
 * @note Clears input buffer before waiting
 */
void pause_();

/**
 * @brief Checks if coordinates are within game field bounds
 * @param coordinates Coordinates to check (1-based)
 * @return true if 1 ≤ X ≤ WIDTH and 1 ≤ Y ≤ HEIGHT
 */
bool isWithinBounds(std::shared_ptr<Coordinates> coordinates);

/**
 * @brief Checks if cell is available for object placement
 * @param coordinates Coordinates to check (1-based)
 * @param grid Reference to game field
 * @return true if:
 * - Cell is unoccupied (grid[y][x] == nullptr)
 * - Not a special locked cell (bases)
 * @note Special locked cells:
 * - (5,1), (6,1) - Player 1 base
 * - (5,10), (6,10) - Player 2 base
 */
bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<std::shared_ptr<Object>>> grid);

#endif
