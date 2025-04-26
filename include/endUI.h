/**
 * @file endUI.h
 * @brief Управление финальным экраном игры
 * 
 * Содержит функции для отображения анимированного экрана завершения игры,
 * включая анимацию звезд и графику победы.
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

extern std::atomic<bool> keepRunning; ///< Флаг для управления анимацией
extern const std::vector<std::string> stars; ///< Набор звездных символов
extern const std::vector<int> starColors; ///< Палитра цветов для звезд

/**
 * @brief Анимирует мерцание звезд в заданной области экрана
 * @param startRow Начальная строка для анимации (1-based)
 * @details Работает в отдельном потоке до сброса флага keepRunning
 */
void animateStars(int startRow);

/**
 * @brief Ожидает нажатия Enter и останавливает анимацию
 * @warning Блокирует основной поток до ввода
 */
void waitForEnter();

/**
 * @brief Отображает экран завершения игры
 * @param winner Название команды-победителя
 * @details Выполняет:
 * - Очистку экрана
 * - Отрисовку ASCII-арта
 * - Запуск анимации в отдельных потоках
 */
void showGameOverScreen(const std::string& winner);

#endif
