/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @class Game
 * @brief Core game management class
 * 
 * Coordinates interaction between all game components:
 * - Player and bot initialization
 * - Turn queue management
 * - Victory condition checking
 * - Final screen triggering
 */
#ifndef GAME_H
#define GAME_H

#include "playerTurn.h"
#include "botTurnEasy.h"
#include "botTurnNormal.h"
#include "zone.h"
#include "endUI.h"

class Game
{
public:
    Field field;            ///< Game field
    Zone zone1;             ///< Player 1 control zone (bottom area)
    Zone zone2;             ///< Player 2 control zone (top area)
    Player player1;         ///< Main player (human)
    Player player2;         ///< Second player (human or bot)
    PlayerTurn playerTurn;  ///< Human player turn controller
    BotTurnEasy botTurnEasy;        ///< AI turn controller
    BotTurnNormal botTurnNormal;

    /**
     * @brief Constructor initializes game objects
     * @details Performs:
     * 1. Player zone configuration
     * 2. Base placement on field
     * 3. Initial card distribution
     */
    Game();

    /**
     * @brief Starts player vs player game (PvP)
     * @algorithm
     * - Alternating player turns
     * - Base status check after each turn
     * - Game end when base is destroyed
     */
    void startA();

    /**
     * @brief Starts player vs AI game (PvE)
     * @algorithm
     * - Alternating player/AI turns
     * - Automated AI decision making
     * - Victory condition processing
     */
    void startB1();
    void startB2();
};

#endif
