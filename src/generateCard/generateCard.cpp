#include "generateCard.h"

std::shared_ptr<Card> generateCard(Player* owner) {
    int randomValue = rand() %7;
    if (randomValue == 0) {
        return std::make_shared<Fighter>();
    } else if (randomValue == 1) {
            return std::make_shared<Wizard>();
    } else if (randomValue == 2) {
            return std::make_shared<Archer>();
    } else if (randomValue == 3) {
            return std::make_shared<Farm>(owner);
    } else if (randomValue == 4) {
            return std::make_shared<Barrier>();
    } else if (randomValue == 5) {
            return std::make_shared<AddHealth>();
    } else {
            return std::make_shared<LevelUp>();
    }
}
