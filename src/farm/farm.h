#ifndef FARM_H
#define FARM_H
#include <memory>
#include "../player/player.h"
#include "../object/object.h"

class Farm : public Object {
public:
    int profit = 1;
    Player* owner;

    Farm(Player* owner);
    std::string getName() const override;
    void bringMoney();
};

#endif
