/**
 * @file wizard.h
 * @brief Magic character class definition
 * 
 * Contains the Wizard class definition - a character with special attack mechanics.
 */

#ifndef WIZARD_H
#define WIZARD_H

#include "character.h"

/**
 * @class Wizard
 * @brief Mage specializing in area attacks
 * @inherit Character
 * 
 * Special traits:
 * - Low health but unique attack mechanics
 * - Can attack diagonally and in cross pattern
 * - Uses magical symbols for display
 */
class Wizard : public Character {
public:
    /**
     * @brief Constructor initializes wizard parameters
     * @details Sets:
     * - Display symbol: "✫" (UTF-8 star)
     * - Health: 2 HP
     * - Attack power: 1 ATK
     * - Attack directions:
     *   • Straight (up/right)
     *   • Diagonal (↗→↓)
     */
    Wizard();

    /**
     * @brief Returns character name and status
     * @override Overrides Character method
     * @return String in format:
     * - "Wizard[X,Y]: X HP Y ATK" (with coordinates)
     * - "Wizard: X HP Y ATK" (without coordinates)
     */
    std::string getName() const override;
};

#endif
