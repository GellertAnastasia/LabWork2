#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include "constants.h"


class Coordinates
{
private:
    int x;
    int y;

public:
    Coordinates(int X, int Y);

    bool operator==(const Coordinates& other) const;
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);

    std::string get() const;
};

#endif
