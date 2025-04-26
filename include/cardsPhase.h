/**
 * @class CardsPhase
 * @brief Управляет фазой использования карт в игровом цикле
 * 
 * Отвечает за:
 * - Отображение интерфейса взаимодействия с картами
 * - Активацию карт из инвентаря
 * - Покупку новых карт
 * - Взаимодействие с игровым полем и игроками
 */
#ifndef CARDSPHASE_H
#define CARDSPHASE_H

#include <iostream>
#include "fieldUI.h"
#include "base.h"
#include "generateCard.h"

class CardsPhase
{
private:
    Field& field;       ///< Ссылка на игровое поле
    FieldUI fieldUI;    ///< Интерфейс отрисовки поля

public:
    /**
     * @brief Конструктор, инициализирует привязку к полю
     * @param field Игровое поле для взаимодействия
     */
    CardsPhase(Field& field);

    /**
     * @brief Основной цикл фазы использования карт
     * @param player Активный игрок
     * @param enemy Противник
     */
    void start(Player& player, Player& enemy);

    /**
     * @brief Логика активации карты из инвентаря
     * @param player Игрок, активирующий карту
     * @param enemy Целевой игрок для эффектов
     */
    void playCard(Player& player, Player& enemy);

    /**
     * @brief Покупка случайной карты за игровую валюту
     * @param player Игрок, совершающий покупку
     * @warning Требует 3 единицы денег
     */
    void buyCard(Player& player);
};

#endif
