/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @class BotTurn 
 * @brief Manages the complete AI player turn cycle
 *
 * Coordinates:
 * - Resource allocation
 * - Character state reset
 * - AI decision-making logic
 */
#ifndef BOTTURNEASY_H
#define BOTTURNEASY_H
#include "aiControllerEasy.h"

class BotTurnEasy
{
public:
    Field& field;       ///< Reference to the game field
    AIControllerEasy ai;    ///< AI controller for decision making

    /**
     * @brief Constructor initializes the bot turn system
     * @param field Game field
     * @param player AI player taking the turn
     */
    BotTurnEasy(Field& field, Player& player);

    /**
     * @brief Executes the complete turn cycle
     * @param player Active AI player
     * @param enemy Opponent player
     */
    void start(Player& player, Player& enemy);
};

#endif
