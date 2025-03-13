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
	int level;
	int power;
	int shield;
	int speed;	
	std::vector<std::shared_ptr<Coordinates>> movement;
	std::vector<std::shared_ptr<Coordinates>> attack;
	
	void calculateMovement(std::shared_ptr<Coordinates> coordinates, std::vector<std::shared_ptr<Coordinates>> location);
	void printMovement();
	void calculateAttack(std::shared_ptr<Coordinates> coordinates, std::vector<std::shared_ptr<Coordinates>> location);
	void printAttack();
	std::string getName() const override;
	
};

#endif
