/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @class AIController
 * @brief Controls the artificial intelligence for a player
 * 
 * Implements logic for automatic actions:
 * - Buying and using cards
 * - Character movement
 * - Attacking enemy targets
 */
#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include <cstdlib>
#include <ctime>
#include <climits>
#include "player.h"
#include "field.h"
#include "fieldUI.h"
#include "generateCard.h"
#include "improvement.h"

class AIController
{
public:
    /**
     * @brief Constructor, initializes the AI player
     * @param player Reference to the controlled player
     * @param field Reference to the game field
     * @note Initializes the random number generator
     */
    AIController(Player& player, Field& field);

    /// Main method for executing AI turn
    void makeMove(Player& enemy);

    /**
     * @brief Character action logic
     * @details Sequentially executes attacks and movements
     */
    void makeActionsMove(Player& enemy);

private:
    /// Internal helper methods
    bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy);
    bool aiAttack(std::shared_ptr<Character> attacker, Player& enemy);
    std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy);
    
    /// Card handling logic
    void playRandomCard(Player& enemy);
    void buyRandomCard();
    bool shouldBuyCard() const;
    bool shouldPlayCard() const;

    Player& player;     ///< AI-controlled player
    Field& field;       ///< Game field
    FieldUI fieldUI;    ///< Field rendering interface
};

#endif
