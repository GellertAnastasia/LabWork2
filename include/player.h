/**
 * @file player.h
 * @brief Player class managing units and resources
 * 
 * Contains logic for managing player resources, inventory and units.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "base.h"
#include "character.h"
#include "zone.h"

/**
 * @class Player
 * @brief Represents a player with their resources and objects
 * 
 * Manages:
 * - Mana and money
 * - Controlled zone on the field
 * - Card inventory
 * - Field units
 */
class Player {
private:
    int mana;   ///< Current mana amount
    int money;  ///< Current money amount
    int color;  ///< Team color ANSI code (38;5;N)

public:
    std::shared_ptr<Base> base; ///< Player's base
    Zone zone;                  ///< Controlled field zone
    std::vector<std::shared_ptr<Card>> inventory;        ///< Card deck
    std::vector<std::shared_ptr<Character>> charactersOnGrid; ///< Field units

    /**
     * @brief Player constructor
     * @param Mana Starting mana value
     * @param Money Starting money amount
     * @param Color Team color (ANSI code)
     * @param zone Player's control zone
     */
    Player(int Mana, int Money, int Color, const Zone& zone);

    /// @name Getters
    /// @{
    int getMana() const;
    int getMoney() const;
    int getColor() const;
    /// @}

    /**
     * @brief Checks if coordinates belong to player's zone
     * @param x X coordinate (1-based)
     * @param y Y coordinate (1-based)
     * @return true if coordinates are within control zone
     */
    bool isInsideZone(int x, int y);

    /**
     * @brief Modifies money amount
     * @param profit Can be positive or negative
     * @post money += profit
     */
    void addMoney(int profit);

    /// @name Information display
    /// @{
    void printInventory();
    void printCharactersOnGrid();
    /// @}

    /**
     * @brief Modifies mana amount
     * @param points Can be positive or negative
     * @warning Doesn't check for minimum value
     * @post mana += points
     */
    void changeMana(int points);
};

#endif
