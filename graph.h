/* ADT GRAPH */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "list.h"
#include "matriks.h"


/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef -888
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeGraf; /* type indeks */
typedef List ElType1; /* type elemen */

typedef struct
{
  ElType1 *TI;
  int MaxElArr;
} TabGraph;

/* ********** SELEKTOR ********** */
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxElArr(T) (T).MaxElArr

/* ********** KONSTRUKTOR ********** */
void CreateEmptyGraph(TabGraph *Arr, int maxel, MATRIKS *Mat);
/* array untuk representasi graph, array berisikan list of bangunan yang terhubung */

boolean IsAdjacent(TabGraph *Arr, int a, int b);
/* mengecek apakah bangunan a bersambung dengan bangunan b */

List Neighbors(TabGraph *Arr, int a);
/* mengembalikan list berisi bangunan yang berhubungan dengan bangunan a */


#endif