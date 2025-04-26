/**
 * @class Fighter
 * @brief Класс бойца ближнего боя
 * @inherit Character
 * 
 * Характеризуется средними показателями здоровья и атаки. 
 * Основной юнит для ближнего боя.
 */
#ifndef FIGHTER_H
#define FIGHTER_H
#include "character.h"

class Fighter: public Character
{
public:
    /**
     * @brief Конструктор инициализирует параметры бойца
     * @details Устанавливает:
     * - Символ: "⚔︎"
     * - Здоровье: 3
     * - Сила атаки: 3
     * - Стоимость призыва: 2
     */
    Fighter();

    /**
     * @brief Возвращает имя и состояние бойца
     * @override Переопределяет метод Character
     * @return Строка формата:
     * - "Fighter[X,Y]: X HP Y ATK" (с координатами)
     * - "Fighter: X HP Y ATK" (без координат)
     */
    std::string getName() const override;
};

#endif
