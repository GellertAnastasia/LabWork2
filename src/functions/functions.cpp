#include "functions.h"

void playCard(Player& player, Player& enemy, Field& field) {
    size_t choice;
    drawField(field, player, enemy);
    player.printInventory();
    std::cout << "Your choice: ";
    std::cin >> choice;
    auto objectPtr = std::dynamic_pointer_cast<Object>(player.inventory[choice-1]);
    auto improvePtr = std::dynamic_pointer_cast<Improvement>(player.inventory[choice-1]);
    if (objectPtr) {
        drawField(field, player, enemy);
        int x,y;
        bool added = false;
        while (added != true) {
            drawField(field, player, enemy);
            std::cout << "Write the coordinates: ";
            std::cin >> x >> y;
            added = field.addCharacter(player, std::make_shared<Coordinates>(x,y), objectPtr);
        }
        //player.mana -= 1;
        player.inventory.erase(player.inventory.begin() + choice-1);
        drawField(field, player, enemy);
        player.printInventory();
    } else {
        if (player.charactersOnGrid.size()<=0) {
            std::cout << "no characters on field. try again\n";
            pause();
            return;
        } else {
            size_t choice1;
            drawField(field, player, enemy);
            player.printCharactersOnGrid();
            std::cout << "Your choice: ";
            std::cin >> choice1;
            improvePtr->addPoints(player.charactersOnGrid[choice1-1]);
            pause();
        }
    }
}

    void moveCharacter(size_t choice, Player& player, Player& enemy, Field& field) {

        auto& character = player.charactersOnGrid[choice - 1];
        drawField(field, player, enemy);
        character->calculateMovement(character->location, field.grid);
        if (character->movement.empty()) {
            std::cout << "No available moves!\n";
            pause();
            return;
        }
        std::cout << "Choose the coordinates:\n";
        character->printMovement();
        size_t choice1;
        std::cin >> choice1;
        if (choice1 < 1 || choice1 > character->movement.size()) {
            std::cout << "Invalid coordinate choice!\n";
            pause();
            return;
        }

        auto newCoords = character->movement[choice1 - 1];
        field.deleteObject(character->location, player);
        character->location = newCoords;
        field.addCharacter(player, newCoords, character);
        character->movement.clear();
        drawField(field, player, enemy);
    }

    void attack(size_t choice, Player& player, Player& enemy, Field& field) {
        drawField(field, player, enemy);
        std::cout << "Choose the coordinates:\n";
        auto& attacker = player.charactersOnGrid[choice-1];
        attacker->calculateAttack(attacker->location, field.grid);
        attacker->printAttack();

        size_t targetChoice;
        std::cin >> targetChoice;
        auto& target = attacker->attack[targetChoice-1];
        target->changeHealth(-attacker->power-attacker->level);
        std::cout << "Health after attack: " << target->health << "\n";

        if (target->health <= 0) {
            auto it = std::find(
                          enemy.charactersOnGrid.begin(),
                          enemy.charactersOnGrid.end(),
                          target
                      );
            if (it != enemy.charactersOnGrid.end()) {
                enemy.charactersOnGrid.erase(it);
            }
            for (size_t y = 0; y < field.grid.size(); ++y) {
                for (size_t x = 0; x < field.grid[y].size(); ++x) {
                    const auto& obj = field.grid[y][x];
                    if (obj == target) {
                        field.grid[y][x] = nullptr;
                    }
                }
            }
        }
        attacker->attack.clear();
    }
