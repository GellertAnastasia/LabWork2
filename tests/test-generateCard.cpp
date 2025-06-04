#include <gtest/gtest.h>
#include <memory>
#include <set>
#include "generateCard.h"

TEST(GenerateCardTest, GeneratesAllCardTypes)
{
    Zone zone(1, 10, 1, 4);
    Player owner(3, 3, 94, zone);
    std::set<std::string> generatedTypes;
    const int iterations = 1000;
    for (int i = 0; i < iterations; ++i)
    {
        auto card = generateCard(&owner);

        if (dynamic_cast<Fighter*>(card.get()) != nullptr)
        {
            generatedTypes.insert("Fighter");
        }
        else if (dynamic_cast<Wizard*>(card.get()) != nullptr)
        {
            generatedTypes.insert("Wizard");
        }
        else if (dynamic_cast<Archer*>(card.get()) != nullptr)
        {
            generatedTypes.insert("Archer");
        }
        else if (dynamic_cast<Farm*>(card.get()) != nullptr)
        {
            generatedTypes.insert("Farm");
        }
        else if (dynamic_cast<Barrier*>(card.get()) != nullptr)
        {
            generatedTypes.insert("Barrier");
        }
        else if (dynamic_cast<AddHealth*>(card.get()) != nullptr)
        {
            generatedTypes.insert("AddHealth");
        }
        else if (dynamic_cast<AddPower*>(card.get()) != nullptr)
        {
            generatedTypes.insert("AddPower");
        }
    }
    EXPECT_EQ(generatedTypes.size(), 7u);
}
