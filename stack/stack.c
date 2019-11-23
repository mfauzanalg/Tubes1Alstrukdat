#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 1.. MaxElStack+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai NilStack */
	Top(*S) = NilStack;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return Top(S) == NilStack;
}

boolean IsFullStack (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return Top(S) == MaxElStack;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypestack X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	if (IsEmptyStack(*S)){
		Top(*S) = 1;
		InfoTop(*S) = X;
	}
	else{
		Top(*S) += 1;
		InfoTop(*S) = X;
	}
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypestack* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	if(Top(*S) == 1){
		*X = InfoTop(*S);
		Top(*S) = NilStack;
	}
	else{
		*X = InfoTop(*S);
		Top(*S) -= 1;
	}
}