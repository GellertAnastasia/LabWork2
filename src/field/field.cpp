#include "field.h"

Field::Field() : grid(HEIGHT, std::vector<Object>(WIDTH)), full(HEIGHT, std::vector<bool>(WIDTH, false)) {}

void Field::addObject(Player player, Coordinates coordinates, std::shared_ptr<Object> object) 
{
    int x = coordinates.x;
    int y = coordinates.y;
    if (x >= 0 && x < WIDTH+1 && y >= 0 && y < HEIGHT+1) {
        full[y-1][x-1] = true;
        charactersOnGrid.push_back(object);
        place.push_back(coordinates);
        //player.mana = player.mana - 1;
        
    }
}

void Field::deleteObject(int choice)
{
    int x = place[choice-1].x;
    int y = place[choice-1].y;
    if (x >= 0 && x < WIDTH+1 && y >= 0 && y < HEIGHT+1) {
        full[y-1][x-1] = false;
        charactersOnGrid.erase(charactersOnGrid.begin() + choice-1);
        place.erase(place.begin() + choice-1);
    }
}

void Field::printCharactersOnGrid() {
    for (size_t i = 0; i < charactersOnGrid.size(); ++i) {
        if (charactersOnGrid[i]) {
            std::cout << i+1 << ". " << charactersOnGrid[i]->getName() << "\n";
        } else {
            std::cout << i+1 << ". empty\n";
        }
    }
}


void drawField(Field field, Player player) {
    std::cout << "  ";
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << x + 1;
        if (x != WIDTH - 1) std::cout << " ";
    }
    std::cout << "\n";


    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << static_cast<char>('A' + y) << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if (field.full[y][x] == false) {
                std::cout << EMPTY_CELL;
                } else {
                std::cout << field.grid[y][x].cell;
                }
            if (x != WIDTH - 1) std::cout << " ";
        }
        if (y == 1) {
        std::cout << "     " << "╎" << "   mana: " << player.mana;
        } else if (y == 2) {
        std::cout << "     " << "╎" << "   money: " << player.money;
        } else {
        std::cout << "     " << "╎";
        }
        std::cout << "\n";
    }
}

