// Nama  : Muhammad Fauzan Al-Ghifari
// NIM   : 13518112
// Topik : Mesin kata
// Tanggal : 21 Septemer 2019

#include "mesinword.h"
#include "mesinchar.h"
#include <stdio.h>

Word CWord;
boolean EndWord;

void IgnoreBlankWord(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
  //  char CC;
    while ((CC == BLANK) || (CC == ENTER)){
        ADVCHAR();
    }
}

void STARTWORD(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,          
          CC karakter pertama sesudah karakter terakhir kata */
    STARTCHAR();
    IgnoreBlankWord();

    if (CC == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        SalinWord();
    }   
}

void ADVWORD(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  IgnoreBlankWord();
  if (CC == MARK){
    EndWord = true;
  }
  else{
    SalinWord();
    IgnoreBlankWord();
  }
}

void SalinWord(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 1;
    CWord.Length = 0;
    while (CC != MARK && CC != BLANK){
        if (i <= NMax){
            CWord.TabKata[i] = CC;
            CWord.Length++;
            i++;
        }
        ADVCHAR();
    }
}
