#include "startUI.h"


void printTitle() {
    clearScreen();
    std::string title[] = {
        purple,
        " ███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗██╗      █████╗ ███████╗██╗  ██╗",
        " ████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝██║     ██╔══██╗██╔════╝██║  ██║",
        " ██╔████╔██║███████║██╔██╗ ██║███████║██║     ██║     ███████║███████╗███████║",
        " ██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║     ██║     ██╔══██║╚════██║██╔══██║",
        " ██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╗███████╗██║  ██║███████║██║  ██║",
        " ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝",
        reset
    };

    for(const auto& line : title) {
        std::cout << line << std::endl;
    }
}


void printMenu(std::string one, std::string two, std::string three) {
    size_t max_length = std::max({one.length(), two.length(), three.length()}) + 5;
    size_t total_width = max_length + 45;
    
    std::string border(total_width, '*');
    std::string space(41, ' ');
    std::string empty_line = "*" + std::string(total_width - 2, ' ') + "*";
    
    std::string line1 = "*  " + std::string(pink) + "➤ 1. " + one + 
                       std::string(blue) + std::string(max_length - (5 + one.length()), ' ') + space + "*";
    std::string line2 = "*  " + std::string(pink) + "➤ 2. " + two + 
                       std::string(blue) + std::string(max_length - (5 + two.length()), ' ') + space + "*";
    std::string line3 = "*  " + std::string(pink) + "➤ 3. " + three + 
                       std::string(blue) + std::string(max_length - (5 + three.length()), ' ') + space + "*";
    
    std::cout << blue << "\n\n"
              << "        " << border << "\n"
              << "        " << empty_line << "\n"
              << "        " << line1 << "\n"
              << "        " << empty_line << "\n"
              << "        " << line2 << "\n"
              << "        " << empty_line << "\n"
              << "        " << line3 << "\n"
              << "        " << empty_line << "\n"
              << "        " << border << "\n"
              << reset;
}
