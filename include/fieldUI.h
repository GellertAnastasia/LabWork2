/**
 * @class FieldUI
 * @brief Класс для графического отображения игрового поля
 * 
 * Обеспечивает визуализацию:
 * - Сетки игрового поля с объектами
 * - Статистики игроков (здоровье базы, мана, деньги)
 * - Системы координат
 */
#ifndef FIELDUI_H
#define FIELDUI_H

#include <sstream>
#include <iomanip>
#include <algorithm>
#include "constants.h"
#include "field.h"

class FieldUI
{
private:
    Field& field; ///< Ссылка на игровое поле для отрисовки

public:
    /**
     * @brief Конструктор инициализирует привязку к полю
     * @param field Ссылка на объект Field для визуализации
     */
    FieldUI(Field& field);

    /**
     * @brief Отрисовывает полное игровое состояние
     * @param player Левый игрок (текущий)
     * @param enemy Правый игрок (противник)
     * @details Выполняет:
     * 1. Очистку экрана
     * 2. Отрисовку координатной сетки
     * 3. Визуализацию объектов поля
     * 4. Вывод статистики игроков
     */
    void draw(Player& player, Player& enemy);
};

#endif
