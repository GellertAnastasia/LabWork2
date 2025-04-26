/**
 * @class ActionsPhase
 * @brief Управляет фазой действий персонажей игрока
 * 
 * Обрабатывает перемещения, атаки и взаимодействие с игровым полем.
 * Координирует обновление состояния игры через объекты Field и FieldUI.
 */
#ifndef ACTIONSPHASE_H
#define ACTIONSPHASE_H
#include "fieldUI.h"
#include "wizard.h"

class ActionsPhase
{
private:
    Field& field;       ///< Ссылка на игровое поле
    FieldUI fieldUI;    ///< Интерфейс для отрисовки поля

public:
    /**
     * @brief Конструктор, инициализирует привязку к полю
     * @param field Ссылка на игровое поле
     */
    ActionsPhase(Field& field);

    /**
     * @brief Запускает фазу действий для текущего игрока
     * @param player Активный игрок
     * @param enemy Противник
     */
    void start(Player& player, Player& enemy);

    /**
     * @brief Выполняет перемещение персонажа
     * @param choice Индекс выбранного персонажа (начиная с 1)
     * @param player Игрок, чей персонаж перемещается
     * @param enemy Противник
     * @return true если перемещение успешно выполнено
     */
    bool moveCharacter(size_t choice, Player& player, Player& enemy);

    /**
     * @brief Выполняет атаку выбранной цели
     * @param choice Индекс атакующего персонажа (начиная с 1)
     * @param player Игрок, чей персонаж атакует
     * @param enemy Цель атаки
     * @return true если атака успешно выполнена
     */
    bool attack(size_t choice, Player& player, Player& enemy);
};

#endif
