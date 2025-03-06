#include <memory>
#include "field.h"

Field::Field() : grid(HEIGHT, std::vector<Object>(WIDTH)), full(HEIGHT, std::vector<bool>(WIDTH, false)) {}

void Field::addObject(int x, int y) 
{
    if (x >= 0 && x < WIDTH+1 && y >= 0 && y < HEIGHT+1) {
        full[y-1][x-1] = true;
    }
}



void drawField(Field field) {
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
                std::cout <<"X";
                //std::cout << field.grid[y][x].cell;
                }
            if (x != WIDTH - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}

