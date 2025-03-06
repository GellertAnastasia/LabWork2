#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "../character/character.h"

class Player
{
public:
    int money = 0;
    int mana = 5;
    std::vector<std::shared_ptr<Character>> inventory;
    
    void printInventory();
};


#endif
