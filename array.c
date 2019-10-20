/#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arraydinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	int i;
	MaxEl(*T) = maxel;
	TI(*T) = (int*) malloc((maxel+1)*sizeof(ElType));
	for (i = IdxMin;i <= MaxEl(*T); i++){
		Elmt(*T,i) = ValUndef;
	}
}

void Dealokasi(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
	MakeEmpty(T,0);
	MaxEl(*T) = 0;
	free (TI(*T));
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	int i;
	boolean found;
	
	if (Elmt(T,1)==0){
		return 0;
	}
	
	i = 1;
	found = false;
	while ((!found) && i <= MaxEl(T)){
			if (Elmt(T,i) == 0){
				found = true;
			}
			else {
				i += 1;
			}
	}
	
	if (!found){
		i = MaxEl(T) + 1;
	}
	return (i-1);

}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return (MaxEl(T));
}


/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
	return (IdxMin);
}



IdxType GetLastIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
	return (NbElmt(T));

}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	return ((i >= IdxMin) && (i <= MaxEl(T)));
}

boolean IsIdxEff(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
	return ((i >= IdxMin) && (i <= NbElmt(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (NbElmt(T) == MaxEl(T));
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

	int N, i;

	scanf("%d", &N);
	if (N == 0){
		MakeEmpty(T,0);
	}
	
	while (!((0 <= N) && (N <= MaxEl(*T)))){
		scanf("%d", &N);
	}
	
	MakeEmpty (T, N);

	for (i = IdxMin; i <= N; i++){
		scanf("%d", &Elmt(*T, i));
	}
}	

void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
	int i;
	
	if (IsEmpty(T)){
		printf("[]");
	}
	else {
		printf("[");
		for (i = IdxMin; i <= NbElmt(T)-1; i ++){
			printf("%d,", Elmt(T,i));
		}
		printf("%d", Elmt(T,NbElmt(T)));
		printf("]");
	}

}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
	TabInt T3;
	int i;
	
	MakeEmpty (&T3,MaxEl(T2));
	
	
	if (plus) {
		for (i = 1; i <= NbElmt (T1); i++){
			Elmt(T3,i) = Elmt(T1,i) + Elmt (T2,i);
		}
	}
	else if (!plus) {
		for (i = 1; i <= NbElmt (T1); i++){
			Elmt(T3,i) = Elmt(T1,i) - Elmt (T2,i);
		}
	}
	return T3;

}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
	int i = IdxMin;
	boolean same = true;
	
	if (NbElmt(T1) != NbElmt(T2)){
		same = false;
	}
	
	else{
		if (NbElmt(T1) == 0){
			same = true;
		}
		else {
			while (same && i <= NbElmt(T1)){
				if (Elmt(T1,i) == Elmt(T2,i)){
					i += 1;
				}
				else{
					same = false;
				}
			}
		}
	}	
	return same;

}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
	int i = IdxMin;
	boolean ada = false;
	
	if (IsEmpty(T)){
		return IdxUndef;
	}
	else {
		while ((!ada) && i <= NbElmt(T)){
			if (Elmt(T,i) == X){
				ada = true;
			}
			else {
				i += 1;
			}
		}
	}
	
	if (!ada){
		i = IdxUndef;
	}
	return i;
}


boolean SearchB(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
	int i = IdxMin;
	boolean ada = false;
	
	while ((!ada) && i <= NbElmt(T)){
		if (Elmt(T,i) == X){
			ada = true;
		}
		else{
			i += 1;
		}
	}
	return ada;

}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
	int i = IdxMin;
	*Max = Elmt(T,i);
	*Min = Elmt(T,i);
	
	for (i = IdxMin; i <= NbElmt(T); i++){
		if (Elmt(T,i) > *Max){
			*Max = Elmt (T,i);
		}
		if (Elmt(T,i) < *Min){
			*Min = Elmt (T,i);
		}
	}

}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
	int i;
	MakeEmpty (&*Tout,MaxEl(Tin));
	
	for (i = IdxMin; i <= NbElmt(Tin); i++){
		Elmt (*Tout,i) = Elmt(Tin, i);
	}
}


ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
	int total;
	int i;
	total = 0;

	if (IsEmpty(T)){
		return 0;
	}
	
	for (i = IdxMin; i <= NbElmt(T); i++){
		total = total + Elmt(T,i);
	}
	
	return total;
}

int CountX(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
	int count, i;
	count = 0;
	
	if (IsEmpty(T)){
		return 0;
	}

	for (i = IdxMin; i<=NbElmt(T); i++){
		if (Elmt(T,i) == X){
			count = count + 1;
		}
	}
	return count;
}

boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
	int i = IdxMin;
	
	i = 1;
	
	if (IsEmpty(T)){
		return false;
	}
	
	if (!IsEmpty(T)){
		for (i=IdxMin; i<=NbElmt (T); i++){
			if (Elmt(T,i) % 2 != 0){
				return false;
			}
		}
	}
	return true;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
	IdxType Pass, i, IMax;
	ElType Temp;
	IdxType FirstIdx = IdxMin;
    IdxType LastIdx = NbElmt(*T);

    if (NbElmt(*T)>1 && asc){
        for (Pass=FirstIdx+1;Pass<=LastIdx;Pass++){
            for (i=FirstIdx;i<Pass;i++){
                if (Elmt(*T,i)>Elmt(*T,Pass)){
                    Temp=Elmt(*T,Pass);
                    Elmt(*T,Pass)=Elmt(*T,i);
                    Elmt(*T,i)=Temp;
                }
            }
        }
    }
    

    else if (NbElmt(*T)>1 && (!asc)){
        for (Pass=FirstIdx;Pass<LastIdx;Pass++){
            IMax=Pass;
            for(i=Pass+1;i<=LastIdx;i++){
                if (Elmt(*T,IMax)<Elmt(*T,i)){
                    IMax=i;
                }
            }

            Temp=Elmt(*T,Pass);
            Elmt(*T,Pass)=Elmt(*T,IMax);
            Elmt(*T,IMax)=Temp;
        }
    }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
	if (IsEmpty(*T)){
        Elmt(*T,GetFirstIdx(*T))=X;
    }
	else {
        Elmt(*T,GetLastIdx(*T)+1)=X;
    }
}


/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
	*X = Elmt(*T, NbElmt(*T));
	Elmt(*T, NbElmt(*T)) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
	MaxEl(*T) += num;
	TI(*T) = realloc(TI(*T), (MaxEl(*T)+1)*sizeof(int));
}

void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan NbElmt < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
	MaxEl(*T) -= num;
	TI(*T) = realloc(TI(*T), (MaxEl(*T)+1)*sizeof(int));
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
	MaxEl(*T) = NbElmt(*T);
	TI(*T) = realloc(TI(*T), (MaxEl(*T)+1)*sizeof(int));
}
