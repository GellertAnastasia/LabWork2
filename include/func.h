#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <algorithm>
#include <memory>
#include <limits>
#include "coordinates.h"
#include "object.h"
#include "constants.h"

void clearScreen();
void pause();
bool isWithinBounds(std::shared_ptr<Coordinates> coordinates);
bool isFree(std::shared_ptr<Coordinates> coordinates, std::vector<std::vector<std::shared_ptr<Object>>> grid);

#endif
