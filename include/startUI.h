/**
 * @file startUI.h
 * @brief Интерфейс стартового меню игры
 * 
 * Содержит функции для отображения главного заголовка и меню с ASCII-графикой.
 * Использует цветовое оформление из constants.h.
 */

#ifndef STARTUI_H
#define STARTUI_H

#include <iostream>
#include <string>
#include "constants.h"
#include "func.h"

/**
 * @brief Выводит главный заголовок игры
 * @details Очищает экран и отображает ASCII-арт названия игры
 * @warning Использует ANSI escape-коды для:
 * - Очистки экрана
 * - Цветового оформления
 */
void printTitle();

/**
 * @brief Рисует меню с тремя пунктами
 * @param one Текст первого пункта меню
 * @param two Текст второго пункта меню
 * @param three Текст третьего пункта меню
 * 
 * @image html menu_layout.png "Структура меню"
 * @note Автоматически подстраивает ширину под длину текста
 */
void printMenu(std::string one, std::string two, std::string three);

#endif
