/**
 * @class Field
 * @brief Управляет игровым полем и взаимодействием объектов
 * 
 * Содержит двумерную сетку для размещения игровых объектов, обрабатывает:
 * - Размещение новых персонажей/строений
 * - Перемещение объектов
 * - Удаление объектов
 * - Экономические операции (доход с ферм)
 */
#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>
#include <limits>
#include "constants.h"
#include "character.h"
#include "fighter.h"
#include "farm.h"
#include "coordinates.h"
#include "player.h"

class Field
{
public:
    /// Двумерная сетка игровых объектов (HEIGHT x WIDTH)
    std::vector<std::vector<std::shared_ptr<Object>>> grid;

    /**
     * @brief Конструктор создает поле размером HEIGHT x WIDTH
     * @details Инициализирует все ячейки nullptr
     */
    Field();

    /**
     * @brief Проверяет наличие свободных ячеек в зоне игрока
     * @param player Игрок для проверки зоны
     * @return true если есть хотя бы одна пустая ячейка
     */
    bool isEmpty(Player& player);

    /**
     * @brief Размещает новый объект на поле
     * @param player Владелец объекта
     * @param coordinates Целевые координаты (1-based)
     * @param character Объект для размещения
     * @return true при успешном размещении
     * @throws logic_error Если координаты вне зоны игрока
     */
    bool placeNewCharacter(Player& player, 
                         const std::shared_ptr<Coordinates>& coordinates,
                         std::shared_ptr<Object> character);

    /**
     * @brief Перемещает объект между ячейками
     * @param player Владелец объекта
     * @param from Исходные координаты (1-based)
     * @param to Целевые координаты (1-based)
     * @return true при успешном перемещении
     * @warning Не проверяет возможность перемещения по правилам объекта
     */
    bool moveCharacter(Player& player,
                      const std::shared_ptr<Coordinates>& from,
                      std::shared_ptr<Coordinates>& to);

    /**
     * @brief Удаляет объект с поля
     * @param coords Координаты объекта (1-based)
     * @param player Владелец объекта
     * @post Объект удаляется из grid и списка персонажей игрока
     */
    void deleteObject(const std::shared_ptr<Coordinates>& coords,
                     Player& player);

    /**
     * @brief Начисляет доход со всех ферм игрока
     * @param player Целевой игрок
     * @return Суммарный доход за ход
     */
    int processFarmsIncome(Player& player);
};

#endif
