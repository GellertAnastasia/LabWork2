#include <gtest/gtest.h>
#include "zone.h"

TEST(ZoneTest, SettersAndGetters) {
    Zone zone;
    
    zone.setMinX(3);
    EXPECT_EQ(zone.getMinX(), 3);
    
    zone.setMaxX(7);
    EXPECT_EQ(zone.getMaxX(), 7);
    
    zone.setMinY(4);
    EXPECT_EQ(zone.getMinY(), 4);
    
    zone.setMaxY(9);
    EXPECT_EQ(zone.getMaxY(), 9);
}
