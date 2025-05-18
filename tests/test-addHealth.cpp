#include <gtest/gtest.h>
#include "addHealth.h"

TEST(AddHealthTest, SettersAndGetters) {
    AddHealth imp;
    imp.setPoints(100);
    EXPECT_EQ(imp.getPoints(), 100);
}

