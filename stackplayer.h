/* File : stackpt.h */
/* deklarasi stackp yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackpt_H
#define stackpt_H

#include "boolean.h"
#include "array.h"

#define Nilstackp 0
#define MaxElstackp 100
/* Nilstackp adalah stackp dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef PLAYER infotypestackp;
typedef int addressstackp;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stackp dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  infotypestackp T[MaxElstackp+1]; /* tabel penyimpan elemen */
  addressstackp TOP;  /* alamat TOP: elemen puncak */
} stackp;
/* Definisi stackp S kosong : S.TOP = Nilstackp */
/* Elemen yang dipakai menyimpan nilai stackp T[1]..T[MaxElstackp] */
/* Jika S adalah stackp maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptystackp (stackp *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stackp S yang kosong berkapasitas MaxElstackp */
/* jadi indeksnya antara 1.. MaxElstackp+1 karena 0 tidak dipakai */
/* Ciri stackp kosong : TOP bernilai Nilstackp */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptystackp (stackp S);
/* Mengirim true jika stackp kosong: lihat definisi di atas */
boolean IsFullstackp (stackp S);
/* Mengirim true jika tabel penampung nilai elemen stackp penuh */

/* ************ Menambahkan sebuah elemen ke stackp ************ */
void Pushp (stackp * S, infotypestackp X);
/* Menambahkan X sebagai elemen stackp S. */
/* I.S. S mungkin kosong, tabel penampung elemen stackp TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen stackp ************ */
void Popp (stackp * S, infotypestackp* X);
/* Menghapus X dari stackp S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CopyPlayer (PLAYER Pin, PLAYER *Pout);


#endif