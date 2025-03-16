#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "../character/character.h"

class Player
{
public:
    Player(int Mana, int Money, int Color);

    int mana;
    int money;
    int color = 0;
    
    std::vector<std::shared_ptr<Character>> inventory;
    std::vector<std::shared_ptr<Character>> charactersOnGrid;
    std::vector<std::shared_ptr<Coordinates>> location;
    
    void printInventory();
    void printCharactersOnGrid();
};


#endif
