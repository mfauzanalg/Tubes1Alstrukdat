#include <stdio.h>
#include "stackplayer.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptystackp (stackp *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stackp S yang kosong berkapasitas MaxElstackp */
/* jadi indeksnya antara 1.. MaxElstackp+1 karena 0 tidak dipakai */
/* Ciri stackp kosong : TOP bernilai Nilstackp */
	Top(*S) = Nilstackp;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptystackp (stackp S){
/* Mengirim true jika stackp kosong: lihat definisi di atas */
	return Top(S) == Nilstackp;
}

boolean IsFullstackp (stackp S){
/* Mengirim true jika tabel penampung nilai elemen stackp penuh */
	return Top(S) == MaxElstackp;
}

/* ************ Menambahkan sebuah elemen ke stackp ************ */
void Pushp (stackp * S, infotypestackp X){
/* Menambahkan X sebagai elemen stackp S. */
/* I.S. S mungkin kosong, tabel penampung elemen stackp TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	if (IsEmptystackp(*S)){
		Top(*S) = 1;
		InfoTop(*S) = X;
	}
	else{
		Top(*S) += 1;
		InfoTop(*S) = X;
	}
}

/* ************ Menghapus sebuah elemen stackp ************ */
void Popp (stackp * S, infotypestackp* X){
/* Menghapus X dari stackp S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	if(Top(*S) == 1){
		*X = InfoTop(*S);
		Top(*S) = Nilstackp;
	}
	else{
		*X = InfoTop(*S);
		Top(*S) -= 1;
	}
}

void CopyPlayer (PLAYER Pin, PLAYER *Pout){
	(*Pout).Skill = Pin.Skill;
	(*Pout).Shield = Pin.Shield;
	CopyList(Pin.ListB, &(*Pout).ListB);

}