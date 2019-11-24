#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"



int main()
{
    int i;
    START();
    printf("%c", CC);
    for (i = 1; i <= 20; i++)
    {
        ADV();
        printf("%c", CC);
    }
    CLOSE();
    return 0;
}
