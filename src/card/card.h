#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
public:
    int cost = 1;
    virtual std::string getName() const
    {
        return "empty";
    }
    
    void setCost(int value);
    int getCost() const;
};

#endif
