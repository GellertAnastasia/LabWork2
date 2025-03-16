#include "playerTurn.h"

void playerTurn(Player& player, Field& field) {
    bool cardsPhase = true;
    while(cardsPhase) {
        drawField(field, player);
        std::cout << "Card playing phase\n\n";
        std::cout << "Choose an action\n";
        std::cout << "1. Play card\n2. Buy card\n3. Go next step\nYour choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            playCard(player, field);
        } else if (choice == 2) {
            buyCard(player);
            pause();
        } else if (choice == 3) {
            cardsPhase = false;
        } else {
            std::cout<<"Error. Try again\n";
        }
    }

    for(auto& c : player.charactersOnGrid) {
        c->hasActed = false;
    }
    bool actionsPhase = true;
    while(actionsPhase) {
        drawField(field, player);
        std::cout << "Character action phase:\n\n";
        std::cout << "Choose a character\n";
        player.printCharactersOnGrid();
        std::cout << player.charactersOnGrid.size()+1 << ". End your turn\n";
        size_t choice;
        std::cin >> choice;

        if (choice == player.charactersOnGrid.size()+1) {
            std::cout << "next turn\n";
            pause();
            break;
        } else if(choice <= 0 || choice > player.charactersOnGrid.size()) {
            std::cout << "Error. Try again\n";
            pause();
            continue;
        }

        std::shared_ptr<Character> current = player.charactersOnGrid[choice-1];
        if (current->hasActed) {
            std::cout << "acted\n";
            pause();
            continue;
        }
        
        drawField(field, player);
        std::cout << "Choose an action\n";
        std::cout << "1. moving\n2. attack\nYour choice: ";
        int action;
        std::cin >> action;

        if (action == 1) {
            current->hasActed = true;
            moveCharacter(choice, player, field);
            continue;
        } else if (action == 2) {
            current->hasActed = true;
            attack(choice, player, field);
            pause();
            continue;
        } else if (action == 3) {
            actionsPhase = false;
        } else {
            std::cout << "Error. Try again\n";
        }
    }
}

