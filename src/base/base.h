#ifndef BASE_H
#define BASE_H
#include "../coordinates/coordinates.h"
#include "../object/object.h"

class Base : public Object
{
public:
    Base();
    std::string getName() const override;
};

#endif
