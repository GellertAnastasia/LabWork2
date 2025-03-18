#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "../base/base.h"
#include "../character/character.h"

class Player
{
public:
    Player(int Mana, int Money, int Color, std::shared_ptr<Base>& b);

    int mana;
    int money;
    int color = 0;
    std::shared_ptr<Base> base;
    
    std::vector<std::shared_ptr<Object>> inventory;
    std::vector<std::shared_ptr<Object>> charactersOnGrid;
    std::vector<std::shared_ptr<Coordinates>> location;
    
    void printInventory();
    void printCharactersOnGrid();
};


#endif
