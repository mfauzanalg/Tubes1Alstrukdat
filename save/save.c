#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "save.h"



void Tulis(boolean *playing, boolean *P1turn, FILE* fptr)
{
    printf("ccccccccccccccccccc\n");
    //FILE *fptr;

    printf("bbbbbbbbbbbbbbbb\n");
    fptr = fopen("E:\\Tugas_Alstrukdat/2/Tubes1Alstrukdat/Save.txt","w");
    /*
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    */

    printf("aaaaaaaaaaaaaaaa\n");

    fprintf(fptr,"%d ",*playing);
    fprintf(fptr,"%d ",*P1turn);
    //fprintf(fptr,"coba ",*P1turn);
    fprintf(fptr,"OJAN");
    fclose(fptr);




}