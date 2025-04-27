/**
 * @class Base
 * @brief Player's main building class
 * @inherit Object
 *
 * Represents the primary attack target for the opponent.
 * Destroying the base results in player's defeat.
 */
#ifndef BASE_H
#define BASE_H
#include "coordinates.h"
#include "object.h"

class Base : public Object
{
public:
    /**
     * @brief Constructor initializes base parameters
     * @param value Player identifier (used for color)
     * @details Sets:
     * - Symbol: "☖" (chess rook)
     * - Health: 10 units
     * - Color according to player identifier
     */
    Base(int value);

    /**
     * @brief Returns base status with coordinates
     * @return String in format:
     * - "Base[X,Y]: X HP" (with coordinates)
     * - "Base: X HP" (without coordinates)
     */
    std::string getName() const override;
};

#endif
