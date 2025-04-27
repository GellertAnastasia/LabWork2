/**
 * @class Coordinates
 * @brief Class for handling 2D coordinates
 * 
 * Provides basic operations for managing object positions on the game field.
 * Used to determine placement of characters, buildings and other objects.
 */
#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include "constants.h"

class Coordinates {
private:
    int x; ///< Horizontal coordinate (from 1 to MAX_WIDTH)
    int y; ///< Vertical coordinate (from 1 to MAX_HEIGHT)

public:
    /**
     * @brief Constructor initializes coordinates
     * @param X Horizontal position
     * @param Y Vertical position
     * @warning Doesn't validate field boundaries
     */
    Coordinates(int X, int Y);

    /**
     * @brief Coordinate comparison operator
     * @return true if x and y match
     */
    bool operator==(const Coordinates& other) const;

    /// @name Getters and setters
    /// @{
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    /// @}

    /**
     * @brief Returns string representation of coordinates
     * @return String in format "(X,Y)"
     * @example For (3,5) returns "(3,5)"
     */
    std::string get() const;
};

#endif
