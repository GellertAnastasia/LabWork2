#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "func.h" 
#include "constants.h"
#include "coordinates.h"
#include "object.h"

TEST(FuncTest, IsWithinBounds) 
{
    EXPECT_TRUE(isWithinBounds(std::make_shared<Coordinates>(5, 5)));
    EXPECT_TRUE(isWithinBounds(std::make_shared<Coordinates>(WIDTH, HEIGHT)));
    EXPECT_FALSE(isWithinBounds(std::make_shared<Coordinates>(WIDTH + 1, 5)));
    EXPECT_FALSE(isWithinBounds(std::make_shared<Coordinates>(5, HEIGHT + 1)));
}


TEST(FuncTest, IsFree) 
{
    std::vector<std::vector<std::shared_ptr<Object>>> grid(HEIGHT, std::vector<std::shared_ptr<Object>>(WIDTH, nullptr));

    EXPECT_FALSE(isFree(std::make_shared<Coordinates>(5, 1), grid));
    EXPECT_FALSE(isFree(std::make_shared<Coordinates>(6, 1), grid));
    EXPECT_FALSE(isFree(std::make_shared<Coordinates>(5, 10), grid));
    EXPECT_FALSE(isFree(std::make_shared<Coordinates>(6, 10), grid));

    EXPECT_TRUE(isFree(std::make_shared<Coordinates>(1, 1), grid));
    grid[3][3] = std::make_shared<Object>();
    EXPECT_FALSE(isFree(std::make_shared<Coordinates>(4, 4), grid));
}
