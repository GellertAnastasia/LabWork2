/**
 * @file generateCard.h
 * @brief Random game card generator
 * 
 * Creates cards of various types with specified probabilities.
 * Probabilities are evenly distributed between 7 types.
 */

#ifndef GENERATECARD_H
#define GENERATECARD_H

#include <memory>
#include <cstdlib>
#include <ctime>
#include "fighter.h"
#include "wizard.h"
#include "archer.h"
#include "barrier.h"
#include "farm.h"
#include "addHealth.h"
#include "addPower.h"

/**
 * @brief Generates a random card
 * @param owner Pointer to owner player (for Farm)
 * @return shared_ptr<Card> Generated card
 */
std::shared_ptr<Card> generateCard(Player* owner);

#endif
