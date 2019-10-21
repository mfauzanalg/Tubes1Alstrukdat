#ifndef __OLAHFILE_H__
#define __OLAHFILE_H__

#include "boolean.h"
#include "array.h"
#include "matriks.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "point.h"
#include "queue.h"
#include "stack.h"
#include "list.h"


void LoadFile (int *N, int *M, int *J, TabBang *Arr, MATRIKS *Mat, List *L1, List *L2, List *L3);
// Load file data inisialisasi awal
// Akan terbentuk
// N = tinggi peta
// M = lebar peta
// J = Jumlah bangunan
// Array of bangunan
// Matriks untuk Graf


#endif
