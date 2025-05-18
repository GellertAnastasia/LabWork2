/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @class Farm
 * @brief Farm class - resource generating object
 * @inherit Object
 * 
 * Automatically generates income for owner each turn. Can be destroyed by attacks.
 */
#ifndef FARM_H
#define FARM_H

#include <memory>
#include "player.h"
#include "object.h"

class Farm : public Object
{
private:
    int profit = 1; ///< Money generated per turn (default 1)

public:
    Player* owner; ///< Pointer to farm owner

    /**
     * @brief Sets farm profitability
     * @param value New income value (>0)
     */
    void setProfit(int value);

    /**
     * @brief Returns current profitability
     * @return profit value
     */
    int getProfit() const;

    /**
     * @brief Constructor creates farm for specified player
     * @param owner Farm owner (cannot be nullptr)
     * @note Sets:
     * - Display symbol: "⛃"
     * - Build cost: 3
     */
    Farm(Player* owner);

    /**
     * @brief Returns farm name and status
     * @override Overrides Object method
     * @return String in format "Farm[X,Y]: X HP" or "Farm: X HP"
     */
    std::string getName() const override;

    /**
     * @brief Generates income for owner
     * @return Amount of money generated
     * @warning If owner == nullptr, returns 0
     * @post Increases owner's money counter by profit
     */
    int bringMoney();
};

#endif
