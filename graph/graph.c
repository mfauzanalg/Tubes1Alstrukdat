#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"


/****************** Manajemen Memori ******************/
addresslistG AlokasiGraph(infotypelist X){
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka InfoG(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
	addresslistG P;
	P =  malloc(1*sizeof(infotypelist));
	if (P == NilList){
		return P;
	}
	else{
		InfoG(P) = X;
		Tetangga(P) = NilList;
		NextG(P) = NilList;
		return P;
	}
}

/****************** Penambahan Elemen ******************/
void InsVFirstGraph (GraphList *Graph, infotypelist X, List L){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	addresslistG P;
	P = AlokasiGraph(X);
	Tetangga(P) = NilList;
	if (P != NilList){
		NextG(P) = FirstG(*Graph);
		FirstG(*Graph) = P;
		Tetangga(P) = First(L);
	}
}
/****************** Konstruktor ******************/
List CreateListNeighbors(int n, MATRIKS Mat){
	List L;
	CreateEmptyList(&L);
	for (int j = KolMin; j <= GetLastIdxKol(Mat); j++){
		if (ElmtMat(Mat, n, j) == 1){
			InsVLast(&L,j);
		}
	}
	return L;
}

void CreateEmptyGraph(GraphList *Graph, MATRIKS Mat)
/* array untuk representasi graph, array berisikan list of bangunan yang terhubung */
{
	FirstG(*Graph) = NilList;
	//Tetangga(FirstG(*Graph)) = NilList;
	for (int i=GetLastIdxBrs(Mat); i >= BrsMin; i--){
		InsVFirstGraph(Graph, i, (CreateListNeighbors(i, Mat)));
	}
}

boolean IsAdjacent(GraphList Graph, int a, int b)
/* mengecek apakah bangunan a bersambung dengan bangunan b */
{
	List L;
	addresslist P;
	boolean found;
	found = false;
	L = Neighbors(Graph, a);
	P = First(L);
	while ((P != NilList) && (!found)){
		if (Info(P) == b){
			found = true;
		}
		else{
			P = Next(P);
		}
	}
	return found;
}


List Neighbors(GraphList Graph, int n){
	List L;
	addresslistG P;
	addresslist Q, precR,R;
	infotypelist X;
	boolean found;
	found = false;
	P = FirstG(Graph);
	CreateEmptyList(&L);
	while ((P != NilList) && (!found)){
		if (InfoG(P) == n){
			found = true;
			First(L) = Tetangga(P);
			// PrintInfo(L);
		}
		else{
			P = NextG(P);
		}
	}
	return L;
}