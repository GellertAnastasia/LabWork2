#include "aiController.h"

AIController::AIController(Player& player, Field& field) : player(player), field(field), fieldUI(field)
{
    std::srand(std::time(0));
}

void AIController::makeMove(Field& field, Player& enemy)
{
    while (shouldBuyCard())
    {
        buyRandomCard();
    }
    while(!player.inventory.empty() && shouldPlayCard(field, enemy))
    {
        playRandomCard(field, enemy);
    }

}

void AIController::playRandomCard(Field& field, Player& enemy)
{
    size_t choice = rand() % player.inventory.size();
    auto card = player.inventory[choice];

    if (auto objectPtr = std::dynamic_pointer_cast<Object>(card))
    {
        int x, y;
        do
        {
            x = player.zone.getMinX() + rand() % (player.zone.getMaxX() - player.zone.getMinX() + 1);
            y = player.zone.getMinY() + rand() % (player.zone.getMaxY() - player.zone.getMinY() + 1);
        }
        while (!field.addCharacter(player, std::make_shared<Coordinates>(x, y), objectPtr));

        player.inventory.erase(player.inventory.begin() + choice);
    }
    else if (auto improvePtr = std::dynamic_pointer_cast<Improvement>(card))
    {
        if (!player.charactersOnGrid.empty())
        {
            size_t charChoice = rand() % player.charactersOnGrid.size();
            improvePtr->addPoints(player.charactersOnGrid[charChoice]);
            player.inventory.erase(player.inventory.begin() + choice);
        }
    }
}

void AIController::buyRandomCard()
{
    if (player.money >= 1)
    {
        player.money -= 1;
        auto character = generateCard(&player);
        player.inventory.push_back(character);
    }
}

bool AIController::shouldBuyCard() const
{
    return player.money >= 1;
}

bool AIController::shouldPlayCard(const Field& field, const Player& enemy) const
{
    return true;
}

void AIController::makeActionsMove(Field& field, Player& enemy)
{
    for (auto& character : player.charactersOnGrid)
    {
        if (character->hasActed) continue;
        bool actionSuccess = false;
        actionSuccess = aiAttack(character, enemy, field);
        while (actionSuccess != true)
        {
            actionSuccess = aiMoveCharacter(character, enemy, field);
        }
        character->hasActed = actionSuccess;
        fieldUI.draw(player, enemy);
        pause();
        if (enemy.base->health <= 0) break;
    }
}

bool AIController::aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy, Field& field)
{
    character->calculateMovement(character->location, field.grid);
    if (character->movement.empty()) return false;

    int moveChoice = rand() % character->movement.size();
    auto newCoords = character->movement[moveChoice];

    field.deleteObject(character->location, player);
    character->location = newCoords;
    field.addCharacter(player, newCoords, character);
    character->movement.clear();

    return true;
}

bool AIController::aiAttack(std::shared_ptr<Character> attacker, Player& enemy, Field& field)
{
    attacker->calculateAttack(attacker->location, field.grid);
    if (attacker->attack.empty()) return false;

    auto target = selectBestTarget(attacker, enemy);
    if (!target) return false;

    target->changeHealth(-attacker->power - attacker->level);

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
/*
    if (attacker->attack.empty()) return nullptr;

    std::shared_ptr<Object> bestTarget = attacker->attack[0];
    for (auto& target : attacker->attack)
    {
        if (target->health < bestTarget->health)
        {
            bestTarget = target;
        }
    }
    */
    std::shared_ptr<Object> bestTarget = attacker->attack[0];
    return bestTarget;
}
