#include <gtest/gtest.h>
#include <vector>
#include "character.h"

TEST(CharacterTest, PowerManagement) {
    Character character;
    character.setPower(5);
    EXPECT_EQ(character.getPower(), 5);
}

TEST(CharacterTest, SetMoveDirections) {
    Character character;
    std::vector<std::pair<int, int>> new_dirs = {{2, -1}, {0, 3}};
    character.setDirectionOfMove(new_dirs);
    const auto& directions = character.getDirectionOfMove();
    ASSERT_EQ(directions.size(), 2);
    EXPECT_EQ(directions[0], (std::pair<int, int>{2, -1}));
    EXPECT_EQ(directions[1], (std::pair<int, int>{0, 3}));
}

TEST(CharacterTest, SetAttackDirections) {
    Character character;
    std::vector<std::pair<int, int>> new_dirs = {{2, 2}, {3, 0}};
    character.setDirectionOfAttack(new_dirs);
    const auto& directions = character.getDirectionOfAttack();
    ASSERT_EQ(directions.size(), 2);
    EXPECT_EQ(directions[0], (std::pair<int, int>{2, 2}));
    EXPECT_EQ(directions[1], (std::pair<int, int>{3, 0}));
}
