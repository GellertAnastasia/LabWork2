#ifndef ADDHEALTH_H
#define ADDHEALTH_H
#include "../base/base.h"
#include "../object/object.h"

void addHealth(std::shared_ptr<Object> object, int hp);
void addHealth(Base& base, int hp);

#endif
