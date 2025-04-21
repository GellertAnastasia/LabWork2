#ifndef FARM_H
#define FARM_H
#include <memory>
#include "player.h"
#include "object.h"

class Farm : public Object
{
private:
    int profit = 1;
public:
    Player* owner;

    void setProfit(int value);
    int getProfit() const;

    Farm(Player* owner);
    std::string getName() const override;
    int bringMoney();
};

#endif
