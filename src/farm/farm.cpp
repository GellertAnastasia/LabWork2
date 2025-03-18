#include "farm.h"

Farm::Farm(Player* owner) : owner(owner) {
    setCell('M');
}

std::string Farm::getName() const {
        return "Farm (hp: "+ std::to_string(health)+")";
}

void Farm::bringMoney() {
    if (owner) {
        owner->addMoney(profit);
        clearScreen();
        std::cout << "Farm brought you money: " << profit << "\n";
        pause();
    }
}

void pause() {
    std::cout << "Click Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}

