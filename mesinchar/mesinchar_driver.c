#include <stdio.h>
#include <stdlib.h>
#include "mesinchar.h"



int main()
{
    printf("Masukan sebuah kalimat diakhiri enter : \n");
    STARTCHAR();
    printf("maka keluarannya adalah :\n");
    printf("%c", CC);
    while (CC!=MARK)
    {
        ADVCHAR();
        printf("%c", CC);
    }
    return 0;
}
