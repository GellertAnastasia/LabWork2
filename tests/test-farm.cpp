#include <gtest/gtest.h>
#include "farm.h"
#include "player.h"
#include "zone.h"

TEST(FarmTest, ProfitGettersAndSetters)
{
    Zone zone(1, 10, 1, 10);
    Player player(3, 3, 94, zone);
    Farm farm(&player);
    farm.setProfit(5);
    EXPECT_EQ(farm.getProfit(), 5);
}

TEST(FarmTest, BringMoneyFunctionality)
{
    Zone zone(1, 10, 1, 10);
    Player player(0, 0, 0, zone);
    Farm farm(&player);

    EXPECT_EQ(farm.bringMoney(), 1);
    EXPECT_EQ(player.getMoney(), 1);
}
