#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "constants.h"
#include "../object/object.h"
#include "../coordinates/coordinates.h"

class Character: public Object
{
public:
	int level = 1;
	int power = 1;
	int shield = 0;
	bool hasActed = false;	
	std::vector<std::shared_ptr<Coordinates>> movement;
	std::vector<std::shared_ptr<Object>> attack;
	
	void calculateMovement(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<bool>> full);
	void printMovement();
	void calculateAttack(std::vector<std::vector<bool>> full, std::vector<std::vector<std::shared_ptr<Object>>> grid);
	void printAttack();
	std::string getName() const override;
	
};

#endif
