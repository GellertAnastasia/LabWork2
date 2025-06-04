#include <gtest/gtest.h>
#include "addPower.h"

TEST(AddPowerTest, SettersAndGetters)
{
    AddPower imp;
    imp.setPoints(100);
    EXPECT_EQ(imp.getPoints(), 100);
}

