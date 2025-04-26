/**
 * @class AddHealth
 * @brief Класс улучшения, добавляющего здоровье персонажу
 * @inherit Improvement
 * 
 * Реализует механизм увеличения здоровья через переопределение методов интерфейса Improvement.
 */
#ifndef ADDHEALTH_H
#define ADDHEALTH_H
#include "improvement.h"

class AddHealth: public Improvement
{
public:
    /**
     * @brief Возвращает название улучшения с количеством добавляемого здоровья
     * @return Строка в формате "Add +X Health", где X — значение getPoints()
     */
    std::string getName() const override;

    /**
     * @brief Добавляет очки здоровья персонажу
     * @param character Персонаж, к которому применяется улучшение
     * @details Также выводит сообщение о применении улучшения в консоль
     */
    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
