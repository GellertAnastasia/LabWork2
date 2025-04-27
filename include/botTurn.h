/**
 * @class BotTurn 
 * @brief Manages the complete AI player turn cycle
 *
 * Coordinates:
 * - Resource allocation
 * - Character state reset
 * - AI decision-making logic
 */
#ifndef BOTTURN_H
#define BOTTURN_H
#include "aiController.h"

class BotTurn
{
public:
    Field& field;       ///< Reference to the game field
    AIController ai;    ///< AI controller for decision making

    /**
     * @brief Constructor initializes the bot turn system
     * @param field Game field
     * @param player AI player taking the turn
     */
    BotTurn(Field& field, Player& player);

    /**
     * @brief Executes the complete turn cycle
     * @param player Active AI player
     * @param enemy Opponent player
     */
    void start(Player& player, Player& enemy);
};

#endif
