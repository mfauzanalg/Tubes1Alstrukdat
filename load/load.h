#include <stdio.h>
#include "../stack/stack.h"
#include "../stackplayer/stackplayer.h"
#include "../boolean/boolean.h"
#include "../list/list.h"
#include "mesinkata/mesinkata.h"
#include "mesinword/mesinword.h"
#include "mesinchar/mesinchar.h"
#include "mesinkar/mesinkar.h"

boolean IntegerToBoolean(int x);

void load (Stack *S, stackp *P1, stackp *P2, boolean *playing, boolean *P1turn);
// void load2(boolean playing, boolean P1turn);
// void save2(boolean playing, boolean P1turn);