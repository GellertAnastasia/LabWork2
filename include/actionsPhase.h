/**
 * @class ActionsPhase
 * @brief Manages the action phase of player characters
 * 
 * Handles movement, attacks, and interaction with the game field.
 * Coordinates game state updates through Field and FieldUI objects.
 */
#ifndef ACTIONSPHASE_H
#define ACTIONSPHASE_H
#include "fieldUI.h"
#include "wizard.h"

class ActionsPhase
{
private:
    Field& field;       ///< Reference to the game field
    FieldUI fieldUI;    ///< Interface for rendering the field

public:
    /**
     * @brief Constructor initializes field binding
     * @param field Reference to the game field
     */
    ActionsPhase(Field& field);

    /**
     * @brief Starts the action phase for the current player
     * @param player Active player
     * @param enemy Enemy player
     */
    void start(Player& player, Player& enemy);

    /**
     * @brief Executes character movement
     * @param choice Selected character index (1-based)
     * @param player Player whose character is moving
     * @param enemy Enemy player
     * @return true if movement was successfully executed
     */
    bool moveCharacter(size_t choice, Player& player, Player& enemy);

    /**
     * @brief Executes attack on selected target
     * @param choice Attacking character index (1-based)
     * @param player Player whose character is attacking
     * @param enemy Attack target
     * @return true if attack was successfully executed
     */
    bool attack(size_t choice, Player& player, Player& enemy);
};

#endif
