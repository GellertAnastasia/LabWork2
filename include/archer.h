/**
 * @class Archer
 * @brief Класс лучника - дальнобойного персонажа
 * @inherit Character
 * 
 * Особенности:
 * - Атакует на расстоянии 2 клетки по диагонали
 * - Может перемещаться по диагонали
 * - Низкие показатели здоровья и силы
 */
#ifndef ARCHER_H
#define ARCHER_H
#include "character.h"

class Archer: public Character
{
public:
    /**
     * @brief Конструктор инициализирует параметры лучника
     * @details Устанавливает:
     * - Здоровье = 2
     * - Силу атаки = 2
     * - Стоимость призыва = 2
     * - Символ отображения: "➶"
     */
    Archer();

    /**
     * @brief Возвращает имя и состояние персонажа
     * @return Строка формата: "Archer[X,Y]: X Health Y Power"
     * @details Если местоположение не задано, возвращает "Archer: X Health Y Power"
     */
    std::string getName() const override;
};

#endif
