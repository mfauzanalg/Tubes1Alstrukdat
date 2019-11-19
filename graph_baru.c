#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
#include "list.h"
#include "graph_baru.h"


/****************** Manajemen Memori ******************/
addresslistG AlokasiGraph (infotypelist X, List L){
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
	addresslistG P;
	P =  malloc(1*sizeof(infotypelistGraph));
	if (P == NilList){
		return P;
	}
	else{
		Induk(P) = X;
		Anak(P) = L;
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
	P = AlokasiGraph(X, L);

	if (P != NilList){
		NextG(P) = FirstG(*Graph);
		FirstG(*Graph) = P;
	}
}

void InsVLastGraph (GraphList *Graph, infotypelist X, List L){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	addresslistG Last, Current;
	Current = AlokasiGraph(X, L);
	if (Current != NilList){
		Last = FirstG(*Graph);
		if (Last != NilList){
			while (NextG(Last) != NilList){
				Last = NextG(Last);
			}
			NextG(Last) = Current;
		}
		else{
			InsVFirstGraph(Graph,X,L);
		}
	}
}


/****************** Konstruktor ******************/
List CreateListNeighbors(int n, MATRIKS *Mat){
	List L;
	CreateEmptyList(&L);
	for (int j = KolMin; j <= GetLastIdxKol(*Mat); j++){
		if (ElmtMat(*Mat, n, j) == 1){
			InsVLast(&L,j);
		}
	}
	return L;
}

void CreateEmptyGraph(GraphList *Graph, int maxel, MATRIKS *Mat)
/* array untuk representasi graph, array berisikan list of bangunan yang terhubung */
{
	FirstG(*Graph) = NilList;
	for (int i=BrsMin; i <= GetLastIdxBrs(*Mat); i++){
		if (i == 1){
			InsVFirstGraph(Graph, i, CreateListNeighbors(i, Mat));
		}
		else{
			InsVLastGraph(Graph, i, CreateListNeighbors(i, Mat));
		}
	}
}

boolean IsAdjacent(GraphList *Graph, int a, int b)
/* mengecek apakah bangunan a bersambung dengan bangunan b */
{
	addresslistG P;
	addresslist Q;
    boolean found;
    P = FirstG(*Graph);
    found = false;
    while (P != NilList){
        if (a == Induk(P)){
            Q = First(Anak(P));
			while ((Q != NilList) && (!found)){
				if (b == Info(Q)){
					found = true;
				}
				else {
					Q = Next(Q);
				}
			}
        }
        else{
            P = NextG(P);
        }
    }
	if (P == NilList){
		found = false;
	}
	else if (Q == NilList){
		found = false;
	}
	else{
		found = true;
	}
	return (found);
}


List Neighbors(GraphList Graph, int n){
	List L;
	addresslistG P;
	P = FirstG(Graph);
	while (P != NilList){
		if (Induk(P) == n){
			L = Anak(P);
		}
	}
	return L;
}
