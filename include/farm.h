/**
 * @class Farm
 * @brief Класс фермы - объекта, генерирующего ресурсы
 * @inherit Object
 * 
 * Автоматически приносит доход владельцу каждый ход. Может быть разрушена атаками.
 */
#ifndef FARM_H
#define FARM_H

#include <memory>
#include "player.h"
#include "object.h"

class Farm : public Object
{
private:
    int profit = 1; ///< Количество денег за ход (по умолчанию 1)

public:
    Player* owner; ///< Указатель на владельца фермы

    /**
     * @brief Устанавливает доходность фермы
     * @param value Новое значение дохода (>0)
     */
    void setProfit(int value);

    /**
     * @brief Возвращает текущую доходность
     * @return Значение profit
     */
    int getProfit() const;

    /**
     * @brief Конструктор создает ферму для указанного игрока
     * @param owner Владелец фермы (не может быть nullptr)
     * @note Устанавливает:
     * - Символ отображения: "⛃"
     * - Стоимость постройки: 3
     */
    Farm(Player* owner);

    /**
     * @brief Возвращает имя и состояние фермы
     * @override Переопределяет метод Object
     * @return Строка формата "Farm[X,Y]: X HP" или "Farm: X HP"
     */
    std::string getName() const override;

    /**
     * @brief Генерирует доход для владельца
     * @return Сумма сгенерированных денег
     * @warning Если owner == nullptr, возвращает 0
     * @post Увеличивает счетчик денег владельца на profit
     */
    int bringMoney();
};

#endif
