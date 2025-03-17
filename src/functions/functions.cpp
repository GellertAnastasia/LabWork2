#include "functions.h"

void playCard(Player& player, Player& enemy, Field& field) {
    int choice;
    drawField(field, player, enemy);
    player.printInventory();
    std::cout << "Your choice: ";
    std::cin >> choice;
    drawField(field, player, enemy);
    int x,y;
    bool added = false;
    while (added != true) {
        drawField(field, player, enemy);
        std::cout << "Write the coordinates: ";
        std::cin >> x >> y;
        added = field.addCharacter(player, std::make_shared<Coordinates>(x,y), player.inventory[choice-1]);
    }
    //player.mana -= 1;
    player.inventory.erase(player.inventory.begin() + choice-1);
    drawField(field, player, enemy);
    player.printInventory();
}

void moveCharacter(int choice, Player& player, Player& enemy, Field& field) {
    drawField(field, player, enemy);
    std::cout << "Choose the coordinates:\n";
    player.charactersOnGrid[choice-1]->calculateMovement(player.location[choice-1], field.grid);
    player.charactersOnGrid[choice-1]->printMovement();
    int choice1;
    std::cin >> choice1;
    field.addCharacter(player, player.charactersOnGrid[choice-1]->movement[choice1-1], player.charactersOnGrid[choice-1]);
    player.charactersOnGrid[choice-1]->movement.clear();
    field.deleteObject(choice, player);
    drawField(field, player, enemy);
}

void attack(int choice, Player& player, Player& enemy, Field& field) { 
    drawField(field, player, enemy);
    std::cout << "Choose the coordinates:\n"; 
    auto& attacker = player.charactersOnGrid[choice-1];
    attacker->calculateAttack(player.location[choice-1], field.grid);
    attacker->printAttack(); 

    int targetChoice;
    std::cin >> targetChoice; 
    auto& target = attacker->attack[targetChoice-1];
    addHealth(target, -attacker->power);
    std::cout << "Health after attack: " << target->health << "\n";

    if (target->health <= 0) {
        auto it = std::find(
        enemy.charactersOnGrid.begin(), 
        enemy.charactersOnGrid.end(), 
        target
        );
        if (it != enemy.charactersOnGrid.end()) {
            size_t index = std::distance(enemy.charactersOnGrid.begin(), it);
            enemy.charactersOnGrid.erase(it);
            enemy.location.erase(enemy.location.begin() + index);
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
