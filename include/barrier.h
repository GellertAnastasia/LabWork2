/**
 * @class Barrier
 * @brief Immobile defensive object class
 * @inherit Object
 *
 * Used as an obstacle on the field that blocks movement.
 * Can be destroyed by attacks.
 */
#ifndef BARRIER_H
#define BARRIER_H
#include "object.h"

class Barrier : public Object
{
public:
    /**
     * @brief Constructor initializes barrier parameters
     * @details Sets:
     * - Display symbol: "≡"
     * - Health: 5 units
     */
    Barrier();

    /**
     * @brief Returns barrier name and status
     * @return String in format:
     * - "Barrier[X,Y]: X HP" (with coordinates)
     * - "Barrier: X HP" (without coordinates)
     */
    std::string getName() const override;
};

#endif
