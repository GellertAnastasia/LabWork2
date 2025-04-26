#include <gtest/gtest.h>
#include "card.h"

TEST(CardTest, SettersAndGetters) {
    Card card;    
    card.setCost(100);
    EXPECT_EQ(card.getCost(), 100);
}
