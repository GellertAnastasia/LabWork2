#include "actionsPhase.h"

ActionsPhase::ActionsPhase(Field& field) : field(field), fieldUI(field) {}

void ActionsPhase::start(Player& player, Player& enemy)
{
    bool actionsPhase = true;
    while(actionsPhase)
    {
        fieldUI.draw(player, enemy);
        std::cout << purple << "Character action phase:\n\n" << reset;
        std::cout << "Choose a character\n";
        player.printCharactersOnGrid();
        std::cout << player.charactersOnGrid.size()+1 << ". End your turn\nYour choice: ";
        size_t choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice == player.charactersOnGrid.size()+1)
        {
            std::cout << "next turn\n";
            pause();
            break;
        }
        else if(choice <= 0 || choice > player.charactersOnGrid.size())
        {
            continue;
        }

        std::shared_ptr<Object> current = player.charactersOnGrid[choice-1];
        if (current->hasActed)
        {
            std::cout << "acted\n";
            pause();
            continue;
        }
        size_t action;
        bool done = false;
        while (done != true)
        {
            fieldUI.draw(player, enemy);
            std::cout << "Choose an action\n";
            std::cout << "1. moving\n2. attack\n3. back\nYour choice: ";
            if (!(std::cin >> action))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (action == 1)
            {
                current->hasActed = moveCharacter(choice, player, enemy);
                current.reset();
                done = true;
            }
            else if (action == 2)
            {
                current->hasActed = attack(choice, player, enemy);
                current.reset();
                pause();
                if (player.base->getHealth() <= 0 || enemy.base->getHealth() <= 0)
                {
                    actionsPhase = false;
                }
                done = true;
            }
            else if (action == 3)
            {
                done = true;
            }
            else
            {
                continue;
            }

        }
        continue;
    }
}

bool ActionsPhase::moveCharacter(size_t choice, Player& player, Player& enemy)
{
    auto& character = player.charactersOnGrid[choice - 1];
    character->calculateMovement(character->location, field.grid);
    if (character->movement.empty())
    {
        std::cout << "No available moves!\n";
        pause();
        return false;
    }
    bool done = false;
    while (done != true)
    {
        fieldUI.draw(player, enemy);
        std::cout << "Choose the coordinates:\n";
        character->printMovement();
        std::cout << character->movement.size()+1 << ". back\n";
        size_t choice1;
        if (!(std::cin >> choice1))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice1 < 1 || choice1 > character->movement.size()+1)
        {
            std::cout << "Invalid coordinate choice!\n";
            pause();
            continue;
        }
        else if (choice1 == character->movement.size()+1)
        {
            return false;
        }
        auto newCoords = character->movement[choice1 - 1];

        field.moveCharacter(player, character->getLocation(), newCoords);
        character->movement.clear();
        fieldUI.draw(player, enemy);
        return true;

    }
    return true;
}
bool ActionsPhase::attack(size_t choice, Player& player, Player& enemy)
{

    auto& attacker = player.charactersOnGrid[choice-1];
    attacker->calculateAttack(attacker->location, field.grid);

    bool done = false;
    while (done != true)
    {
        fieldUI.draw(player, enemy);
        std::cout << "Choose the enemy:\n";
        auto wizardPtr = std::dynamic_pointer_cast<Wizard>(attacker);

        attacker->printAttack();
        std::cout << attacker->attack.size()+1 << ". back\n";
        size_t targetChoice;
        if (!(std::cin >> targetChoice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (targetChoice < 1 || targetChoice > attacker->attack.size()+1)
        {
            std::cout << "Invalid choice!\n";
            pause();
            continue;
        }
        else if (targetChoice == attacker->attack.size()+1)
        {
            return false;
        }
        else
        {
            auto& target = attacker->attack[targetChoice-1];
            target->changeHealth(-attacker->getPower());
            std::cout << "Health after attack: " << target->getHealth() << "\n";
            if (target->getHealth() <= 0)
            {
                auto it = std::find(
                              enemy.charactersOnGrid.begin(),
                              enemy.charactersOnGrid.end(),
                              target
                          );
                if (it != enemy.charactersOnGrid.end())
                {
                    enemy.charactersOnGrid.erase(it);
                }
                for (size_t y = 0; y < field.grid.size(); ++y)
                {
                    for (size_t x = 0; x < field.grid[y].size(); ++x)
                    {
                        const auto& obj = field.grid[y][x];
                        if (obj == target)
                        {
                            field.grid[y][x] = nullptr;
                        }
                    }
                }
            }
        }

        done = true;
    }
    attacker->attack.clear();
    return true;
}
