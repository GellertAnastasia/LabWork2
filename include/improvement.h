/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


/**
 * @file improvement.h
 * @brief Base class for character improvements
 * 
 * Abstract class defining the interface for all improvement types.
 * Allows modification of character attributes.
 */

#ifndef IMPROVEMENT_H
#define IMPROVEMENT_H

#include "card.h"
#include "character.h"
#include <memory>

/**
 * @class Improvement
 * @brief Abstract improvement applied to characters
 * @inherit Card
 * 
 * Implements core functionality for:
 * - Storing improvement points value
 * - Applying modifiers to characters
 */
class Improvement : public Card {
private:
    int points = 1; ///< Improvement points amount

public:
    //Improvement();
    //virtual ~Improvement() = default;
    /**
     * @brief Sets the improvement points value
     * @param value New value (must be > 0)
     * @warning Doesn't perform value validation
     */
    void setPoints(int value);
    
    /**
     * @brief Returns current points value
     * @return Current improvement points amount
     */
    int getPoints() const;
    
    /**
     * @brief Applies improvement to character (pure virtual method)
     * @param character Target character for modification
     * @virtual Must be overridden in derived classes
     */
    virtual void addPoints(std::shared_ptr<Character>& character) = 0;
    
    /**
     * @brief Virtual destructor
     * @details Ensures proper derived class destruction
     */
    virtual ~Improvement() = default;
};

#endif
