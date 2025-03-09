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
	
	bool attack();
	void calculateMovement(std::shared_ptr<Coordinates> coordinates);
	void printMovement();
	//void calculateAttack(std::shared_ptr<Coordinates> coordinates);
	//void printAttack();
	std::string getName() const override;
	
};

#endif
