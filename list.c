#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
/* Mengirim true jika list kosong */
	return (First(L) == NilList);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	First(*L) = NilList;
}

/****************** Manajemen Memori ******************/
addresslist Alokasi (infotypelist X){
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
	addresslist P;
	P =  malloc(1*sizeof(infotypelist));

	if (P == NilList){
		return P;
	}
	else{
		Info(P) = X;
		Next(P) = NilList;
		return P;
	}

}

void DealokasiList (addresslist *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist Search (List L, infotypelist X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */
    addresslist P;
    boolean found;
    P = First(L);
    found = false;
    while ((P != NilList) && (!found)){
        if (X == Info(P)){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    if (found){
        return P;
    }
    else{
        return NilList;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypelist X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	addresslist P;
	P = Alokasi(X);

	if (P != NilList){
		Next (P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotypelist X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	addresslist Last, ini;
	ini = Alokasi(X);

	if (ini != NilList){
		Last = First(*L);
		if (Last != NilList){
			while (Next(Last) != NilList){
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
void DelVFirst (List *L, infotypelist *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	addresslist P;
	P = First(*L);

	*X = Info(P);
	First(*L) = Next(P);
	DealokasiList(&P);
}

void DelVLast (List *L, infotypelist *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
	addresslist Prec; //P sebelum Terakhir
	addresslist Last;
	Last = First(*L);
	Prec = NilList;

	while (Next(Last) != NilList){
		Prec = Last;
		Last = Next(Last);
	}

	*X = Info(Last);

	if (Prec == NilList){
	    First(*L) = NilList;
	}
	else {
	    Next(Prec) = NilList;
	}

	DealokasiList(&Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addresslist P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addresslist P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}


void InsertAfter (List *L, addresslist P, addresslist Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, addresslist P){                                             
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	addresslist Last;

	if (IsEmptyList(*L)){
		InsertFirst(L, P);
	}
	else{
		Last = First(*L);
		while (Next(Last) != NilList){
			Last = Next(Last);
		}
		Next(Last) = P;
	}
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addresslist *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(*P);
}

void DelP (List *L, infotypelist X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	addresslist P;
	addresslist Prec;
	addresslist addr1 = Search(*L, X);

	if(addr1 != NilList){
		P = First(*L);
		Prec = NilList;

		if (Info(P) ==  X){
			First(*L) = Next(P);
			DealokasiList(&P);
		}
		else{
			while (Info(P) != X && P != NilList){
				Prec = P;
				P = Next(P);
			}

			if (P != NilList){
				Next(Prec) = (Next(Next(Prec)));
				DealokasiList(&P);
			}
		}
	}
}

void DelLast (List *L, addresslist *P){ //!!!!!!!!!!!
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
	addresslist Prec = NilList;
	addresslist Last;
	Last = First(*L);


	if(Next(Last) == NilList){
		*P = Last;
		Last = NilList;
		First(*L) = NilList;
	}
	else{
		while (Next(Last) != NilList){
			Prec = Last;
			Last = Next(Last);
		}

		*P = Last;
		if (Prec != NilList){
	      Next(Prec) = NilList;
	    }
	}
}


void DelAfter (List *L, addresslist *Pdel, addresslist Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	addresslist P;
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
	addresslist P;

	if (IsEmptyList(L)){
		printf("[]");
	}
	else{
		P = First(L);
		printf("[");
		while(Next(P) != NilList){
			printf("%d,", Info(P));
			P = Next(P);
		}
		if (Next(P) == NilList){
			printf("%d]", Info(P));
		}
	}
}

int NbElmtList (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	addresslist P;
	int count = 0;

	if (IsEmptyList(L)){
		return count;
	}
	else{
		P = First(L);
		while (P != NilList){
			count ++;
			P = Next(P);
		}
		return count;
	}
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	addresslist P;

	CreateEmptyList(L3);
	P = First(*L1);
	if (P != NilList){
		First(*L3) = First(*L1);
		while (Next(P) != NilList){
			P = Next(P);
		}
		Next (P) = First(*L2);
	}
	else{
		First(*L3) = First(*L2);
	}

	CreateEmptyList(L1);
	CreateEmptyList(L2);
}

void CopyList (List L1, List *L2){
	int x;
	addresslist P;
	addresslist P1;
	int i;
	
	CreateEmptyList(&*L2);
	P = First(L1);
	
	for (i = 1; i <= NbElmtList(L1); i++){
		P1 = Alokasi(Info(P));
		InsertLast(&*L2, P1);
		P = Next(P);
	}

}
