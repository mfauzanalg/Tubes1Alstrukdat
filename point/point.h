/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "../boolean/boolean.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

#define Absis(Q) (Q).X
#define Ordinat(Q) (Q).Y

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y);
/* Membentuk sebuah POINT dari komponen X dan Y */

void BacaPOINT (POINT * P);
// Membaca input Point dari user

void TulisPOINT (POINT P);
// Menuliskan point dengan format (X,Y)

#endif
