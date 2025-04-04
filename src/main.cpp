#include "game/game.h"
#include "ui/ui.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    while (true)
    {
        printTitle();
        printMenu();
        std::cout << "Your choice: ";
        int choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1)
        {
            Game game;
            clearScreen();
            std::cout << "1. Player vs Player\n2. Player vs Bot\n3. Back\nYour choice:";
            int choice1;
            if (!(std::cin >> choice1))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (choice1 == 1)
            {
                game.start();
            }
            else if (choice1 == 2)
            {
                game.startB();
            }
        }
        else if (choice == 2)
        {
            std::cout << "Rules\n";
            //printRules();
            break;
        }
        else if (choice == 3)
        {
            std::cout << "Exit...\n";
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}

