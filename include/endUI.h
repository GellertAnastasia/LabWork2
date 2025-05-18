/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

/**
 * @file endUI.h
 * @brief Game over screen management
 * 
 * Contains functions for displaying animated game ending screens,
 * including star animations and victory graphics.
 */

#ifndef ENDUI_H
#define ENDUI_H

#include "func.h"
#include <string>
#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

extern std::atomic<bool> keepRunning; ///< Animation control flag
extern const std::vector<std::string> stars; ///< Collection of star symbols
extern const std::vector<int> starColors; ///< Color palette for stars

/**
 * @brief Animates twinkling stars in specified screen area
 * @param startRow Starting row for animation (1-based)
 * @details Runs in separate thread until keepRunning flag is cleared
 */
void animateStars(int startRow);

/**
 * @brief Waits for Enter key press and stops animation
 * @warning Blocks main thread until input
 */
void waitForEnter();

/**
 * @brief Displays game over screen
 * @param winner Winning team name
 * @details Performs:
 * - Screen clearing
 * - ASCII art rendering
 * - Animation launch in separate threads
 */
void showGameOverScreen(const std::string& winner);

#endif
