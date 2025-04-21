#ifndef ADDHEALTH_H
#define ADDHEALTH_H
#include "improvement.h"

class AddHealth: public Improvement
{
public:
    std::string getName() const override;

    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
