/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @file playingCards.h
 * @brief Class for managing playing cards during a turn
 * 
 * Handles the logic of placing characters and applying improvements.
 */

#ifndef PLAYINGCARDS_H
#define PLAYINGCARDS_H

#include <iostream>
#include <memory>
#include "fieldUI.h"
#include "generateCard.h"

/**
 * @class PlayingCards
 * @brief Orchestrator for interacting with playing cards
 * 
 * Manages:
 * - Placing characters on the field
 * - Applying improvements to characters
 * - Interacting with the user via FieldUI
 */
class PlayingCards {
public:
    /**
     * @brief Constructor initializes the game context
     * @param player The active player
     * @param enemy The opponent
     * @param field The game field
     * @param fieldUI The display interface
     */
    PlayingCards(Player& player, Player& enemy, Field& field, FieldUI& fieldUI);

    /**
     * @brief Places a character on the field
     * @param object The character object to place
     * @return true if placement was successful
     * 
     * @algorithm
     * 1. Check available mana
     * 2. Check for free space in the zone
     * 3. Interactive coordinate selection
     * 4. Place the object
     */
    bool characters(std::shared_ptr<Object> object);

    /**
     * @brief Applies an improvement to a character
     * @param improvement The improvement to apply
     * @return true if application was successful
     * 
     * @throws logic_error If there are no available characters
     */
    bool improvements(std::shared_ptr<Improvement> improvement);

private:
    Player& player;     ///< Reference to the active player
    Player& enemy;      ///< Reference to the opponent
    Field& field;       ///< Reference to the game field
    FieldUI& fieldUI;   ///< Reference to the display interface

    /**
     * @brief Reads and validates coordinates
     * @param[out] x The read X-coordinate
     * @param[out] y The read Y-coordinate
     * @return true if the coordinates are valid
     * 
     * @note Repeats the request in case of incorrect input
     */
    bool readCoordinates(int& x, int& y);
};

#endif
