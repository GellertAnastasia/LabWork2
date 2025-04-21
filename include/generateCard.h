#ifndef GENERATECARD_H
#define GENERATECARD_H
#include <memory>
#include <cstdlib>
#include <ctime>
#include "fighter.h"
#include "wizard.h"
#include "archer.h"
#include "barrier.h"
#include "farm.h"
#include "addHealth.h"
#include "addPower.h"

std::shared_ptr<Card> generateCard(Player* owner);

#endif
