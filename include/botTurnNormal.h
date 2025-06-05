/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/
/**
 * @file botTurnNormal.h
 * @brief Header file for the BotTurnNormal class
 * 
 * This file contains the declaration of the BotTurnNormal class which manages
 * the normal AI player's turn sequence and actions.
 */

#ifndef BOTTURNNORMAL_H
#define BOTTURNNORMAL_H

#include "aiControllerNormal.h"

/**
 * @class BotTurnNormal
 * @brief Manages normal AI player's turn sequence
 *
 * This class handles the turn flow for a normal difficulty AI player,
 * including mana management, character actions, and AI decision making.
 */
class BotTurnNormal
{
public:
    Field& field;               ///< Reference to the game field
    AIControllerNormal ai;      ///< AI controller for normal difficulty
    
    /**
     * @brief Constructs a BotTurnNormal instance
     * @param field Reference to the game field
     * @param player Reference to the AI-controlled player
     */
    BotTurnNormal(Field& field, Player& player);
    
    /**
     * @brief Executes the AI player's turn
     * @param player Reference to the AI-controlled player
     * @param enemy Reference to the enemy player
     * 
     * Manages the full turn sequence including:
     * - Mana replenishment
     * - Farm income processing
     * - Character action reset
     * - AI decision making
     */
    void start(Player& player, Player& enemy);
};

#endif
