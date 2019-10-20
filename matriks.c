#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
 /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff (*M) = NB;
    NKolEff (*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return (((i >= BrsMin) && (i <= BrsMax)) && ((j >= KolMin) && (j <= KolMax)));
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

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return (((i >= BrsMin) && (i <= GetLastIdxBrs(M))) && ((j >= KolMin) && (j <= GetLastIdxKol(M))));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return (Elmt(M,i,i));
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	int i;
	int j;
	MakeMATRIKS(MIn.NBrsEff, MIn.NKolEff, &*MHsl);
	for (i = 1; i <= NBrsEff(MIn); i++){
		for (j = 1; j <= NKolEff(MIn); j++){
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
		}
	}
}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

	MakeMATRIKS(NB, NK, &*M);
    int i;
    int j;

	for (i = 1; i <= NBrsEff(*M); i++){
		for( j = 1; j <= NKolEff(*M); j++){
			scanf("%d", &Elmt(*M, i, j));
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
			printf("%d ", Elmt(M,i,j));
		}
		printf("%d", Elmt(M, i, NKolEff(M)));

		if (j == NKolEff(M)){
			if (i != NBrsEff(M)){
				printf("\n");
			}
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);

    int i;
    int j;

    for (i = 1; i <= NBrsEff(M1); i++){
        for (j = 1; j <= NKolEff(M1); j++){
            Elmt(M3, i, j) = Elmt(M1, i, j) + Elmt (M2, i,j);
        }
    }

    return M3;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);

    int i;
    int j;

    for (i = 1; i <= NBrsEff(M1); i++){
        for (j = 1; j <= NKolEff(M1); j++){
            Elmt(M3, i, j) = Elmt(M1, i, j) - Elmt (M2, i,j);
        }
    }

    return M3;
}


MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    int i;
    int j;
    int k;

    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);

    for (i = 1; i <= NBrsEff(M3); i++){
    	for (j = 1; j <= NKolEff(M3); j++){
			for (k = 1; k <= NKolEff(M1); k++){
				Elmt(M3, i, j) += (Elmt(M1,i,k)*Elmt(M2,k,j));
			}
    	}
    }
    return M3;
}

MATRIKS KaliKons (MATRIKS M, ElType X){
    /* Mengirim hasil perkalian setiap elemen M dengan X */
    MATRIKS M2;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &M2);
    
    int i;
    int j;

    for (i = 1; i <= NBrsEff(M); i++){
        for (j = 1; j <= NKolEff(M); j++){
            Elmt(M2, i, j) = (Elmt(M, i, j) * X);
        }
    }
    return M2;
}


void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
    int i;
    int j;

    for (i = 1; i <= NBrsEff(*M); i++){
        for (j = 1; j <= NKolEff(*M); j++){
            Elmt(*M, i, j) = (Elmt(*M, i, j)*K);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
	int i;
	int j;

	if (NKolEff(M1) != NKolEff(M2) || NBrsEff(M1) != NBrsEff(M2)){
		return false;
	}
	
	for (i = 1; i <= NBrsEff(M1); i++){
		for (j = 1; j <= NKolEff(M1); j++){
			if (Elmt(M1,i,j) != Elmt (M2, i, j)){
				return false;
			}
		}
	}
	
	return true;
}


boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return (!(EQ(M1,M2)));
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return(NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return (NBrsEff(M) == NKolEff (M));
}
boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
	int i;
	int j;

	if (!(IsBujurSangkar(M))){
		return false;
	}
	else{
		for (i = 1; i <= NBrsEff(M); i++){
			for (j = 1; j <= NKolEff(M); j++){
				if (Elmt(M,i,j) != Elmt(M,j,i)){
					return false;
				}
			}
		}
	}

	return true;
}

boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
	int i;
	int j;

	if (!(IsBujurSangkar(M))){
		return false;
	}
	else{
		for (i = 1; i <= NBrsEff(M); i++){
			for (j = 1; j <= NBrsEff(M); j++){
				if (i != j){
					if (Elmt(M, i, j) != 0){
						return false;
						
					}
				}
				else {
					if (Elmt(M, i, j) != 1){
						return false;
					}
				}
			}
		}
	}
	return true;
}

boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
	int sparse;
	int i;
	int j;
	int jumlah;

	sparse = (5*NBElmt(M))/100;

	jumlah = 0;
	for (i = 1; i <= NBrsEff(M); i++){
		for (j = 1; j <= NKolEff(M); j++){
			if (Elmt(M,i,j) != 0){
				jumlah += 1;
			}
		}
	}

	if (jumlah <= sparse){
		return true;
	}
	else{
		return false;
	}
}

MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	int i;
	int j;

	for (i = 1; i <= NBrsEff(M); i++){
		for (j = 1; j <= NKolEff(M); j++){
			Elmt(M,i,j) = Elmt(M,i,j)*-1;
		}
	}
	return M;
}

MATRIKS MatriksKecil (MATRIKS M, int kolom){
//Baris 1 di delete terus kolom pilihan di delete juga
	int i;
	int j;
	MATRIKS M2;
	int kolomke = 1;

	MakeMATRIKS((NBrsEff(M)-1), (NKolEff(M)-1), &M2);

	for (i = GetFirstIdxBrs(M)+1; i <= NBrsEff(M); i++){
		for (j = 2; j <= NKolEff(M); j++){
			if (j != kolom){
				Elmt(M2,i,kolomke) = Elmt(M,i,j);
				kolomke += 1;
			}
			if (kolomke > NKolEff(M2)){
				kolomke = 1;
			}
		}
	}
	return M2;
}


float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
	int x;
	int j;
	int a;
	float hasil;
	float temp;
	int kolomke;
	MATRIKS M2;

	hasil = 0;

	if ((NBrsEff(M) == 1) && (NKolEff(M) == 1)){
		hasil = (Elmt(M,1,1)*1.0);
	}
	if ((NBrsEff(M) == 2) && (NKolEff(M) == 2)){
		hasil = hasil + (Elmt(M,1,1)*Elmt(M,2,2))-(Elmt(M,1,2)*Elmt(M,2,1));
	}
	else {
		for (x = 1; x <= NKolEff(M);x++){

			kolomke = 1;
			MakeMATRIKS((NBrsEff(M)-1), (NKolEff(M)-1), &M2);

			for (a = 2; a <= NBrsEff(M); a++){
				for (j = 1; j <= NKolEff(M); j++){
					if (j != x){
						Elmt(M2,a-1,kolomke) = Elmt(M,a,j);
						kolomke += 1;
					}
					if (kolomke > NKolEff(M2)){
						kolomke = 1;
					}
				}
			}


			if (x%2==0){
				temp = (-1) * Determinan(M2);
				hasil = hasil + Elmt(M,1,x) * temp;
			}
			else{
				hasil = hasil + Elmt(M,1,x) * Determinan(M2);
			}		
		}
	}
	return hasil;
}


void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	PKaliKons(&*M, -1);
}

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	int i;
	int j;
	MATRIKS M2;

	MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &M2);

	for (i = 1; i <= NBrsEff(*M); i++){
		for (j = 1; j <= NKolEff(*M); j++){
			Elmt(M2, j, i) = Elmt(*M, i, j);
		}
	}

	CopyMATRIKS (M2, &*M);
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
	int j;
	int count = 0;
	int total = 0;
	float hasil =0;
	
	for (j = 1; j <= NKolEff(M); j++){
		count = count + 1;
		total = total + Elmt(M, i, j);
	}
	
	hasil = total/count;
	
	return hasil;
}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
	int i;
	int count = 0;
	int total = 0;
	float hasil =0;
	
	for (i = 1; i <= NBrsEff(M); i++){
		count = count + 1;
		total = total + Elmt(M, i, j);
	}
	
	hasil = total/count;
	
	return hasil;
}


void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
	
	int j;
	*max = -9999;
	*min = 9999;
	
	for (j = 1; j <= NKolEff(M); j++){
		if (Elmt (M, i, j) > *max){
			*max = Elmt (M, i, j);
		}
		if (Elmt (M, i, j) < *min){
			*min = Elmt (M, i, j);
		}
	}
}


void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
	int i;
	*max = -9999;
	*min = 9999;
	
	for (i = 1; i <= NBrsEff(M); i++){
		if (Elmt (M, i, j) > *max){
			*max = Elmt (M, i, j);
		}
		if (Elmt (M, i, j) < *min){
			*min = Elmt (M, i, j);
		}
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
	int j;
	int count = 0;
	
	for (j = 1; j <= NKolEff(M); j++){
		if (Elmt(M, i, j) == X){
			count = count +1;
		}
	}
	
	return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
	int i;
	int count = 0;
	
	for (i = 1; i <= NBrsEff(M); i++){
		if (Elmt(M, i, j) == X){
			count = count +1;
		}
	}
	
	return count;
}

