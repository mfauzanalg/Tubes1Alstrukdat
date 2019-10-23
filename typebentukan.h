#ifndef __TYPEBENTUKAN_H__
#define __TYPEBENTUKAN_H__

#include "boolean.h"
#include "point.h"

typedef struct {
    int nomor;
	char type;
    int milik;
    int jum;
    int lev;
    int A;
    int M;
    boolean P;
    int U;
    POINT letak;
} Bangunan;

#endif