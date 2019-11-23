#include "point.h"
#include <stdio.h>

/* *** Konstruktor membentuk POINT *** */
void BacaPOINT (POINT * P){
        int X,Y;
        printf("Masukkan X : ");
        scanf("%d", &X);
        printf("Masukkan Y : ");
        scanf("%d", &Y);
        *P = MakePOINT(X,Y);
    }

void TulisPOINT (POINT P){
        printf("(%d,%d)", Absis(P), Ordinat(P));
    }

POINT MakePOINT (float X, float Y){
        POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
}