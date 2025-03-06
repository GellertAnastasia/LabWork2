#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "../object/object.h"

class Character: public Object
{
public:
	int level;
	int power;
	int shield;
	int speed;	
	
	
	bool move();
	bool attack();
	std::string getName() const override;
	
};

#endif
