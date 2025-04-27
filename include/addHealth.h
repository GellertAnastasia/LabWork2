/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @class AddHealth
 * @brief Upgrade class that adds health to a character
 * @inherit Improvement
 * 
 * Implements the health increase mechanism by overriding methods of the Improvement interface.
 */
#ifndef ADDHEALTH_H
#define ADDHEALTH_H
#include "improvement.h"

class AddHealth: public Improvement
{
public:
    /**
     * @brief Returns the upgrade name with the amount of health added
     * @return String in format "Add +X Health" where X is getPoints() value
     */
    std::string getName() const override;

    /**
     * @brief Adds health points to the character
     * @param character Character to which the upgrade is applied
     * @details Also prints a message about the upgrade application to console
     */
    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
