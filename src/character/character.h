#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
	std::string getName() const override;
	
};

#endif
