#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
	return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	address P;
	P = (address) malloc(1*sizeof(ElmtMatList));

	if (P == Nil){
		return P;
	}
	else{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}

}

void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	address P;
	P = First(L);

	while (P != Nil){
		if (Info(P) == X){
			return P;
		}
		else{
			P = Next(P);
		}
	}

	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	address P;
	P = Alokasi(X);

	if (P != Nil){
		Next (P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	address Last, ini;
	ini = Alokasi(X);

	if (ini != Nil){
		Last = First(*L);
		if (Last != Nil){
			while (Next(Last) != Nil){
				Last = Next(Last);
			}
			Next(Last) = ini;
		}
		else{
			InsVFirst(L,X);
		}
	}
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	address P;
	P = First(*L);

	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
	address Prec; //P sebelum Terakhir
	address Last;
	Last = First(*L);
	Prec = Nil;

	while (Next(Last) != Nil){
		Prec = Last;
		Last = Next(Last);
	}

	*X = Info(Last);

	if (Prec == Nil){
	    First(*L) = Nil;
	}
	else {
	    Next(Prec) = Nil;
	}

	Dealokasi(&Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}


void InsertAfter (List *L, address P, address Prec){ //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P){                                             
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;

	if (IsEmpty(*L)){
		InsertFirst(L, P);
	}
	else{
		Last = First(*L);
		while (Next(Last) != Nil){
			Last = Next(Last);
		}
	}

	Next(Last) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(*P);
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	address P;
	address Prec;
	P = First(*L);
	Prec = Nil;

	if (Info(P) ==  X){
		First(*L) = Next(P);
		Dealokasi(&P);
	}
	else{
		while (Info(P) != X && P != Nil){
			Prec = P;
			P = Next(P);
		}

		if (P != Nil){
			Next(Prec) = (Next(Next(Prec)));
			Dealokasi(&P);
		}
	}
}

void DelLast (List *L, address *P){ //!!!!!!!!!!!
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
	address Prec = Nil;
	address Last;
	Last = First(*L);


	if(Next(Last) == Nil){
		*P = Last;
		Last = Nil;
		First(*L) = Nil;
	}
	else{
		while (Next(Last) != Nil){
			Prec = Last;
			Last = Next(Last);
		}

		*P = Last;
		if (Prec != Nil){
	      Next(Prec) = Nil;
	    }
	}
}


void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	address P;
	P = First(*L);

	while (P != Prec){
		P = Next(P);
	}

	*Pdel = Next(P);
	Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	address P;

	if (IsEmpty(L)){
		printf("[]");
	}
	else{
		P = First(L);
		printf("[");
		while(Next(P) != Nil){
			printf("%d,", Info(P));
			P = Next(P);
		}
		if (Next(P) == Nil){
			printf("%d]", Info(P));
		}
	}
}

int NbElmtMat (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	address P;
	int count = 0;

	if (IsEmpty(L)){
		return count;
	}
	else{
		P = First(L);
		while (P != Nil){
			count ++;
			P = Next(P);
		}
		return count;
	}
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
	address P;
	infotype maks;
	P = First(L);

	maks = Info(P);
	while (P != Nil){
		if (Info(P) > maks){
			maks = Info(P);
		}
		P = Next(P);
	}
	return maks;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	address P;

	CreateEmpty(L3);
	P = First(*L1);
	if (P != Nil){
		First(*L3) = First(*L1);
		while (Next(P) != Nil){
			P = Next(P);
		}
		Next (P) = First(*L2);
	}
	else{
		First(*L3) = First(*L2);
	}

	CreateEmpty(L1);
	CreateEmpty(L2);
}
