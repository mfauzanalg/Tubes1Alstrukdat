#include "point.h"
#include <stdio.h>

/* *** Konstruktor membentuk POINT *** */
void BacaPOINT (POINT * P){
        float X,Y;
        printf("Masukkan X : ");
        scanf("%f", &X);
        printf("Masukkan Y : ");
        scanf("%f", &Y);
        *P = MakePOINT(X,Y);
    }

void TulisPOINT (POINT P){
        printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    }

POINT MakePOINT (float X, float Y){
        POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
    