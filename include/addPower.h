/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @class AddPower
 * @brief Upgrade class that increases character's attack power
 * @inherit Improvement
 * 
 * Implements the attack power boost mechanism through the Improvement interface.
 */
#ifndef ADDPOWER_H
#define ADDPOWER_H
#include "improvement.h"

class AddPower: public Improvement
{
public:
    /**
     * @brief Generates upgrade name with bonus value
     * @return String in format "Add +X Power" where X is getPoints() value
     */
    std::string getName() const override;

    /**
     * @brief Increases character's power
     * @param character Target character to enhance
     * @details Prints upgrade application message to console
     */
    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
