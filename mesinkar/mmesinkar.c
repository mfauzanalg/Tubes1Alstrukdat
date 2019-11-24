#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"



int main()
{
    START();
    printf("%c", CC);
    
    while (CC!='.')
    {
        ADV();
        printf("%c", CC);


    }
    CLOSE();
    




    return 0;
}
