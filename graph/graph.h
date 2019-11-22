/* ADT GRAPH */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean/boolean.h"
#include "../list/list.h"
#include "../matriks/matriks.h"

#include "../typebentukan/typebentukan.h"
#include "../stack/stack.h"



#define NilList NULL


typedef struct tElmtMatlistG *addresslistG;

typedef struct tElmtMatlistG {
	infotypelist infoG;
	addresslist tetangga;
	addresslistG nextG;
} ElmtListGraph;

typedef struct {
	addresslistG FirstG;
} GraphList;

/* Definisi list : */
/* List kosong : First(L) = NilList */
/* Setiap elemen dengan addresslist P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=NilList */

#define InfoG(P) (P)->infoG
#define NextG(P) (P)->nextG
#define Tetangga(P) (P)->tetangga
#define FirstG(L) ((L).FirstG)


/****************** Manajemen Memori ******************/
addresslistG AlokasiGraph (infotypelist X);

/****************** Penambahan Elemen ******************/
void InsVFirstGraph (GraphList *Graph, infotypelist X, List L);

/****************** Konstruktor ******************/
List CreateListNeighbors(int n, MATRIKS Mat);

void CreateEmptyGraph(GraphList *Graph, MATRIKS Mat);

boolean IsAdjacent(GraphList Graph, int a, int b);

List Neighbors(GraphList Graph, int n);

#endif