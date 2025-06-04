#include <gtest/gtest.h>
#include "coordinates.h"

TEST(CoordinatesTest, EqualityOperator)
{
    Coordinates pos1(2, 5);
    Coordinates pos2(2, 5);
    Coordinates pos3(3, 5);
    Coordinates pos4(2, 6);
    EXPECT_TRUE(pos1 == pos2);
    EXPECT_FALSE(pos1 == pos3);
    EXPECT_FALSE(pos1 == pos4);
    EXPECT_FALSE(pos3 == pos4);
}

TEST(CoordinatesTest, SettersAndGetters)
{
    Coordinates pos(0, 0);
    pos.setX(5);
    pos.setY(7);
    EXPECT_EQ(pos.getX(), 5);
    EXPECT_EQ(pos.getY(), 7);
}

TEST(CoordinatesTest, StringRepresentation)
{
    Coordinates pos1(3, 5);
    EXPECT_EQ(pos1.get(), "(3,5)");
}
