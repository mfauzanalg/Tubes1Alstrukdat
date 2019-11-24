/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATAl_H__
#define __MESINKATAl_H__

#include "../mesinkarl/mesinkarl.h"

#define NMaxl 50
#define BLANKl ' '
#define ENTERl 0x0A

typedef struct {
  char TabKatal[NMaxl+1];
  int Lengthl;
} Katal;

/* State Mesin Kata */
extern boolean EndKatal;
extern Katal CKatal;

void IgnoreBlankl();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATAl();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAl();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKatal();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int CharToIntl(char CC);
// Mengubah  Char ke Integer

void SalinLastl();

int StringToIntegerl(Katal CKata);
// Mengubah String ke Integer

#endif
