#include <gtest/gtest.h>
#include "addHealth.h"

TEST(ImprovementTest, SettersAndGetters) 
{
    AddHealth imp;
    imp.setPoints(42);
    EXPECT_EQ(imp.getPoints(), 42);
}
