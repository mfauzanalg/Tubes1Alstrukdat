/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINWORD_H__
#define __MESINWORD_H__

#include "../boolean/boolean.h"
#include "../mesinchar/mesinchar.h"

#define NMax 50
#define BLANK ' '
#define ENTER 0x0A
#define clear printf("\033[H\033[J")

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Word;

/* State Mesin Kata */
extern boolean EndKata;
extern Word CWord;

void IgnoreBlankWord();
/* Mengabaikan satu atau beberapa BLANK*/

void STARTWORD();
// untuk membaca input dari user dan memasukkannya ke Cword


void INPUTENTER();
//Input enter untuk melanjutkan game

void ADVWORD();
// Membaca huruf satu persatu


void SalinWord();
// Menyambung per huruf menjadi suatu kata

void MakeEmptyWord();
// Membuat Cword menjadi kosong kembali

int WStringToInteger (Word CWord);
// mengubah string menjadi integer

int WCharToInt(char CC);
// mengubah char ke integer

int StringLength(char *S);
// membaca panjang string

int CompareTwoStrings(char *S1, char *S2);
// compare 2 string apakah sama

#endif
