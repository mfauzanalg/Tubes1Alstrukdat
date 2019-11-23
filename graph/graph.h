/* ADT GRAPH */

#ifndef GRAPH_H
#define GRAPH_H


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
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka InfoG(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */

/****************** Penambahan Elemen ******************/
void InsVFirstGraph (GraphList *Graph, infotypelist X, List L);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

/****************** Konstruktor ******************/
List CreateListNeighbors(int n, MATRIKS Mat);
/*Mengembalikan List yang bertetangga dengan n dari Matriks*/

void CreateEmptyGraph(GraphList *Graph, MATRIKS Mat);
/*Membuat Graph kosong*/

boolean IsAdjacent(GraphList Graph, int a, int b);
/* mengecek apakah bangunan a bersambung dengan bangunan b */

List Neighbors(GraphList Graph, int n);
// Mengembalikan list yang terhubung dengan n pada graph

#endif