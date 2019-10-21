#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"


void MakeEmpty(TabBang *Arr, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	int i;
	MaxEl(*Arr) = maxel;
	TI(*Arr) = (int*) malloc((maxel+1)*sizeof(ElType));
	for (i = IdxMin;i <= MaxEl(*Arr); i++){
		Elmt(*Arr,i).milik = ValUndef;
		Elmt(*Arr,i).jum = ValUndef;
		Elmt(*Arr,i).lev = ValUndef;
		Elmt(*Arr,i).A = ValUndef;
		Elmt(*Arr,i).M = ValUndef;
		Elmt(*Arr,i).P = false;
		Elmt(*Arr,i).U = ValUndef;
		Elmt(*Arr,i).letak.X = ValUndef;
		Elmt(*Arr,i).letak.Y = ValUndef;
	}
}

void Dealokasi(TabBang *Arr){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
	MakeEmpty(Arr,0);
	MaxEl(*Arr) = 0;
	free (TI(*Arr));
}

int MaxElement(TabBang T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return (MaxEl(T));
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
	return (IdxMin);
}

IdxType GetLastIdx(TabBang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
	return (NbElmt(T));

}

boolean IsIdxValid(TabBang T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	return ((i >= IdxMin) && (i <= MaxEl(T)));
}

boolean IsIdxEff(TabBang T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
	return ((i >= IdxMin) && (i <= NbElmt(T)));
}

boolean IsEmpty(TabBang T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (NbElmt(T) == 0);
}

boolean IsFull(TabBang T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (NbElmt(T) == MaxEl(T));
}
