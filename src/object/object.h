#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "../card/card.h"

class Object: public Card
{
public:
    char cell = 'X';
    
    virtual std::string getName() const
    {
        return "empty";
    }
};


#endif
