/**
 * @class AddPower
 * @brief Класс улучшения, увеличивающего силу атаки персонажа
 * @inherit Improvement
 * 
 * Реализует механизм увеличения боевой силы через интерфейс Improvement.
 */
#ifndef ADDPOWER_H
#define ADDPOWER_H
#include "improvement.h"

class AddPower: public Improvement
{
public:
    /**
     * @brief Генерирует название улучшения с величиной бонуса
     * @return Строка формата "Add +X Power", где X - значение getPoints()
     */
    std::string getName() const override;

    /**
     * @brief Увеличивает силу персонажа
     * @param character Целевой персонаж для усиления
     * @details Выводит в консоль сообщение о применении улучшения
     */
    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
