#include "cardsPhase.h"

CardsPhase::CardsPhase(Field& field) : field(field), fieldUI(field) {}

void CardsPhase::start(Field& field, Player& player, Player& enemy) {
    bool cardsPhase = true;
    while(cardsPhase) {
        fieldUI.draw(player, enemy);
        std::cout << "Card playing phase\n\n";
        std::cout << "Choose an action\n";
        std::cout << "1. Play card\n2. Buy card\n3. Go next step\nYour choice: ";
        size_t choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    bool played = false;
    while (played != true) {
    fieldUI.draw(player, enemy);
    player.printInventory();
    std::cout << player.inventory.size()+1 << ". Back\n";
    std::cout << "Your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice == player.inventory.size()+1) {
            return;
        } else if ((choice < 1) || (choice > player.inventory.size()+1)) {
            continue;
        } else {
            auto objectPtr = std::dynamic_pointer_cast<Object>(player.inventory[choice-1]);
            auto improvePtr = std::dynamic_pointer_cast<Improvement>(player.inventory[choice-1]);
            if (objectPtr) {
                fieldUI.draw(player, enemy);
                int x,y;
                bool added = false;
                while (added != true) {
                    bool coord = false;
                    while (coord != true) {
                    fieldUI.draw(player, enemy);
                    std::cout << "Write the coordinates: ";
                    if (!(std::cin >> x)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    else if (!(std::cin >> y)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    else if (x < player.zone.getMinX() || x > player.zone.getMaxX() || y < player.zone.getMinY() || y > player.zone.getMaxY()) {
                        std::cout << "Coordinates out of your zone\n";
                        pause();
                        continue;
                    } else {
                    coord = true;
                    }
                    }
                    added = field.addCharacter(player, std::make_shared<Coordinates>(x,y), objectPtr);
                }
                //player.mana -= 1;
                player.inventory.erase(player.inventory.begin() + choice-1);
                played = true;
            } else {
                if (player.charactersOnGrid.size()<=0) {
                    std::cout << "no characters on field. try again\n";
                    pause();
                    continue;
                } else {
                    size_t choice1;
                    fieldUI.draw(player, enemy);
                    player.printCharactersOnGrid();
                    std::cout << "Your choice: ";
                    std::cin >> choice1;
                    improvePtr->addPoints(player.charactersOnGrid[choice1-1]);
                    pause();
                    player.inventory.erase(player.inventory.begin() + choice-1);
                    played = true;
                }
            }
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
