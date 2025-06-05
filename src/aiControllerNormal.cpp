/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

#include "aiControllerNormal.h"
#include "func.h"

AIControllerNormal::AIControllerNormal(Player& player, Field& field) : AIControllerEasy(player, field) {}

std::shared_ptr<Object> AIControllerNormal::selectBestTarget(std::shared_ptr<Character> attacker, Player& enemy)
{
    if (!attacker || attacker->attack.empty())
    {
        return nullptr;
    }

    std::shared_ptr<Object> bestTarget = nullptr;
    int bestScore = -1;

    for (auto& target : attacker->attack)
    {
        if (!target)
        {
            continue;
        }
        if (target == enemy.base)
        {
            return target;
        }
        if (auto enemyChar = std::dynamic_pointer_cast<Character>(target))
        {
            if (!enemyChar->location)
            {
                continue;
            }
            int score = 0;
            score += (10 - target->getHealth());
            score += enemyChar->getPower() * 2;

            if (player.base && player.base->location)
            {
                int distToBase = distance(target->getLocation(), player.base->getLocation());
                score += (10 - distToBase) * 3;
            }
            if (score > bestScore)
            {
                bestScore = score;
                bestTarget = target;
            }
        }
    }
    return bestTarget;
}

std::shared_ptr<Coordinates> AIControllerNormal::findClosestPositionTo(
    std::vector<std::shared_ptr<Coordinates>>& possibleMoves,
    std::shared_ptr<Coordinates> target
)
{
    if (possibleMoves.empty()) return nullptr;
    std::shared_ptr<Coordinates> bestMove = possibleMoves[0];
    int minDistance = distance(bestMove, target);
    for (const auto& move : possibleMoves)
    {
        int currentDistance = distance(move, target);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestMove = move;
        }
    }
    return bestMove;
}

std::shared_ptr<Character> AIControllerNormal::findNearestEnemy(
    std::shared_ptr<Character> unit,
    Player& enemy
)
{
    if (enemy.charactersOnGrid.empty()) return nullptr;
    std::shared_ptr<Character> nearestEnemy = enemy.charactersOnGrid[0];
    int minDistance = distance(unit->location, nearestEnemy->location);
    for (const auto& enemyUnit : enemy.charactersOnGrid)
    {
        int currentDistance = distance(unit->location, enemyUnit->location);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            nearestEnemy = enemyUnit;
        }
    }
    return nearestEnemy;
}
bool AIControllerNormal::aiMoveCharacter(std::shared_ptr<Character> character, Player& enemy)
{
    if (!character || !character->location)
    {
        std::cerr << "Error: Invalid character or location in aiMoveCharacter" << std::endl;
        return false;
    }
    try
    {
        character->calculateMovement(character->location, field.grid);
    }
    catch (...)
    {
        std::cerr << "Error in calculateMovement" << std::endl;
        return false;
    }
    if (character->movement.empty())
    {
        character->hasActed = true;
        return false;
    }
    if (!enemy.charactersOnGrid.empty())
    {
        auto nearestEnemy = findNearestEnemy(character, enemy);
        if (nearestEnemy && nearestEnemy->location)
        {
            auto bestMove = findClosestPositionTo(character->movement, nearestEnemy->location);
            if (bestMove)
            {
                if (field.moveCharacter(player, character->location, bestMove))
                {
                    character->hasActed = true;
                    return true;
                }
            }
        }
    }
    if (!character->hasActed)
    {
        character->calculateMovement(character->location, field.grid);
        if (character->movement.empty()) return false;
        const Coordinates target1(4, 9);
        const Coordinates target2(5, 9);
        std::shared_ptr<Coordinates> bestMove = character->movement[0];
        int minDistance = INT_MAX;
        for (const auto& move : character->movement)
        {
            int dist1 = abs(move->getX() - target1.getX()) + abs(move->getY() - target1.getY());
            int dist2 = abs(move->getX() - target2.getX()) + abs(move->getY() - target2.getY());
            int currentDist = std::min(dist1, dist2);

            if (currentDist < minDistance)
            {
                minDistance = currentDist;
                bestMove = move;
            }
        }

        field.moveCharacter(player, character->getLocation(), bestMove);
        character->movement.clear();
        character->hasActed = true;

        return true;
    }
    character->hasActed = true;
    return false;
}

bool AIControllerNormal::shouldPlayCard() const
{
    return player.getMana() >= 3 && (!player.charactersOnGrid.empty() || field.isEmpty(player));
}

bool AIControllerNormal::tryPlaceUnit(std::shared_ptr<Object> unitCard, Player& enemy)
{
    std::vector<Coordinates> spawnAreas =
    {
        {4, 4}, {5, 4}, {6, 4}, {7, 4},
        {5, 2}, {6, 2}
    };
    for (const auto& pos : spawnAreas)
    {
        if (field.grid[pos.getY()-1][pos.getX()-1] == nullptr &&
                player.isInsideZone(pos.getX(), pos.getY()))
        {
            field.placeNewCharacter(player, std::make_shared<Coordinates>(pos), unitCard);
            return true;
        }
    }
    for (int y = player.zone.getMinY(); y <= player.zone.getMaxY(); ++y)
    {
        for (int x = player.zone.getMinX(); x <= player.zone.getMaxX(); ++x)
        {
            if (field.grid[y-1][x-1] == nullptr)
            {
                field.placeNewCharacter(player, std::make_shared<Coordinates>(x, y), unitCard);
                return true;
            }
        }
    }

    return false;
}

std::shared_ptr<Character> AIControllerNormal::getStrongestCharacter(Player& player)
{
    if (player.charactersOnGrid.empty()) return nullptr;

    std::shared_ptr<Character> strongest = player.charactersOnGrid[0];
    int maxPower = strongest->getPower();
    for (const auto& character : player.charactersOnGrid)
    {
        int currentPower = character->getPower() + character->getHealth() / 10;
        if (currentPower > maxPower)
        {
            maxPower = currentPower;
            strongest = character;
        }
    }

    return strongest;
}

void AIControllerNormal::playCard(Player& enemy)
{
    if (player.inventory.empty()) return;
    if (player.charactersOnGrid.size() < 2)
    {
        for (size_t i = 0; i < player.inventory.size(); ++i)
        {
            if (auto obj = std::dynamic_pointer_cast<Object>(player.inventory[i]))
            {
                if (tryPlaceUnit(obj, enemy))
                {
                    player.inventory.erase(player.inventory.begin() + i);
                    fieldUI.draw(player, enemy);
                    pause_();
                    return;
                }
            }
        }
    }

    if (!player.charactersOnGrid.empty())
    {
        auto strongest = getStrongestCharacter(player);
        if (strongest)
        {
            for (size_t i = 0; i < player.inventory.size(); ++i)
            {
                if (auto imp = std::dynamic_pointer_cast<Improvement>(player.inventory[i]))
                {
                    imp->addPoints(strongest);
                    player.inventory.erase(player.inventory.begin() + i);
                    pause_();
                    return;
                }
            }
        }
    }

    playRandomCard(enemy);
}

