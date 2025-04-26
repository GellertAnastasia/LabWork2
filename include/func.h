/**
 * @file func.h
 * @brief Вспомогательные функции общего назначения
 * 
 * Содержит утилиты для работы с консолью, проверки координат и состояния игрового поля.
 */

#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <limits>
#include "coordinates.h"
#include "object.h"
#include "constants.h"

/**
 * @brief Очищает консоль с использованием ANSI escape-кодов
 * @details Посылает последовательность "\033c" для полной очистки экрана
 */
void clearScreen();

/**
 * @brief Приостанавливает выполнение до нажатия Enter
 * @warning Блокирует поток выполнения до получения ввода пользователя
 * @note Очищает буфер ввода перед ожиданием
 */
void pause();

/**
 * @brief Проверяет, находятся ли координаты в пределах игрового поля
 * @param coordinates Проверяемые координаты (1-based)
 * @return true если 1 ≤ X ≤ WIDTH и 1 ≤ Y ≤ HEIGHT
 */
bool isWithinBounds(std::shared_ptr<Coordinates> coordinates);

/**
 * @brief Проверяет доступность клетки для размещения объекта
 * @param coordinates Координаты проверки (1-based)
 * @param grid Ссылка на игровое поле
 * @return true если:
 * - Клетка не занята (grid[y][x] == nullptr)
 * - Не является специальной заблокированной клеткой (базы)
 * @note Специальные заблокированные клетки:
 * - (5,1), (6,1) - база игрока 1
 * - (5,10), (6,10) - база игрока 2
 */
bool isFree(std::shared_ptr<Coordinates> coordinates, 
          std::vector<std::vector<std::shared_ptr<Object>>> grid);

#endif
