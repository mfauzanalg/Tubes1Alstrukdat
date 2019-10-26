#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "point.h"
#include "typebentukan.h"
#include "stack.h"
#include "levelup.h"

void levelUp(TabBang Arr, TabBang Arr2, PLAYER P, int i)
{
    DaftarBangunan(P.ListB, Arr);
    
    if ((Elmt(Arr, i).jum-Elmt(Arr, i).M/2)<0)
    {
        printf("Jumlah pasukan Castle kurang untuk level up\n");



    }
    else
    {
        //printf("%d", Elmt(Arr, i).jum);
        //printf("%d", Elmt(Arr, i).M/2);
        Elmt(Arr, i).jum=(Elmt(Arr, i).jum)-(Elmt(Arr, i).M)/2;
        
        Elmt(Arr, i).lev++;
        printf("Level Tower-mu meningkat menjadi %d!\n", Elmt(Arr, i).lev);


    }
    
    
    




    
}


