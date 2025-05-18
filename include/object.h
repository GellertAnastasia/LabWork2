/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @file object.h
 * @brief Base class for all game objects
 * 
 * Contains core properties and methods common to all field objects:
 * - Visual representation
 * - Health
 * - Team color affiliation
 * - Map position
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "card.h"
#include "coordinates.h"

/**
 * @class Object
 * @brief Game object abstraction
 * @inherit Card
 * 
 * Serves as base class for:
 * - Characters
 * - Buildings
 * - Improvements
 * - Obstacles
 */
class Object : public Card {
protected:
    std::string cell;   ///< Symbolic representation (UTF-8)
    int health = 1;     ///< Current object health
    int color;          ///< Team color (ANSI code)

public:
    bool hasActed = false; ///< Action performed flag (per turn)
    std::shared_ptr<Coordinates> location; ///< Field coordinates

    /**
     * @brief Sets symbolic representation
     * @param value UTF-8 character string
     */
    void setCell(const std::string& value);
    
    /**
     * @brief Returns object's current symbol
     * @return UTF-8 string for display
     */
    std::string getCell() const;

    /**
     * @brief Sets team color
     * @param value ANSI color code (38;5;N)
     */
    void setColor(int value);
    
    /**
     * @brief Returns current object color
     * @return ANSI color code
     */
    int getColor() const;

    /**
     * @brief Sets health value
     * @param value New health (>0)
     * @warning Doesn't validate value
     */
    void setHealth(int value);
    
    /**
     * @brief Returns current health
     * @return Health value in range [0..MAX_HEALTH]
     */
    int getHealth() const;

    /**
     * @brief Sets object position
     * @param newLocation shared_ptr to coordinates
     * @note Automatically updates field position
     */
    void setLocation(const std::shared_ptr<Coordinates>& newLocation);
    
    /**
     * @brief Returns current position
     * @return shared_ptr with coordinates or nullptr
     */
    std::shared_ptr<Coordinates> getLocation() const;

    /**
     * @brief Modifies object health
     * @param points Positive/negative value
     * @post Health changes by specified amount
     * @warning Doesn't enforce minimum value
     */
    void changeHealth(int points);
};

#endif
