#ifndef GENERATECARD_H
#define GENERATECARD_H
#include <memory>
#include <cstdlib>
#include <ctime>
#include "../fighter/fighter.h"
#include "../wizard/wizard.h"
#include "../archer/archer.h"

std::shared_ptr<Character> generateCard();

#endif
