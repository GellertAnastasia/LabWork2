#include "cardsPhase.h"

CardsPhase::CardsPhase(Field& field) : field(field), fieldUI(field) {} 

void CardsPhase::start(Field& field, Player& player, Player& enemy) {
    field.processFarmsIncome(player);
    bool cardsPhase = true;
    while(cardsPhase) {
        fieldUI.draw(player, enemy);
        std::cout << "Card playing phase\n\n";
        std::cout << "Choose an action\n";
        std::cout << "1. Play card\n2. Buy card\n3. Go next step\nYour choice: ";
        size_t choice;
        std::cin >> choice;
        if (choice == 1) {
            playCard(field, player, enemy);
        } else if (choice == 2) {
            buyCard(player);
            pause();
        } else if (choice == 3) {
            cardsPhase = false;
        } else {
        }
    }
}


void CardsPhase::playCard(Field& field, Player& player, Player& enemy) {
    size_t choice;
    fieldUI.draw(player, enemy);
    player.printInventory();
    std::cout << "Your choice: ";
    std::cin >> choice;
    auto objectPtr = std::dynamic_pointer_cast<Object>(player.inventory[choice-1]);
    auto improvePtr = std::dynamic_pointer_cast<Improvement>(player.inventory[choice-1]);
    if (objectPtr) {
        fieldUI.draw(player, enemy);
        int x,y;
        bool added = false;
        while (added != true) {
            fieldUI.draw(player, enemy);
            std::cout << "Write the coordinates: ";
            std::cin >> x >> y;
            added = field.addCharacter(player, std::make_shared<Coordinates>(x,y), objectPtr);
        }
        //player.mana -= 1;
        player.inventory.erase(player.inventory.begin() + choice-1);
        fieldUI.draw(player, enemy);
        player.printInventory();
    } else {
        if (player.charactersOnGrid.size()<=0) {
            std::cout << "no characters on field. try again\n";
            pause();
            return;
        } else {
            size_t choice1;
            fieldUI.draw(player, enemy);
            player.printCharactersOnGrid();
            std::cout << "Your choice: ";
            std::cin >> choice1;
            improvePtr->addPoints(player.charactersOnGrid[choice1-1]);
            pause();
        }
    }
}

void CardsPhase::buyCard(Player& player) {
    if (player.money >= 1) {
        player.money -= 1;
        auto character = generateCard(&player);
        player.inventory.push_back(character);
        std::cout << character->getName() << " added to inventory\n";
    } else {
       std::cout << "not enough money\n";
    }
}
