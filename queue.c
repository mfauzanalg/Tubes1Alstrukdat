#include "queue.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q) == NilQueue && Tail(Q) == NilQueue);
}

boolean IsFullQueue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
	return (NBElmtQueue(Q) == MaxElQueue(Q));
}

int NBElmtQueue (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmptyQueue(Q)){
		return 0;
	}
	else{
		if (Head(Q) < Tail(Q)){
			return (Tail(Q) - Head(Q) + 1);
		}
		else{
			return (MaxElQueue(Q) - Head(Q) + Tail (Q) + 1);
		}
	}

}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (infotypequeue*) malloc((Max+1)*sizeof(infotypequeue));
	if ((*Q).T == NULL){
	    MaxElQueue(*Q) = 0;
	}
	else{
	    MaxElQueue(*Q) = Max;
	}
	Head(*Q) = NilQueue;
	Tail(*Q) = NilQueue;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
	free ((*Q).T);
	MaxElQueue (*Q) = 0;
}

/* *** Primitif AddQueue/Delete *** */
void AddQueue (Queue * Q, infotypequeue X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
	if (IsEmptyQueue(*Q)){
		Head(*Q)++;
		Tail(*Q)++;
		InfoTail(*Q) = X;
	}
	else if (Tail(*Q) == MaxElQueue(*Q)){
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
	else{
		Tail(*Q) += 1;
		InfoTail(*Q) = X;
	}
}


void Del (Queue * Q, infotypequeue * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
	*X = InfoHead(*Q);

	if ((Head(*Q) < Tail(*Q)) || (Head(*Q) > Tail(*Q))) {
		Head(*Q) += 1;
	}
	else{
		Head(*Q) = 0;
		Tail(*Q) = 0;
	}
}