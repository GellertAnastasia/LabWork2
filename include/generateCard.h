/**
 * @file generateCard.h
 * @brief Генератор случайных игровых карт
 * 
 * Создает карты различных типов с заданными вероятностями.
 * Вероятности распределены равномерно между 7 типами.
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
 * @brief Генерирует случайную карту
 * @param owner Указатель на игрока-владельца (для Farm)
 * @return shared_ptr<Card> Сгенерированная карта
 */
std::shared_ptr<Card> generateCard(Player* owner);

#endif
