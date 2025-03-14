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
            std::cout<<"buy\n";
            pause();
            //buyCard();
        } else if (choice == 3) {
            cardsPhase = false;
        } else {
            std::cout<<"Error. Try again\n";
        }
    }

    for(auto& c : field.charactersOnGrid) {
        c->hasActed = false;
    }
    bool actionsPhase = true;
    while(actionsPhase) {
        drawField(field, player);
        std::cout << "Character action phase:\n\n";
        std::cout << "Choose a character\n";
        field.printCharactersOnGrid();
        std::cout << field.charactersOnGrid.size()+1 << ". End your turn\n";
        size_t choice;
        std::cin >> choice;

        if (choice == field.charactersOnGrid.size()+1) {
            std::cout << "next turn\n";
            pause();
            break;
        } else if(choice < 0 || choice > field.charactersOnGrid.size()) {
            std::cout << "Error. Try again\n";
            pause();
            continue;
        }

        std::shared_ptr<Character> current = field.charactersOnGrid[choice-1];
        if (current->hasActed) {
            std::cout << "acted\n";
            pause();
        }
        
        drawField(field, player);
        std::cout << "Choose an action\n";
        std::cout << "1. moving\n2. attack\nYour choice: ";
        int action;
        std::cin >> action;

        if (action == 1) {
            moveCharacter(choice, player, field);
                
            current->hasActed = true;
            continue;
        } else if (action == 2) {s
            current->hasActed = true;
            std::cout << "attack!\n";
            pause();
            continue;
        } else if (action == 3) {
            actionsPhase = false;
        } else {
            std::cout << "Error. Try again\n";
        }
    }
}

