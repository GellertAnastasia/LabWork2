/**
 * @class Character 
 * @brief Base class for all game characters
 * @inherit Object
 *
 * Provides core functionality for:
 * - Field movement
 * - Attacking enemy objects
 * - Managing attributes (power, health)
 */
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "constants.h"
#include "object.h"
#include "coordinates.h"
#include "func.h"

class Character: public Object
{
private:
    int power = 1;  ///< Character's combat strength
    std::vector<std::pair<int, int>> directionOfMove = ///< Movement directions
    {
        {-1, 0},  // Left
        {1, 0},   // Right
        {0, -1},  // Up
        {0, 1}    // Down
    };
    std::vector<std::pair<int, int>> directionOfAttack = ///< Attack zones
    {
        {1, 0},  // Horizontal
        {0, 1}   // Vertical
    };

public:
    std::vector<std::shared_ptr<Coordinates>> movement; ///< Available movement cells
    std::vector<std::shared_ptr<Object>> attack;        ///< Available attack targets

    /// @name Attribute Management
    /// @{
    void setPower(int value);
    int getPower() const;
    /// @}

    /// @name Movement Configuration
    /// @{
    const std::vector<std::pair<int, int>>& getDirectionOfMove() const;
    void setDirectionOfMove(const std::vector<std::pair<int, int>>& newDirections);
    /// @}

    /// @name Attack Configuration
    /// @{
    const std::vector<std::pair<int, int>>& getDirectionOfAttack() const;
    void setDirectionOfAttack(const std::vector<std::pair<int, int>>& newDirections);
    /// @}

    /// @name Combat Logic
    /// @{
    void calculateMovement(const std::shared_ptr<Coordinates>& coordinates,
                         const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
    void printMovement();
    bool isWithinAttackRange(int targetX, int targetY,
                           const std::shared_ptr<Coordinates>& coordinates);
    void calculateAttack(const std::shared_ptr<Coordinates>& coordinates,
                       const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
    void printAttack();
    /// @}

    /**
     * @brief Returns character name and status
     * @override Overrides Object method
     * @return String with character info (requires implementation in derived classes)
     */
    std::string getName() const override;
};

#endif
