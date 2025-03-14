#include "generateCard.h"

std::shared_ptr<Character> generateCard() {
    int randomValue = rand() % 3;
    if (randomValue == 0) {
        return std::make_shared<Fighter>();
    } else if (randomValue == 1) {
            return std::make_shared<Wizard>();
    } else {
            return std::make_shared<Archer>();
    }
}
