/**
 * @class AIController
 * @brief Управляет искусственным интеллектом игрока
 * 
 * Реализует логику автоматических действий:
 * - Покупка и использование карт
 * - Перемещение персонажей
 * - Атака вражеских целей
 */
#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include <cstdlib>
#include <ctime>
#include <climits>
#include "player.h"
#include "field.h"
#include "fieldUI.h"
#include "generateCard.h"
#include "improvement.h"

class AIController
{
public:
    /**
     * @brief Конструктор, инициализирует ИИ-игрока
     * @param player Ссылка на управляемого игрока
     * @param field Ссылка на игровое поле
     * @note Инициализирует генератор случайных чисел
     */
    AIController(Player& player, Field& field);

    /// Основной метод для выполнения хода ИИ
    void makeMove(Player& enemy);

    /**
     * @brief Логика действий с персонажами
     * @details Последовательно выполняет атаки и перемещения
     */
    void makeActionsMove(Player& enemy);

private:
    /// Внутренние вспомогательные методы
    bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy);
    bool aiAttack(std::shared_ptr<Character> attacker, Player& enemy);
    std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy);
    
    /// Логика работы с картами
    void playRandomCard(Player& enemy);
    void buyRandomCard();
    bool shouldBuyCard() const;
    bool shouldPlayCard() const;

    Player& player;     ///< Управляемый ИИ игрок
    Field& field;       ///< Игровое поле
    FieldUI fieldUI;    ///< Интерфейс отрисовки поля
};

#endif
