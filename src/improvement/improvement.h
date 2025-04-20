#ifndef IMPROVEMENT_H
#define IMPROVEMENT_H
#include "../card/card.h"
#include "../character/character.h"

class Improvement: public Card
{
private:
    int points = 1;
public:
    void setPoints(int value);
    int getPoints() const;
    virtual void addPoints(std::shared_ptr<Character>& character) {}
};

#endif
