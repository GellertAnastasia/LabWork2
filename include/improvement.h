/**
 * @file improvement.h
 * @brief Базовый класс для улучшений персонажей
 * 
 * Абстрактный класс, определяющий интерфейс для всех типов улучшений.
 * Позволяет модифицировать характеристики персонажей.
 */

#ifndef IMPROVEMENT_H
#define IMPROVEMENT_H

#include "card.h"
#include "character.h"
#include <memory>

/**
 * @class Improvement
 * @brief Абстрактное улучшение, применяемое к персонажам
 * @inherit Card
 * 
 * Реализует базовую функциональность для:
 * - Хранения количества очков улучшения
 * - Применения модификаторов к персонажам
 */
class Improvement : public Card {
private:
    int points = 1; ///< Количество очков улучшения

public:
    /**
     * @brief Устанавливает значение очков улучшения
     * @param value Новое значение (должно быть > 0)
     * @warning Не выполняет проверку на валидность значения
     */
    void setPoints(int value);
    
    /**
     * @brief Возвращает текущее значение очков
     * @return Текущее количество очков улучшения
     */
    int getPoints() const;
    
    /**
     * @brief Применяет улучшение к персонажу (чисто виртуальный метод)
     * @param character Целевой персонаж для модификации
     * @virtual Требует переопределения в производных классах
     */
    virtual void addPoints(std::shared_ptr<Character>& character) = 0;
    
    /**
     * @brief Виртуальный деструктор
     * @details Гарантирует корректное удаление производных классов
     */
    virtual ~Improvement() = default;
};

#endif
