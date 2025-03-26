#ifndef BASE_H
#define BASE_H
#include "../coordinates/coordinates.h"
#include "../object/object.h"

class Base : public Object
{
public:
    Base(int value);
    std::string getName() const override;
};

#endif
