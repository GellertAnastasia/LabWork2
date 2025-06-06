/* Anastasia Gellert st130144@student.spbu.ru
	labwork 2
*/


#include "fieldUI.h"

FieldUI::FieldUI(Field& field) : field(field) {}

void FieldUI::draw(Player& player, Player& enemy)
{
    clearScreen();

    const int field_width = WIDTH * 2 - 1;

    std::cout << "  ";
    for (int x = 0; x < WIDTH; ++x)
    {
        if (x < 10)
        {
            std::cout << circled_numbers[x];
        }
        else
        {
            std::cout << x+1;
        }
        if (x != WIDTH - 1) std::cout << " ";
    }
    std::cout << std::string(field_width - WIDTH - 1, ' ')
              << "\033[" << player.getColor() << "m    Player\033[0m's turn\n";

    auto formatValue = [](int value, int width)
    {
        std::ostringstream oss;
        oss << std::setw(width) << value;
        return oss.str();
    };

    int max_value_width = 2;
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.base->getHealth()).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.base->getHealth()).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.getMana()).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.getMana()).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(player.getMoney()).length()));
    max_value_width = std::max(max_value_width, static_cast<int>(std::to_string(enemy.getMoney()).length()));

    for (int y = 0; y < HEIGHT; ++y)
    {
        if (y < 10)
        {
            std::cout << circled_numbers[y] << " ";
        }
        else
        {
            std::cout << y+1 << " ";
        }

        for (int x = 0; x < WIDTH; ++x)
        {
            if (field.grid[y][x] == nullptr)
            {
                if (y < 4)
                {
                    std::cout << forest_green << EMPTY_CELL << reset;
                }
                else if (y >= HEIGHT - 4)
                {
                    std::cout << azure << EMPTY_CELL << reset;
                }
                else
                {
                    std::cout << EMPTY_CELL;
                }
            }
            else
            {
                std::cout << "\033[" << field.grid[y][x]->getColor() << ";1m"
                          << field.grid[y][x]->getCell() << reset;
            }
            if (x != WIDTH - 1) std::cout << " ";
        }

        std::cout << std::string(field_width - (WIDTH * 2 - 1), ' ') << "    ╎";

        if (y == 0)
        {
            std::cout << "   ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌";
        }
        else if (y == 1)
        {
            std::cout << "   \033[" << player.getColor() << "mPlayer\033[0m        \033["
                      << enemy.getColor() << "mPlayer\033[0m";
        }
        else if (y == 2)
        {
            std::cout << "   base: " << formatValue(player.base->getHealth(), max_value_width)
                      << HEALTH << "     base: " << formatValue(enemy.base->getHealth(), max_value_width)
                      << HEALTH;
        }
        else if (y == 3)
        {
            std::cout << "   mana: " << formatValue(player.getMana(), max_value_width)
                      << MANA << "     mana: " << formatValue(enemy.getMana(), max_value_width)
                      << MANA;
        }
        else if (y == 4)
        {
            std::cout << "   money:" << formatValue(player.getMoney(), max_value_width)
                      << MONEY << "     money:" << formatValue(enemy.getMoney(), max_value_width) << MONEY;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
