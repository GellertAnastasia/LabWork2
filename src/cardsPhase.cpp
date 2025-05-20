/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "cardsPhase.h"

CardsPhase::CardsPhase(Field& field) : field(field), fieldUI(field) {}

void CardsPhase::start(Player& player, Player& enemy)
{
    bool cardsPhase = true;
    while(cardsPhase)
    {
        fieldUI.draw(player, enemy);
        std::cout << purple << "Card playing phase\n\n" << reset;
        std::cout << "Choose an action\n";
        std::cout << "1. Play card\n2. Buy card\n3. Go next step\nYour choice: ";
        size_t choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(choice)
        {
        case 1:
            playCard(player, enemy);
            break;
        case 2:
            buyCard(player);
            pause_();
            break;
        case 3:
            cardsPhase = false;
            break;
        default:
            break;
        }
    }
}


void CardsPhase::playCard(Player& player, Player& enemy) {
    size_t choice;
    bool played = false;
    
    PlayingCards playing(player, enemy, field, fieldUI);

    while (!played) {
        fieldUI.draw(player, enemy);
        player.printInventory();
        std::cout << player.inventory.size() + 1 << ". Back\n";
        std::cout << "Your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == player.inventory.size() + 1) return;

        if (choice < 1 || choice > player.inventory.size()) continue;

        auto& card = player.inventory[choice - 1];
        
        if (auto object = std::dynamic_pointer_cast<Object>(card)) {
            if (playing.characters(object)) {
                player.inventory.erase(player.inventory.begin() + choice - 1);
                played = true;
            }
            pause_();
        }
        else if (auto improvement = std::dynamic_pointer_cast<Improvement>(card)) {
            if (playing.improvements(improvement)) {
                player.inventory.erase(player.inventory.begin() + choice - 1);
                played = true;
            }
            pause_();
        }
    }
}

void CardsPhase::buyCard(Player& player)
{
    if (player.getMoney() >= 3)
    {
        player.addMoney(-3);
        auto character = generateCard(&player);
        player.inventory.push_back(character);
        std::cout << character->getName() << "  added to inventory\n";
    }
    else
    {
        std::cout << "Not enough money\n";
    }
}
