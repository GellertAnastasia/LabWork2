/**
 * @class Archer
 * @brief Archer class - a ranged combat character
 * @inherit Character
 * 
 * Special traits:
 * - Attacks at 2-cell diagonal range
 * - Can move diagonally
 * - Low health and attack power stats
 */
#ifndef ARCHER_H
#define ARCHER_H
#include "character.h"

class Archer: public Character
{
public:
    /**
     * @brief Constructor initializes archer parameters
     * @details Sets:
     * - Health = 2
     * - Attack power = 2
     * - Summoning cost = 2
     * - Display symbol: "➶"
     */
    Archer();

    /**
     * @brief Returns character name and status
     * @return String in format: "Archer[X,Y]: X Health Y Power"
     * @details If location is not set, returns "Archer: X Health Y Power"
     */
    std::string getName() const override;
};

#endif
