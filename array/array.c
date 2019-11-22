#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"


void CreateEmptyArray(TabBang *Arr, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	int i;
	MaxElArr(*Arr) = maxel;
	TI(*Arr) = (ElType*) malloc((maxel+1)*sizeof(ElType));
	for (i = IdxMin;i <= MaxElArr(*Arr); i++){
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

void DealokasiArr(TabBang *Arr){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElArr(T)=0; Neff(T)=0 */
	CreateEmptyArray(Arr,0);
	MaxElArr(*Arr) = 0;
	free (TI(*Arr));
}

int NbElmtArr(TabBang T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	int i;
	boolean found;
	
	if (Elmt(T,1).jum == ValUndef){
		return 0;
	}
	
	i = 1;
	found = false;
	while ((!found) && i <= MaxElArr(T)){
			if (Elmt(T,i).jum == ValUndef){
				found = true;
			}
			else {
				i += 1;
			}
	}
	
	if (!found){
		i = MaxElArr(T) + 1;
	}
	return (i-1);

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
	return (NbElmtArr(T));

}

void CopyArr (TabBang Tabin, TabBang *Tabout){
/*Mengcopy isi Tabin ke Tabout*/
	int i;
	CreateEmptyArray (&*Tabout, MaxElArr(Tabin));
	for (i = 1; i <= GetLastIdx(Tabin); i++){
		Elmt(*Tabout,i).nomor = Elmt(Tabin,i).nomor;
		Elmt(*Tabout,i).type = Elmt(Tabin,i).type;
		Elmt(*Tabout,i).jum = Elmt(Tabin,i).jum;
		Elmt(*Tabout,i).lev = Elmt(Tabin,i).lev;
		Elmt(*Tabout,i).A = Elmt(Tabin,i).A;
		Elmt(*Tabout,i).M = Elmt(Tabin,i).M;
		Elmt(*Tabout,i).P = Elmt(Tabin,i).P;
		Elmt(*Tabout,i).U = Elmt(Tabin,i).U; 
		Elmt(*Tabout,i).letak.X = Elmt(Tabin,i).letak.X; 
		Elmt(*Tabout,i).letak.Y = Elmt(Tabin,i).letak.Y; 
		Elmt(*Tabout,i).attack = Elmt(Tabin,i).attack; 
		Elmt(*Tabout,i).move = Elmt(Tabin,i).move; 
	}
}