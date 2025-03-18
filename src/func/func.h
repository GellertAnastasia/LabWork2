#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <algorithm>
#include <memory>
#include "../coordinates/coordinates.h"
#include "../object/object.h"
#include "constants.h"


bool isWithinBounds(std::shared_ptr<Coordinates> coordinates);
bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<std::shared_ptr<Object>>> grid);

#endif
