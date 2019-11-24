#ifndef save_H
#define save_H

#include <stdio.h>
#include "../stack/stack.h"
#include "../stackplayer/stackplayer.h"
#include "../boolean/boolean.h"
#include "../list/list.h"


int BooleanToInteger(boolean x);
boolean IntegerToBoolean(int x);
void SaveAll(Stack S, stackp P1, stackp P2, boolean playing, boolean P1turn);
void Saveee(Stack S, stackp P1, stackp P2, boolean playing, boolean P1turn);

#endif