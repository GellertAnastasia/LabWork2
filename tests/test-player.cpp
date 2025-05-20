#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <string>
#include "player.h"

TEST(PlayerTest, ConstructorAndGetters) 
{
    Zone zone(1, 5, 1, 5);
    Player player(100, 200, 3, zone);
    EXPECT_EQ(player.getMana(), 100);
    EXPECT_EQ(player.getMoney(), 200);
    EXPECT_EQ(player.getColor(), 3);
}

TEST(PlayerTest, IsInsideZone) 
{
    Zone zone(1, 5, 1, 5);
    Player player(0, 0, 0, zone);
    EXPECT_TRUE(player.isInsideZone(1, 1));
    EXPECT_FALSE(player.isInsideZone(0, 3));
}

TEST(PlayerTest, AddMoney) 
{
    Zone zone(0, 0, 0, 0);
    Player player(0, 100, 0, zone);
    player.addMoney(50);
    EXPECT_EQ(player.getMoney(), 150);
}

TEST(PlayerTest, ChangeMana) 
{
    Zone zone(0, 0, 0, 0);
    Player player(100, 0, 0, zone);
    player.changeMana(-50);
    EXPECT_EQ(player.getMana(), 50);
}

