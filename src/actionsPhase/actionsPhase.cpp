#include "actionsPhase.h"

ActionsPhase::ActionsPhase(Field& field) : field(field), fieldUI(field) {} 

void ActionsPhase::start(Field& field, Player& player, Player& enemy) {
    bool actionsPhase = true;
    while(actionsPhase) {
        fieldUI.draw(player, enemy);
        std::cout << "Character action phase:\n\n";
        std::cout << "Choose a character\n";
        player.printCharactersOnGrid();
        std::cout << player.charactersOnGrid.size()+1 << ". End your turn\nYour choice: ";
        size_t choice;
        std::cin >> choice;

        if (choice == player.charactersOnGrid.size()+1) {
            std::cout << "next turn\n";
            pause();
            break;
        } else if(choice <= 0 || choice > player.charactersOnGrid.size()) {
            continue;
        }

        std::shared_ptr<Object> current = player.charactersOnGrid[choice-1];
        if (current->hasActed) {
            std::cout << "acted\n";
            pause();
            continue;
        }

        fieldUI.draw(player, enemy);
        std::cout << "Choose an action\n";
        std::cout << "1. moving\n2. attack\nYour choice: ";
        size_t action;
        std::cin >> action;

        if (action == 1) {
            current->hasActed = true;
            moveCharacter(choice, player, enemy, field);
            continue;
        } else if (action == 2) {
            current->hasActed = true;
            attack(choice, player, enemy, field);
            pause();
            if (player.base->health <= 0 || enemy.base->health <= 0) {
                actionsPhase = false;
            }
            continue;
        } else if (action == 3) {
            actionsPhase = false;
        } else {
        }
    }
}

void ActionsPhase::moveCharacter(size_t choice, Player& player, Player& enemy, Field& field) {

    auto& character = player.charactersOnGrid[choice - 1];
    fieldUI.draw(player, enemy);
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
    fieldUI.draw(player, enemy);
}

void ActionsPhase::attack(size_t choice, Player& player, Player& enemy, Field& field) {
    fieldUI.draw(player, enemy);
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
