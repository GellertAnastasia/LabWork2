/**
 * @class Card
 * @brief Base class for game cards
 *
 * Provides interface and base functionality for all card types:
 * - Cost management
 * - Name retrieval
 *
 * @note This is an abstract class requiring getName() override
 */
#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
private:
    int cost = 1; ///< Card cost in mana (default 1)

public:
    /**
     * @brief Returns card name
     * @virtual Must be overridden in derived classes
     * @return String with card name
     */
    virtual std::string getName() const
    {
        return "empty";
    }

    /**
     * @brief Sets card usage cost
     * @param value New cost (must be > 0)
     */
    void setCost(int value);

    /**
     * @brief Returns current card cost
     * @return Current cost value
     */
    int getCost() const;
};

#endif
