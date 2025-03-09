#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "../character/character.h"

class Player
{
public:
    Player(int Mana, int Money);

    int mana;
    int money;
    
    std::vector<std::shared_ptr<Character>> inventory;
    
    void printInventory();
};


#endif
