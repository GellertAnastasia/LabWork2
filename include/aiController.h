#ifndef AICONTROLLER_H
#define AICONTROLLER_H
#include <cstdlib>
#include <ctime>
#include <climits>
#include "player.h"
#include "field.h"
#include "fieldUI.h"
#include "generateCard.h"
#include "improvement.h"


class AIController
{
public:
    AIController(Player& player, Field& field);

    void makeMove(Player& enemy);
    void playRandomCard(Player& enemy);
    void buyRandomCard();
    bool shouldBuyCard() const;
    bool shouldPlayCard() const;

    void makeActionsMove(Player& enemy);
    bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy);
    bool aiAttack(std::shared_ptr<Character> attacker, Player& enemy);
    std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy);

private:
    Player& player;
    Field& field;
    FieldUI fieldUI;
};

#endif
