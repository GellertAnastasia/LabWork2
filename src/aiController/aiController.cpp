#include "aiController.h"

AIController::AIController(Player& player, Field& field) : player(player), field(field), fieldUI(field)
{
    std::srand(std::time(0));
}

void AIController::makeMove(Field& field, Player& enemy)
{
    fieldUI.draw(player, enemy);
    pause();
    while (shouldBuyCard())
    {
        buyRandomCard();
    }
    while(!player.inventory.empty() && shouldPlayCard())
    {
        playRandomCard(field, enemy);
    }

}

void AIController::playRandomCard(Field& field, Player& enemy)
{
    size_t choice = rand() % player.inventory.size();
    auto card = player.inventory[choice];
    player.changeMana(-card->getCost());

    if (auto objectPtr = std::dynamic_pointer_cast<Object>(card))
    {
        int x, y;
        do
        {
            x = player.zone.getMinX() + rand() % (player.zone.getMaxX() - player.zone.getMinX() + 1);
            y = player.zone.getMinY() + rand() % (player.zone.getMaxY() - player.zone.getMinY() + 1);
        }
        while (field.grid[y-1][x-1]!=nullptr || !field.placeNewCharacter(player, std::make_shared<Coordinates>(x, y), objectPtr));
        player.inventory.erase(player.inventory.begin() + choice);
        fieldUI.draw(player, enemy);
        pause();
    }
    else if (auto improvePtr = std::dynamic_pointer_cast<Improvement>(card))
    {
        if (!player.charactersOnGrid.empty())
        {
            size_t charChoice = rand() % player.charactersOnGrid.size();
            improvePtr->addPoints(player.charactersOnGrid[charChoice]);
            pause();
            player.inventory.erase(player.inventory.begin() + choice);
        }
    }
}

void AIController::buyRandomCard()
{
    if (player.money >= 3)
    {
        player.money -= 3;
        auto character = generateCard(&player);
        player.inventory.push_back(character);
    }
}

bool AIController::shouldBuyCard() const
{
    return player.money >= 3;
}

bool AIController::shouldPlayCard() const
{
    if (field.isEmpty(player) && player.getMana() >= 3) {
        return true;
    } else {
        return false;
    }
}

void AIController::makeActionsMove(Field& field, Player& enemy) {
    bool restartLoop = false;
    
    do {
        restartLoop = false;
        for (auto& character : player.charactersOnGrid) {
            if (character->hasActed) continue;
            
            bool actionSuccess = aiAttack(character, enemy, field);
            if (enemy.base->health <= 0) return;
            if (!actionSuccess) {
                actionSuccess = aiMoveCharacter(character, enemy, field);
            }            
            if (actionSuccess) {
                fieldUI.draw(player, enemy);
                pause();
                restartLoop = true;
                break;
            }
        }
        
    } while (restartLoop);
}

bool AIController::aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy, Field& field) {
    character->calculateMovement(character->location, field.grid);
    if (character->movement.empty()) return false;

    const Coordinates target1(4, 9);
    const Coordinates target2(5, 9);
    
    std::shared_ptr<Coordinates> bestMove = character->movement[0];
    int minDistance = INT_MAX;

    for (const auto& move : character->movement) {
        int dist1 = abs(move->getX() - target1.getX()) + abs(move->getY() - target1.getY());
        int dist2 = abs(move->getX() - target2.getX()) + abs(move->getY() - target2.getY());
        int currentDist = std::min(dist1, dist2);
        
        if (currentDist < minDistance) {
            minDistance = currentDist;
            bestMove = move;
        }
    }

    field.moveCharacter(player, character->getLocation(), bestMove);
    character->movement.clear();
    character->hasActed = true;

    return true;
}
bool AIController::aiAttack(std::shared_ptr<Character> attacker, Player& enemy, Field& field)
{
    attacker->calculateAttack(attacker->location, field.grid);
    if (attacker->attack.empty()) return false;

    auto target = selectBestTarget(attacker, enemy);
    if (!target) return false;

    target->changeHealth(-attacker->power);
    attacker->hasActed = true;

    if (target->health <= 0)
    {
        auto it = std::find(enemy.charactersOnGrid.begin(), enemy.charactersOnGrid.end(), target);
        if (it != enemy.charactersOnGrid.end())
        {
            enemy.charactersOnGrid.erase(it);
        }

        for (size_t y = 0; y < field.grid.size(); ++y)
        {
            for (size_t x = 0; x < field.grid[y].size(); ++x)
            {
                if (field.grid[y][x] == target)
                {
                    field.grid[y][x] = nullptr;
                }
            }
        }
    }

    attacker->attack.clear();
    return true;
}

std::shared_ptr<Object> AIController::selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy)
{
    std::shared_ptr<Object> bestTarget = attacker->attack[0];
    return bestTarget;
}
