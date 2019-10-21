#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void CreateEmptyMatriks (int NB, int NK, MATRIKS * M){
 /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff (*M) = NB;
    NKolEff (*M) = NK;
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return (BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return (KolMin);
}


indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return (NBrsEff(M));
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return (NKolEff(M));
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	int i;
	int j;
	CreateEmptyMatriks(MIn.NBrsEff, MIn.NKolEff, &*MHsl);
	for (i = 1; i <= NBrsEff(MIn); i++){
		for (j = 1; j <= NKolEff(MIn); j++){
			ElmtMat(*MHsl, i, j) = ElmtMat(MIn, i, j);
		}
	}
}

	

void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	int i;
	int j;

	for (i = 1; i <= NBrsEff(M); i++){
		for (j = 1; j <= NKolEff(M)-1; j++){
			printf("%d ", ElmtMat(M,i,j));
		}
		printf("%d", ElmtMat(M, i, NKolEff(M)));

		if (j == NKolEff(M)){
			if (i != NBrsEff(M)){
				printf("\n");
			}
		}
	}
}