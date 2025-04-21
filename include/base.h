#ifndef BASE_H
#define BASE_H
#include "coordinates.h"
#include "object.h"

class Base : public Object
{
public:
    Base(int value);
    std::string getName() const override;
};

#endif
