/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @file aiControllerEasy.h
 * @brief Header for AIControllerEasy class - basic AI implementation
 * 
 * Defines the AI controller for easy difficulty that handles:
 * - Card purchasing and playing
 * - Character movement and attacks
 * - Basic decision making
 */

#ifndef AICONTROLLEREASY_H
#define AICONTROLLEREASY_H

#include <cstdlib>
#include <ctime>
#include <climits>
#include "player.h"
#include "field.h"
#include "fieldUI.h"
#include "generateCard.h"
#include "improvement.h"

/**
 * @class AIControllerEasy
 * @brief Basic AI controller for easy difficulty
 * 
 * Implements fundamental AI behaviors that can be extended by more advanced controllers.
 * Uses random selection for most decisions with basic targeting logic.
 */
class AIControllerEasy
{
public:
    /**
     * @brief Constructs an AIControllerEasy instance
     * @param player Reference to the controlled player
     * @param field Reference to the game field
     * 
     * Initializes random number generator and stores references to game objects.
     */
    AIControllerEasy(Player& player, Field& field);

    /**
     * @brief Executes the main AI turn logic
     * @param enemy Reference to the enemy player
     * 
     * Handles card purchasing and playing during the AI's turn.
     */
    void makeMove(Player& enemy);

    /**
     * @brief Manages character actions during turn
     * @param enemy Reference to the enemy player
     * 
     * Processes attacks and movements for all AI-controlled characters.
     */
    void makeActionsMove(Player& enemy);

    /**
     * @brief Attempts an attack with specified character
     * @param attacker The attacking character
     * @param enemy The enemy player
     * @return True if attack was successful
     */
    bool aiAttack(std::shared_ptr<Character> attacker, Player& enemy);

    /**
     * @brief Purchases a random card if possible
     */
    void buyRandomCard();

    /**
     * @brief Plays a random card from inventory
     * @param enemy The enemy player
     */
    void playRandomCard(Player& enemy);
    
protected:
    /**
     * @brief Moves a character according to basic AI logic
     * @param character The character to move
     * @param enemy The enemy player
     * @return True if movement was successful
     */
    virtual bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy);

    /**
     * @brief Selects best target for an attacker
     * @param attacker The attacking character
     * @param enemy The enemy player
     * @return Shared pointer to selected target
     */
    virtual std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy);
    
    /**
     * @brief Determines if AI should buy a card
     * @return True if card should be purchased
     */
    bool shouldBuyCard() const;

    /**
     * @brief Plays a card according to AI logic
     * @param enemy The enemy player
     */
    virtual void playCard(Player& enemy);

    /**
     * @brief Determines if AI should play a card
     * @return True if card should be played
     */
    virtual bool shouldPlayCard() const;

    Player& player;     ///< Reference to the AI-controlled player
    Field& field;       ///< Reference to the game field
    FieldUI fieldUI;    ///< Field rendering interface
};

#endif
