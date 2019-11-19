/* ADT GRAPH */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "list.h"
#include "matriks.h"


#define NilList NULL


typedef struct tElmtMatlistG *addresslistG;

typedef struct{
  infotypelist induk;
  List anak;
}infotypelistGraph;

typedef struct tElmtMatlistG {
	infotypelistGraph infoG;
	addresslistG nextG;
} ElmtListGraph;

typedef struct {
	addresslistG FirstG;
} GraphList;

/* Definisi list : */
/* List kosong : First(L) = NilList */
/* Setiap elemen dengan addresslist P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=NilList */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

#define Induk(P) ((P)->infoG).induk
#define Anak(P) ((P)->infoG).anak
#define NextG(P) (P)->nextG
#define FirstG(G) ((G).FirstG)


/****************** Manajemen Memori ******************/
addresslistG AlokasiGraph (infotypelist X, List L);

/****************** Penambahan Elemen ******************/
void InsVFirstGraph (GraphList *Graph, infotypelist X, List L);

void InsVLastGraph (GraphList *Graph, infotypelist X, List L);

/****************** Konstruktor ******************/
List CreateListNeighbors(int n, MATRIKS *Mat);

void CreateEmptyGraph(GraphList *Graph, int maxel, MATRIKS *Mat);

boolean IsAdjacent(GraphList *Graph, int a, int b);

List Neighbors(GraphList Graph, int n);

#endif