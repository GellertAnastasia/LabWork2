#include "endUI.h"

std::atomic<bool> keepRunning(true);
const std::vector<std::string> stars = {"✧", "✦", "✶", "✷", "✸"};
const std::vector<int> starColors = {93, 129, 165, 201, 219, 123};

void animateStars(int startRow)
{
    while(keepRunning)
    {
        for(int i = 0; i < 5; i++)
        {
            std::cout << "\033[" << startRow + i << ";1H\033[K";
        }

        int starCount = 8 + rand() % 3;
        for(int i = 0; i < starCount; i++)
        {
            int x = 20 + rand() % 40;
            int y = startRow + rand() % 5;
            std::cout << "\033[" << y << ";" << x << "H"
                      << "\033[38;5;" << starColors[rand() % starColors.size()] << "m"
                      << stars[rand() % stars.size()];
        }
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void waitForEnter()
{
    std::cout << "\033[25;1H\033[38;5;240mPress Enter to exit...\033[0m";
    std::cin.ignore();
    keepRunning = false;
}

void showGameOverScreen(const std::string& winner)
{
    srand(time(nullptr));
    clearScreen();
    std::cout << "\033[2J\033[H";

    const std::vector<std::string> victoryArt =
    {
        R"(        ██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗)",
        R"(        ██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝)",
        R"(        ██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ )",
        R"(        ╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  )",
        R"(         ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   )",
        R"(          ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   )"
    };

    std::cout << "\n\n\033[38;5;129m";
    for(const auto& line : victoryArt)
    {
        std::cout << "  " << line << "\n";
    }

    std::cout << "\n\n"
              << "    \033[38;5;230m✧ ✦ ✶ ✧ ✦ ✶ ✦ ✧ ✦ ✶ ✦ ✧ ✦ ✶ ✦\033[38;5;208m  WINNER \033[38;5;230m✦ ✶ ✦ ✧ ✦ ✶ ✦ ✧ ✦ ✶ ✦ ✧ ✦ ✶ ✦ ✧\n\n"
              << "                                  " << winner << "\033[0m\n\n\n";
    std::cout.flush();

    std::thread starThread(animateStars, 16);
    std::thread inputThread(waitForEnter);

    starThread.join();
    inputThread.join();
}
