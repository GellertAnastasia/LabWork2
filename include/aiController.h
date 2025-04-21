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

    void makeMove(Field& field, Player& enemy);
    void playRandomCard(Field& field, Player& enemy);
    void buyRandomCard();
    bool shouldBuyCard() const;
    bool shouldPlayCard() const;

    void makeActionsMove(Field& field, Player& enemy);
    bool aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy, Field& field);
    bool aiAttack(std::shared_ptr<Character> attacker, Player& enemy, Field& field);
    std::shared_ptr<Object> selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy);

private:
    Player& player;
    Field& field;
    FieldUI fieldUI;
};

#endif
