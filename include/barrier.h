#ifndef BARRIER_H
#define BARRIER_H
#include "object.h"

class Barrier : public Object
{
public:
    Barrier();
    std::string getName() const override;
};

#endif
