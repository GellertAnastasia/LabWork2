#include <gmock/gmock.h>
#include "fieldUI.h"
#include "playingCards.h"

class MockPlayer : public Player {
public:
    MockPlayer(int Mana)
        : Player(Mana, 0, 0, Zone(1, 10, 1, 4)) {}
    MOCK_METHOD(int, getMana, (), (const override));
    MOCK_METHOD(void, changeMana, (int points), (override));
    MOCK_METHOD(bool, isInsideZone, (int x, int y), (override));
    MOCK_METHOD(void, printCharactersOnGrid, (), (override));
    int mana;
    std::vector<std::shared_ptr<Character>> charactersOnGrid;
};

class MockField : public Field {
public:
    MOCK_METHOD(bool, isEmpty, (Player& player), (override));
    MOCK_METHOD(bool, placeNewCharacter, (
        Player& player,
        const std::shared_ptr<Coordinates>& coords,
        std::shared_ptr<Object> character
    ), (override));
};

class MockFieldUI : public FieldUI {
public:
    MockFieldUI(Field& field) : FieldUI(field) {}
    MOCK_METHOD(void, draw, (Player& player, Player& enemy), (override));
};

TEST(PlayingCardsTest, Characters_NoSpace_ReturnsFalse) 
{
    MockPlayer player(0);
    MockPlayer enemy(0);
    MockField field;
    MockFieldUI fieldUI(field);
    EXPECT_CALL(field, isEmpty(testing::Ref(player))).WillOnce(testing::Return(false));
    PlayingCards cards(player, enemy, field, fieldUI);
    auto obj = std::make_shared<Object>();
    bool result = cards.characters(obj);
    ASSERT_FALSE(result);
    EXPECT_EQ(player.getMana(), 0); 
}

TEST(PlayingCardsTest, Characters_NotEnoughMana_ReturnsFalse) {
    MockPlayer player(0);
    MockPlayer enemy(0);
    MockField field;
    MockFieldUI fieldUI(field);
    EXPECT_CALL(field, isEmpty(testing::Ref(player))).WillOnce(testing::Return(true));
    PlayingCards cards(player, enemy, field, fieldUI);
    auto obj = std::make_shared<Object>();
    bool result = cards.characters(obj);
    ASSERT_FALSE(result);
    EXPECT_EQ(player.getMana(), 0);
}

