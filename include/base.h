/**
 * @class Base
 * @brief Класс главного здания игрока
 * @inherit Object
 * 
 * Представляет собой основную цель для атаки противника. 
 * Уничтожение базы приводит к поражению игрока.
 */
#ifndef BASE_H
#define BASE_H
#include "coordinates.h"
#include "object.h"

class Base : public Object
{
public:
    /**
     * @brief Конструктор инициализирует базовые параметры
     * @param value Идентификатор игрока (используется для цвета)
     * @details Устанавливает:
     * - Символ: "☖" (шахматная ладья)
     * - Здоровье: 10 единиц
     * - Цвет в соответствии с идентификатором игрока
     */
    Base(int value);

    /**
     * @brief Возвращает состояние базы с координатами
     * @return Строка формата:
     * - "Base[X,Y]: X HP" (с координатами)
     * - "Base: X HP" (без координат)
     */
    std::string getName() const override;
};

#endif
