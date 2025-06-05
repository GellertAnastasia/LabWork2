/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @file aiControllerNormal.h
 * @brief Header file for the AIControllerNormal class
 * 
 * This file contains the declaration of the AIControllerNormal class which implements
 * AI behavior for normal difficulty in the game. It inherits from AIControllerEasy
 * and provides more advanced decision-making capabilities.
 */

#ifndef AICONTROLLERNORMAL_H
#define AICONTROLLERNORMAL_H

#include "aiControllerEasy.h"

/**
 * @class AIControllerNormal
 * @brief AI controller for normal difficulty level
 *
 * This class implements AI behavior with more strategic decision-making than
 * the easy difficulty. It includes methods for target selection, movement,
 * and card playing with improved logic.
 */
class AIControllerNormal : public AIControllerEasy {
public:
    /**
     * @brief Constructs an AIControllerNormal instance
     * @param player Reference to the player controlled by this AI
     * @param field Reference to the game field
     */
    AIControllerNormal(Player& player, Field& field);
    
    /**
     * @brief Selects the best target for an attacker
     * @param attacker The attacking character
     * @param enemy The enemy player
     * @return Shared pointer to the best target object
     */
    std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy) override;
    
    /**
     * @brief Finds closest position to target from possible moves
     * @param possibleMoves List of possible move coordinates
     * @param target Target coordinates to move towards
     * @return Shared pointer to closest coordinates
     */
    std::shared_ptr<Coordinates> findClosestPositionTo(std::vector<std::shared_ptr<Coordinates>>& possibleMoves, std::shared_ptr<Coordinates> target);
    
    /**
     * @brief Finds nearest enemy character
     * @param unit The unit to find enemies for
     * @param enemy The enemy player
     * @return Shared pointer to nearest enemy character
     */
    std::shared_ptr<Character> findNearestEnemy(std::shared_ptr<Character> unit, Player& enemy);
    
    /**
     * @brief Moves character according to AI logic
     * @param character Character to move
     * @param enemy Enemy player
     * @return True if move was successful
     */
    bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy) override;
    
    /**
     * @brief Determines if AI should play a card
     * @return True if card should be played
     */
    bool shouldPlayCard() const override;
    
    /**
     * @brief Attempts to place a unit card
     * @param unitCard Unit card to place
     * @param enemy Enemy player
     * @return True if placement was successful
     */
    bool tryPlaceUnit(std::shared_ptr<Object> unitCard, Player& enemy);
    
    /**
     * @brief Gets strongest character from player
     * @param player Player to check
     * @return Shared pointer to strongest character
     */
    std::shared_ptr<Character> getStrongestCharacter(Player& player);
    
    /**
     * @brief Plays a card according to AI logic
     * @param enemy Enemy player
     */
    void playCard(Player& enemy) override;
    
    /**
     * @brief Safely applies improvement to target
     * @param imp Improvement to apply
     * @param target Target character
     */
    void safelyApplyImprovement(std::shared_ptr<Improvement> imp, std::shared_ptr<Character> target);
};

#endif
