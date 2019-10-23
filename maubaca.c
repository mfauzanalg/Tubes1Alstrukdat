#include "stdio.h"
#include "mesinchar.h"
#include "mesinword.h"

int main (){
    STARTWORD();
    int i;

    for (i = 1; i <= 10; i++){
        printf("%c", CWord.TabKata[i]);
    }


    return 0;
}