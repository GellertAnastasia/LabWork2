/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

#include "playingCards.h"
#include <limits>

bool PlayingCards::characters(std::shared_ptr<Object> object) {
    if (!field.isEmpty(player)) {
        std::cout << "There is no place for objects\n";
        return false;
    }

    if (object->getCost() > player.getMana()) {
        std::cout << "Not enough mana\n";
        return false;
    }

    player.changeMana(-object->getCost());
    
    int x, y;
    bool placed = false;
    while (!placed) {
        if (!readCoordinates(x, y)) continue;
        
        placed = field.placeNewCharacter(
            player, 
            std::make_shared<Coordinates>(x, y), 
            object
        );
    }
    return true;
}

bool PlayingCards::improvements(std::shared_ptr<Improvement> improvement) {
    if (player.charactersOnGrid.empty()) {
        std::cout << "No characters on field\n";
        return false;
    }

    if (improvement->getCost() > player.getMana()) {
        std::cout << "Not enough mana\n";
        return false;
    }

    size_t choice;
    bool valid = false;
    while (!valid) {
        fieldUI.draw(player, enemy);
        player.printCharactersOnGrid();
        std::cout << "Your choice: ";
        
        if (!(std::cin >> choice) || choice < 1 || choice > player.charactersOnGrid.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input\n";
            continue;
        }
        valid = true;
    }

    player.changeMana(-improvement->getCost());
    improvement->addPoints(player.charactersOnGrid[choice - 1]);
    return true;
}

bool PlayingCards::readCoordinates(int& x, int& y) {
    fieldUI.draw(player, enemy);
    std::cout << "Write coordinates: ";
    
    if (!(std::cin >> x >> y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if (!player.isInsideZone(x, y)) {
        std::cout << "Coordinates out of zone\n";
        pause_();
        return false;
    }
    return true;
}

