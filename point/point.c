#include "point.h"
#include <stdio.h>

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
    {
        POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
    }