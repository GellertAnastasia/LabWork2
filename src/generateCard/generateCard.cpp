#include "generateCard.h"

std::shared_ptr<Object> generateCard(Player* owner) {
    int randomValue = rand() % 4;
    if (randomValue == 0) {
        return std::make_shared<Fighter>();
    } else if (randomValue == 1) {
            return std::make_shared<Wizard>();
    } else if (randomValue == 2) {
            return std::make_shared<Archer>();
    } else if (randomValue == 3) {
            return std::make_shared<Farm>(owner);
    } else {
            return std::make_shared<Barrier>();
    }
}
