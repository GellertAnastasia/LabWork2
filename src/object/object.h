#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "../card/card.h"
#include "../coordinates/coordinates.h"


class Object: public Card
{
protected:
    char cell;
public:
    int health = 20;
    int color;
    void setCell(char value);
    char getCell() const;
    void setColor(int value);
    int getColor() const;
    virtual std::string getName() const
    {
        return "empty";
    }
};

#endif
