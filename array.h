/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "typebentukan.h"


/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef -888
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef Bangunan ElType;  /* type elemen tabel */

typedef struct
{
  ElType *TI; /* memori tempat penyimpan elemen (container) */
  int MaxElArr;  /* ukuran elemen */
} TabBang;

/* Indeks yang digunakan [IdxMin..MaxElArr] */
/* Jika T adalah TabBang, cara deklarasi dan akses: */
/* Deklarasi : T : TabBang */
/* Maka cara akses:
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
  sehingga T.TI[i] != ValUndef */

/* ********** SELEKTOR ********** */
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxElArr(T) (T).MaxElArr

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void CreateEmptyArray(TabBang *Arr, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void DealokasiArr(TabBang *Arr);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElArr(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr(TabBang T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
IdxType GetFirstIdx(TabBang T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabBang T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

#endif
