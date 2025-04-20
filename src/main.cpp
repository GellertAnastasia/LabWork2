#include "game/game.h"
#include "startUI/startUI.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    while (true)
    {
        printTitle();
        printMenu("START", "RULES", "EXIT");
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
            printMenu("Player vs Player", "Player vs Bot", "Back");
            std::cout << "Your choice: ";
            int choice1;
            if (!(std::cin >> choice1))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (choice1 == 1)
            {
                game.startA();
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

