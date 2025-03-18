#ifndef ADDHEALTH_H
#define ADDHEALTH_H
#include "../improvement/improvement.h"

class AddHealth: public Improvement
{
public:
    
    void setPoints(char value);
    int getPoints() const;
    std::string getName() const override;
    
    void addPoints(std::shared_ptr<Character>& character) override;
};

#endif
