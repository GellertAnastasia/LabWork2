#include <gtest/gtest.h>
#include <memory>
#include "object.h"
#include "coordinates.h" 

TEST(ObjectTest, CellSettersAndGetters) 
{
    Object obj;
    obj.setCell("&");
    EXPECT_EQ(obj.getCell(), "&");

}

TEST(ObjectTest, ColorSettersAndGetters) 
{
    Object obj;
    obj.setColor(5);
    EXPECT_EQ(obj.getColor(), 5);
}

TEST(ObjectTest, HealthSettersAndGetters) 
{
    Object obj;
    obj.setHealth(100);
    EXPECT_EQ(obj.getHealth(), 100);
}

TEST(ObjectTest, LocationSettersAndGetters) 
{
    Object obj;
    auto coord = std::make_shared<Coordinates>(10, 20);
    obj.setLocation(coord);
    auto loc = obj.getLocation();
    ASSERT_NE(loc, nullptr);
    EXPECT_EQ(loc->getX(), 10);
    EXPECT_EQ(loc->getY(), 20);
}

TEST(ObjectTest, ChangeHealth) 
{
    Object obj;
    obj.setHealth(50);
    obj.changeHealth(10);
    EXPECT_EQ(obj.getHealth(), 60);
    obj.changeHealth(-20);
    EXPECT_EQ(obj.getHealth(), 40);
    obj.changeHealth(0);
    EXPECT_EQ(obj.getHealth(), 40);
}
