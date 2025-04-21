#include "farm.h"

Farm::Farm(Player* owner) : owner(owner)
{
    setCell("⛃");
    setCost(3);
}

void Farm::setProfit(int value)
{
    profit = value;
}
int Farm::getProfit() const
{
    return profit;
}

std::string Farm::getName() const
{
    if (getLocation() != nullptr)
    {
        return "Farm" + getLocation()->get() + ": " + std::to_string(health) + HEALTH;
    }
    else
    {
        return "Farm: " + std::to_string(health) + HEALTH;
    }
}

int Farm::bringMoney()
{
    if (owner)
    {
        owner->addMoney(profit);
        clearScreen();
        return profit;
    }
    return 0;
}

