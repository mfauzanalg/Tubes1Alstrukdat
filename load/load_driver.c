#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../save/save.h"
#include "../boolean/boolean.h"
#include "../stack/stack.h"
#include "../stackplayer/stackplayer.h"
//#include "../boolean/boolean.h"
#include "../list/list.h"
#include "mesinkata/mesinkata.h"
#include "mesinword/mesinword.h"
#include "mesinchar/mesinchar.h"
#include "mesinkar/mesinkar.h"



int main()
{
    Stack S;
    stackp P1, P2;
    boolean playing, P1turn;
    int i;

    load(&S, &P1, &P2, &playing, &P1turn);
    //printf("%d\n", S.T[1].TI[1]);
    printf("%d\n", playing);
    printf("%d\n", P1turn);
    printf("%d\n", InfoTop(S).MaxElArr);
    printf("%c\n", Elmt(InfoTop(S),1).type);
    printf("%d\n", Elmt(InfoTop(S),1).jum);
    printf("%d\n", Elmt(InfoTop(S),1).lev);
    printf("%d\n", Elmt(InfoTop(S),1).A);
    printf("%d\n", Elmt(InfoTop(S),1).M);
    printf("%d\n", Elmt(InfoTop(S),1).P);
    // for (i=1;i<=2;i++)
    // {
    //     printf("%c", Elmt(InfoTop(S),i).type);



    // }


    return 0;
}