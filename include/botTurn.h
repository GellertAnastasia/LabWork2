/**
 * @class BotTurn
 * @brief Управляет полным циклом хода ИИ-игрока
 * 
 * Координирует:
 * - Начисление ресурсов
 * - Сброс состояний персонажей
 * - Вызов логики ИИ для принятия решений
 */
#ifndef BOTTURN_H
#define BOTTURN_H
#include "aiController.h"

class BotTurn
{
public:
    Field& field;       ///< Ссылка на игровое поле
    AIController ai;    ///< Контроллер ИИ для принятия решений

    /**
     * @brief Конструктор инициализирует систему хода бота
     * @param field Игровое поле
     * @param player ИИ-игрок, для которого выполняется ход
     */
    BotTurn(Field& field, Player& player);

    /**
     * @brief Выполняет полный цикл хода
     * @param player Активный ИИ-игрок
     * @param enemy Противник
     */
    void start(Player& player, Player& enemy);
};

#endif
