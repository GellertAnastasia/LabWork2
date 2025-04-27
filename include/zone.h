/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @file zone.h
 * @brief Class for defining rectangular zones on game field
 * 
 * Used to limit player action areas, 
 * manage object placement and control available cells.
 */

#ifndef ZONE_H
#define ZONE_H

/**
 * @class Zone
 * @brief Represents a rectangular coordinate area
 * 
 * Stores zone boundaries and provides methods for:
 * - Setting boundaries
 * - Getting current boundary values
 * - Copying zones
 */
class Zone {
private:
    int minX; ///< Minimum X coordinate (left edge)
    int maxX; ///< Maximum X coordinate (right edge)
    int minY; ///< Minimum Y coordinate (bottom edge)
    int maxY; ///< Maximum Y coordinate (top edge)

public:
    /**
     * @brief Default constructor
     * @warning Creates invalid zone (0,0,0,0)
     */
    Zone() = default;

    /**
     * @brief Main zone constructor
     * @param minX Left boundary (inclusive, >=1)
     * @param maxX Right boundary (inclusive, <=WIDTH)
     * @param minY Bottom boundary (inclusive, >=1)
     * @param maxY Top boundary (inclusive, <=HEIGHT)
     */
    Zone(int minX, int maxX, int minY, int maxY);

    /// @name Copy constructors
    /// @{
    Zone(const Zone&) = default; ///< Copies boundaries from existing zone
    /// @}

    /// @name Boundary getters
    /// @{
    int getMinX() const; ///< Returns minX
    int getMaxX() const; ///< Returns maxX
    int getMinY() const; ///< Returns minY
    int getMaxY() const; ///< Returns maxY
    /// @}

    /// @name Boundary setters
    /// @{
    void setMinX(int value); ///< Sets minX (no validation)
    void setMaxX(int value); ///< Sets maxX (no validation)
    void setMinY(int value); ///< Sets minY (no validation)
    void setMaxY(int value); ///< Sets maxY (no validation)
    /// @}
};

#endif
