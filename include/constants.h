/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

const int WIDTH = 10;
const int HEIGHT = 10;

const std::string EMPTY_CELL = "◦";
const std::string circled_numbers[] = {"➀", "➁", "➂", "➃", "➄", "➅", "➆", "➇", "➈", "➉"};

const std::string purple = "\033[38;5;129m";
const std::string blue = "\033[38;5;45m";
const std::string orange = "\033[38;5;208m";
const std::string pink = "\033[38;5;199m";
const std::string forest_green = "\033[38;5;28m";
const std::string azure = "\033[38;2;135;206;250m";
const std::string reset = "\033[0m";

const std::string MANA = "\033[38;5;129m✦\033[0m";
const std::string MONEY = "\033[38;2;255;215;0m●\033[0m";
const std::string HEALTH = "\033[31m♥\033[0m";
const std::string POWER = "\033[38;5;240m⸸\033[0m";
#endif
