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
};

#endif
