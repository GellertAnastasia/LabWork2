/**
 * @file object.h
 * @brief Базовый класс для всех игровых объектов
 * 
 * Содержит основные свойства и методы, общие для всех объектов на поле:
 * - Визуальное представление
 * - Здоровье
 * - Цветовую принадлежность
 * - Позицию на карте
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "card.h"
#include "coordinates.h"

/**
 * @class Object
 * @brief Абстракция игрового объекта
 * @inherit Card
 * 
 * Используется как базовый класс для:
 * - Персонажей
 * - Строений
 * - Улучшений
 * - Препятствий
 */
class Object : public Card {
protected:
    std::string cell;   ///< Символьное представление объекта (UTF-8)
    int health = 1;     ///< Текущее здоровье объекта
    int color;          ///< Цвет команды (код ANSI)

public:
    bool hasActed = false; ///< Флаг выполнения действия за ход
    std::shared_ptr<Coordinates> location; ///< Координаты на поле

    /**
     * @brief Устанавливает символьное представление
     * @param value Строка с UTF-8 символом
     */
    void setCell(const std::string& value);
    
    /**
     * @brief Возвращает текущий символ объекта
     * @return UTF-8 строка для отображения
     */
    std::string getCell() const;

    /**
     * @brief Устанавливает цвет команды
     * @param value Код цвета ANSI (38;5;N)
     */
    void setColor(int value);
    
    /**
     * @brief Возвращает текущий цвет объекта
     * @return Код цвета ANSI
     */
    int getColor() const;

    /**
     * @brief Устанавливает значение здоровья
     * @param value Новое значение здоровья (>0)
     * @warning Не проверяет допустимость значения
     */
    void setHealth(int value);
    
    /**
     * @brief Возвращает текущее здоровье
     * @return Значение здоровья в диапазоне [0..MAX_HEALTH]
     */
    int getHealth() const;

    /**
     * @brief Устанавливает позицию объекта
     * @param newLocation shared_ptr на координаты
     * @note Автоматически обновляет позицию на поле
     */
    void setLocation(const std::shared_ptr<Coordinates>& newLocation);
    
    /**
     * @brief Возвращает текущую позицию
     * @return shared_ptr с координатами или nullptr
     */
    std::shared_ptr<Coordinates> getLocation() const;

    /**
     * @brief Изменяет здоровье объекта
     * @param points Положительное/отрицательное значение
     * @post Здоровье изменяется на указанное количество пунктов
     * @warning Не ограничивает минимальное значение
     */
    void changeHealth(int points);
};

#endif
