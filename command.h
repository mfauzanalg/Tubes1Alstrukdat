#ifndef COMMAND_H
#define COMMAND_H


#include <stdio.h>
#include <stdlib.h>
#include "typebentukan.h"
#include "stack.h"
#include "array.h"


void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P, PLAYER *Pcop, stackp *SPlayer);

void LevelUpUp(TabBang *(Arr), PLAYER P, int i);

#endif