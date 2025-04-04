#ifndef SIMBOLSUI_H
#define SIMBOLSUI_H
#include <string>

class SimbolsUI {
private:
    std::string mana = "\033[38;5;129m✦\033[0m";
    std::string money = "\033[38;2;255;215;0m●\033[0m";
    std::string health = "\033[31m♥\033[0m";
    std::string power = "\033[38;5;255m\033[48;5;238m⸸\033[0m";
public:
    SimbolsUI();
    std::string gmana();
    std::string gmoney();
    std::string ghealth();
    std::string gpower();
};
#endif
