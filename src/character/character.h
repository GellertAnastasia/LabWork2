#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "constants.h"
#include "../object/object.h"
#include "../coordinates/coordinates.h"
#include "../func/func.h"

class Character: public Object
{
public:
	int power = 1;
	int shield = 0;
	std::vector<std::pair<int, int>> directionOfMove = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
        };
        std::vector<std::pair<int, int>> directionOfAttack = {
        {1, 0},
        {0, 1}
        };
	std::vector<std::shared_ptr<Coordinates>> movement;
	std::vector<std::shared_ptr<Object>> attack;	

        const std::vector<std::pair<int, int>>& getDirectionOfMove() const;
        void setDirectionOfMove(const std::vector<std::pair<int, int>>& newDirections);
        const std::vector<std::pair<int, int>>& getDirectionOfAttack() const;
        void setDirectionOfAttack(const std::vector<std::pair<int, int>>& newDirections);
        
	void calculateMovement(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
	void printMovement();
	bool isWithinAttackRange(int targetX, int targetY, const std::shared_ptr<Coordinates>& coordinates);
	void calculateAttack(const std::shared_ptr<Coordinates>& coordinates, const std::vector<std::vector<std::shared_ptr<Object>>>& grid);
	void printAttack();
	std::string getName() const override;
	
};

#endif
