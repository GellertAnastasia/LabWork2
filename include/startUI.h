/**
 * @file startUI.h
 * @brief Game start menu interface
 * 
 * Contains functions for displaying the main title and menu with ASCII graphics.
 * Uses color schemes from constants.h.
 */

#ifndef STARTUI_H
#define STARTUI_H

#include <iostream>
#include <string>
#include "constants.h"
#include "func.h"

/**
 * @brief Displays the game's main title
 * @details Clears screen and shows game name ASCII art
 * @warning Uses ANSI escape codes for:
 * - Screen clearing
 * - Color formatting
 */
void printTitle();

/**
 * @brief Renders a three-option menu
 * @param one First menu option text
 * @param two Second menu option text
 * @param three Third menu option text
 * 
 * @image html menu_layout.png "Menu structure"
 * @note Automatically adjusts width to text length
 */
void printMenu(std::string one, std::string two, std::string three);

#endif
