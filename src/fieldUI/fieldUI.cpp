#include "fieldUI.h"

FieldUI::FieldUI(Field& field) : field(field) {}
void FieldUI::draw(Player& player, Player& enemy) {
    clearScreen();
    
    const int field_width = WIDTH * 2 - 1;
    
    std::cout << "  ";
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << x + 1;
        if (x != WIDTH - 1) std::cout << " ";
    }
    std::cout << std::string(field_width - WIDTH - 1, ' ') 
              << "\033[" << player.color << "m    Player\033[0m's turn\n";

    const std::string forest_green = "\033[38;5;28m";
    const std::string azure = "\033[38;2;135;206;250m";
    const std::string reset = "\033[0m";

    auto formatValue = [](int value, int width) {
        std::ostringstream oss;
        oss << std::setw(width) << value;
        return oss.str();
    };

    int max_value_width = 2;
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.base->health).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.base->health).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.mana).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.mana).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.money).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.money).length()));

    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << y+1 << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if (field.grid[y][x] == nullptr) {
                if (y < 4) {
                    std::cout << forest_green << "⋅" << reset;
                } else if (y >= HEIGHT - 4) {
                    std::cout << azure << "⋅" << reset;
                } else {
                    std::cout << "⋅";
                }
            } else {
                std::cout << "\033[" << field.grid[y][x]->getColor() << ";1m" 
                          << field.grid[y][x]->getCell() << reset;
            }
            if (x != WIDTH - 1) std::cout << " ";
        }

        std::cout << std::string(field_width - (WIDTH * 2 - 1), ' ') << "    ╎";
        
        if (y == 0) {
            std::cout << "   ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌";
        } else if (y == 1) {
            std::cout << "   \033[" << player.color << "mPlayer\033[0m        \033[" 
                     << enemy.color << "mPlayer\033[0m";
        } else if (y == 2) {
            std::cout << "   base: " << formatValue(player.base->health, max_value_width) 
                     << simbolsUI.ghealth() << "     base: " << formatValue(enemy.base->health, max_value_width) 
                     << simbolsUI.ghealth();
        } else if (y == 3) {
            std::cout << "   mana: " << formatValue(player.mana, max_value_width) 
                     << simbolsUI.gmana() << "     mana: " << formatValue(enemy.mana, max_value_width) 
                     << simbolsUI.gmana();
        } else if (y == 4) {
            std::cout << "   money:" << formatValue(player.money, max_value_width) 
                     << simbolsUI.gmoney() << "     money:" << formatValue(enemy.money, max_value_width) << simbolsUI.gmoney();
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
