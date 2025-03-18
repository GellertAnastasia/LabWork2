#ifndef GENERATECARD_H
#define GENERATECARD_H
#include <memory>
#include <cstdlib>
#include <ctime>
#include "../fighter/fighter.h"
#include "../wizard/wizard.h"
#include "../archer/archer.h"
#include "../barrier/barrier.h"
#include "../farm/farm.h"

std::shared_ptr<Object> generateCard(Player* owner);

#endif
