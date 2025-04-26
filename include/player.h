/**
 * @file player.h
 * @brief Класс игрока, управляющего юнитами и ресурсами
 * 
 * Содержит логику управления ресурсами, инвентарем и юнитами игрока.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "base.h"
#include "character.h"
#include "zone.h"

/**
 * @class Player
 * @brief Представляет игрока с его ресурсами и объектами
 * 
 * Управляет:
 * - Маной и деньгами
 * - Зоной контроля на поле
 * - Инвентарем карт
 * - Персонажами на поле
 */
class Player {
private:
    int mana;   ///< Текущее количество маны
    int money;  ///< Текущее количество денег
    int color;  ///< ANSI код цвета команды (38;5;N)

public:
    std::shared_ptr<Base> base; ///< База игрока
    Zone zone;                  ///< Контролируемая зона на поле
    std::vector<std::shared_ptr<Card>> inventory;        ///< Колода карт
    std::vector<std::shared_ptr<Character>> charactersOnGrid; ///< Персонажи на поле

    /**
     * @brief Конструктор игрока
     * @param Mana Начальное значение маны
     * @param Money Начальное количество денег
     * @param Color Цвет команды (ANSI код)
     * @param zone Зона контроля игрока
     */
    Player(int Mana, int Money, int Color, const Zone& zone);

    /// @name Геттеры
    /// @{
    int getMana() const;
    int getMoney() const;
    int getColor() const;
    /// @}

    /**
     * @brief Проверяет принадлежность координат зоне игрока
     * @param x Координата X (1-based)
     * @param y Координата Y (1-based)
     * @return true если координаты в зоне контроля
     */
    bool isInsideZone(int x, int y);

    /**
     * @brief Изменяет количество денег
     * @param profit Может быть положительным или отрицательным
     * @post money += profit
     */
    void addMoney(int profit);

    /// @name Информационный вывод
    /// @{
    void printInventory();
    void printCharactersOnGrid();
    /// @}

    /**
     * @brief Изменяет количество маны
     * @param points Может быть положительным или отрицательным
     * @warning Не проверяет выход за минимальное значение
     * @post mana += points
     */
    void changeMana(int points);
};

#endif
