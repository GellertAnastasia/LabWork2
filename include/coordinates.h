/**
 * @class Coordinates
 * @brief Класс для работы с двумерными координатами
 * 
 * Предоставляет базовые операции для управления позицией объектов на игровом поле.
 * Используется для определения расположения персонажей, построек и других объектов.
 */
#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include "constants.h"

class Coordinates {
private:
    int x; ///< Горизонтальная координата (от 1 до MAX_WIDTH)
    int y; ///< Вертикальная координата (от 1 до MAX_HEIGHT)

public:
    /**
     * @brief Конструктор инициализирует координаты
     * @param X Горизонтальная позиция
     * @param Y Вертикальная позиция
     * @warning Не проверяет границы поля
     */
    Coordinates(int X, int Y);

    /**
     * @brief Оператор сравнения координат
     * @return true если x и y совпадают
     */
    bool operator==(const Coordinates& other) const;

    /// @name Геттеры и сеттеры
    /// @{
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    /// @}

    /**
     * @brief Возвращает строковое представление координат
     * @return Строка формата "(X,Y)"
     * @example Для (3,5) вернет "(3,5)"
     */
    std::string get() const;
};

#endif
