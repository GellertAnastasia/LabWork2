#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
private:
    int cost = 1;
public:
    virtual std::string getName() const
    {
        return "empty";
    }
    void setCost(int value);
    int getCost() const;
};

#endif
