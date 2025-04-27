/**
 * @file playerTurn.h
 * @brief Management of human player's full turn
 * 
 * Coordinates the sequence of actions during a turn:
 * 1. Mana and income allocation
 * 2. Card usage phase
 * 3. Character actions phase
 */

#ifndef PLAYERTURN_H
#define PLAYERTURN_H

#include "cardsPhase.h"
#include "actionsPhase.h"

/**
 * @class PlayerTurn
 * @brief Player turn orchestrator
 * 
 * Manages all turn phases:
 * - Resource initialization
 * - Card interactions
 * - Character actions
 */
class PlayerTurn {
public:
    Field& field;           ///< Reference to game field
    CardsPhase cardsphase;   ///< Card phase controller
    ActionsPhase actionsPhase; ///< Action phase controller

    /**
     * @brief Constructor initializes turn components
     * @param field Reference to game field
     */
    PlayerTurn(Field& field);

    /**
     * @brief Executes full player turn cycle
     * @param player Active player
     * @param enemy Opponent
     * 
     * Execution sequence:
     * 1. Mana allocation (+2)
     * 2. Farm income collection
     * 3. Card usage phase
     * 4. Character state reset
     * 5. Character actions phase
     */
    void start(Player& player, Player& enemy);
};

#endif
