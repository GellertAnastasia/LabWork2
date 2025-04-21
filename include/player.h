#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "base.h"
#include "character.h"
#include "zone.h"

class Player
{
private:
    int mana;
    int money;
    int color = 0;
public:
    Player(int Mana, int Money, int Color, const Zone& zone);

    std::shared_ptr<Base> base;
    Zone zone;
    std::vector<std::shared_ptr<Card>> inventory;
    std::vector<std::shared_ptr<Character>> charactersOnGrid;

    int getMana() const;
    int getMoney() const;
    int getColor() const;

    bool isInsideZone(int x, int y);
    void addMoney(int profit);
    void printInventory();
    void printCharactersOnGrid();
    void changeMana(int points);

};


#endif
