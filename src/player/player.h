#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "../base/base.h"
#include "../character/character.h"
#include "../zone/zone.h"

class Player
{
public:
    Player(int Mana, int Money, int Color, const Zone& zone);

    int mana;
    int money;
    int color = 0;

    std::shared_ptr<Base> base;
    Zone zone;
    
    std::vector<std::shared_ptr<Card>> inventory;
    std::vector<std::shared_ptr<Character>> charactersOnGrid;
    
    int getMana() const;
    
    bool isInsideZone(int x, int y);
    void addMoney(int profit);
    void printInventory();
    void printCharactersOnGrid();
    void changeMana(int points);
    
};


#endif
