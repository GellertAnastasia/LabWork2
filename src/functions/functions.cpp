#include "functions.h"

void playCard(Player& player, Field& field) {
    drawField(field, player);

    player.printInventory();

    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;
    drawField(field, player);
    int x,y;
    std::cout << "Write the coordinates: ";
    std::cin >> x >> y;
    field.addCharacter(player, std::make_shared<Coordinates>(x,y), player.inventory[choice-1]);
    //player.mana -= 1;
    player.inventory.erase(player.inventory.begin() + choice-1);
    drawField(field, player);
    player.printInventory();
}

void moveCharacter(int choice, Player& player, Field& field) {
    drawField(field, player);
    std::cout << "Choose the coordinates:\n";
    player.charactersOnGrid[choice-1]->calculateMovement(player.location[choice-1], field.full);
    player.charactersOnGrid[choice-1]->printMovement();
    int choice1;
    std::cin >> choice1;
    field.addCharacter(player, player.charactersOnGrid[choice-1]->movement[choice1-1], player.charactersOnGrid[choice-1]);
    player.charactersOnGrid[choice-1]->movement.clear();
    field.deleteObject(choice, player);
    drawField(field, player);
}
/*
void attack(Player& player, Field& field) {
    drawField(field, player);
    std::cout << "Choose a character\n";
    player.printCharactersOnGrid();
    int choice;
    std::cin >> choice;
    drawField(field, player);
    std::cout << "Choose the coordinates:\n";
    player.charactersOnGrid[choice-1]->calculateAttack(field.location[choice-1], field.location);
    player.charactersOnGrid[choice-1]->printAttack();
    int choice1;
    std::cin >> choice1;
}
*/
void pause() {
     std::cout << "Click Enter to continue...";
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     std::cin.get();
}
