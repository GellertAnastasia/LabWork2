/**
 * @class Fighter
 * @brief Melee combat character class
 * @inherit Character
 * 
 * Features medium health and attack stats.
 * Primary melee combat unit.
 */
#ifndef FIGHTER_H
#define FIGHTER_H
#include "character.h"

class Fighter: public Character
{
public:
    /**
     * @brief Constructor initializes fighter parameters
     * @details Sets:
     * - Symbol: "⚔︎"
     * - Health: 3
     * - Attack power: 3
     * - Summon cost: 2
     */
    Fighter();

    /**
     * @brief Returns fighter name and status
     * @override Overrides Character method
     * @return String in format:
     * - "Fighter[X,Y]: X HP Y ATK" (with coordinates)
     * - "Fighter: X HP Y ATK" (without coordinates)
     */
    std::string getName() const override;
};

#endif
