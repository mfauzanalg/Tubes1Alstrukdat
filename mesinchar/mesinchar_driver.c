#include <stdio.h>
#include <stdlib.h>
#include "mesinchar.h"



int main()
{
    STARTCHAR();
    printf("%c", CC);
    while (CC!=MARK)
    {
        ADVCHAR();
        printf("%c", CC);
    }


    return 0;
}
