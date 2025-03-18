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
    int health = 1;
    int color;
    std::shared_ptr<Coordinates> location;
    bool hasActed = false;
    void setCell(char value);
    char getCell() const;
    void setColor(int value);
    int getColor() const;
    void setLocation(const std::shared_ptr<Coordinates>& newLocation);
    std::shared_ptr<Coordinates> getLocation() const;
    virtual std::string getName() const
    {
        return "empty";
    }
};

#endif
