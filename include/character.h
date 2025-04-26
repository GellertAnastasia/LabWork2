/**
 * @class Character
 * @brief Базовый класс для всех игровых персонажей
 * @inherit Object
 * 
 * Обеспечивает базовую функциональность для:
 * - Перемещения по полю
 * - Атаки вражеских объектов
 * - Управления характеристиками (сила, здоровье)
 */
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "constants.h"
#include "object.h"
#include "coordinates.h"
#include "func.h"

class Character: public Object
{
private:
    int power = 1;  ///< Боевая сила персонажа
    std::vector<std::pair<int, int>> directionOfMove = ///< Направления перемещения
    {
        {-1, 0},  // Влево
        {1, 0},   // Вправо
        {0, -1},  // Вверх
        {0, 1}    // Вниз
    };
    std::vector<std::pair<int, int>> directionOfAttack = ///< Зоны атаки
    {
        {1, 0},  // Горизонтальная
        {0, 1}   // Вертикальная
    };

public:
    std::vector<std::shared_ptr<Coordinates>> movement; ///< Доступные клетки для перемещения
    std::vector<std::shared_ptr<Object>> attack;         ///< Доступные цели для атаки

    /// @name Управление характеристиками
    /// @{
    void setPower(int value);
    int getPower() const;
    /// @}

    /// @name Настройка перемещения
    /// @{
    const std::vector<std::pair<int, int>>& getDirectionOfMove() const;
    void setDirectionOfMove(const std::vector<std::pair<int, int>>& newDirections);
    /// @}

    /// @name Настройка атаки
    /// @{
    const std::vector<std::pair<int, int>>& getDirectionOfAttack() const;
    void setDirectionOfAttack(const std::vector<std::pair<int, int>>& newDirections);
    /// @}

    /// @name Боевая логика
    /// @{
    void calculateMovement(const std::shared_ptr<Coordinates>& coordinates, 
                         const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
    void printMovement();
    bool isWithinAttackRange(int targetX, int targetY, 
                           const std::shared_ptr<Coordinates>& coordinates);
    void calculateAttack(const std::shared_ptr<Coordinates>& coordinates,
                       const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
    void printAttack();
    /// @}

    /**
     * @brief Возвращает имя и состояние персонажа
     * @override Переопределяет метод Object
     * @return Строка с информацией (требует реализации в наследниках)
     */
    std::string getName() const override;
};

#endif
