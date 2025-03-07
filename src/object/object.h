#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "../card/card.h"

class Object: public Card
{
protected:
    char cell;
public:
    void setCell(char value);
    char getCell() const;
    virtual std::string getName() const
    {
        return "empty";
    }
};


#endif
