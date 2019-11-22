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

void INPUTENTER(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,          
          CC karakter pertama sesudah karakter terakhir kata */
    STARTCHAR();

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
    int i = 0;
    MakeEmptyWord();
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

void MakeEmptyWord(){
  int i;
  for (i = 0; i <= 10; i++){
    CWord.TabKata[i] = '\0';
  }
}

int WStringToInteger (Word CWord){
	int i = 0;
	int hasil = 0;
	int CI = 0;

	for (i = 0; i <= CWord.Length-1; i++){
		CI = WCharToInt(CWord.TabKata[i]);
		hasil = (hasil*10) + CI;
	}
	return hasil;
}

int WCharToInt(char CC){
	if (CC == '0'){
		return 0;
	}
	else if (CC == '1'){
		return 1;
	}
	else if (CC == '2'){
		return 2;
	}
	else if (CC == '3'){
		return 3;
	}
	else if (CC == '4'){
		return 4;
	}
	else if (CC == '5'){
		return 5;
	}
	else if (CC == '6'){
		return 6;
	}
	else if (CC == '7'){
		return 7;
	}
	else if (CC == '8'){
		return 8;
	}
	else if (CC == '9'){
		return 9;
	}
}
