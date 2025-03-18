#ifndef IMPROVEMENT_H
#define IMPROVEMENT_H
#include "../card/card.h"
#include "../character/character.h"

class Improvement: public Card
{
public:
    int points = 1;
    
    virtual void addPoints(std::shared_ptr<Character>& character)
    {
    }
};

#endif
