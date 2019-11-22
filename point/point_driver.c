#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"



void BacaPOINT (POINT * P)

    {
        float X,Y;
        printf("Masukkan X : ");
        scanf("%f", &X);
        printf("Masukkan Y : ");
        scanf("%f", &Y);
        *P = MakePOINT(X,Y);
    }

void TulisPOINT (POINT P)

    {
        printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    }



int main(){

    POINT p1;
    printf("Masukkan X dan Y untuk membuat point : \n\n");
    BacaPOINT(&p1);
    printf("\n");
    printf("Hasil point yang dimaksud   :  ");
    TulisPOINT(p1);
    printf("\n");


return 0;
}
