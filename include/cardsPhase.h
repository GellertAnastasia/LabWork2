/**
 * @class CardsPhase
 * @brief Manages the card usage phase in the game cycle
 * 
 * Responsible for:
 * - Displaying card interaction interface
 * - Activating cards from inventory
 * - Purchasing new cards
 * - Interaction with game field and players
 */
#ifndef CARDSPHASE_H
#define CARDSPHASE_H

#include <iostream>
#include "fieldUI.h"
#include "base.h"
#include "generateCard.h"

class CardsPhase
{
private:
    Field& field;       ///< Reference to the game field
    FieldUI fieldUI;    ///< Field rendering interface

public:
    /**
     * @brief Constructor, initializes field binding
     * @param field Game field for interaction
     */
    CardsPhase(Field& field);

    /**
     * @brief Main card usage phase cycle
     * @param player Active player
     * @param enemy Target player for effects
     */
    void start(Player& player, Player& enemy);

    /**
     * @brief Logic for activating card from inventory
     * @param player Player activating the card
     * @param enemy Target player for effects
     */
    void playCard(Player& player, Player& enemy);

    /**
     * @brief Purchasing random card with in-game currency
     * @param player Player making the purchase
     * @warning Requires 3 units of money
     */
    void buyCard(Player& player);
};

#endif
