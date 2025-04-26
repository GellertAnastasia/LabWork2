/**
 * @class Barrier
 * @brief Класс неподвижного защитного объекта
 * @inherit Object
 * 
 * Используется как препятствие на поле, блокирующее перемещение.
 * Может быть разрушено атаками.
 */
#ifndef BARRIER_H
#define BARRIER_H
#include "object.h"

class Barrier : public Object
{
public:
    /**
     * @brief Конструктор инициализирует параметры барьера
     * @details Устанавливает:
     * - Символ отображения: "≡"
     * - Здоровье: 5 единиц
     */
    Barrier();

    /**
     * @brief Возвращает имя и состояние барьера
     * @return Строка формата:
     * - "Barrier[X,Y]: X HP" (с координатами)
     * - "Barrier: X HP" (без координат)
     */
    std::string getName() const override;
};

#endif
