#include "mesinword.h"
#include <stdio.h>

Word CWord;
boolean EndWord;

void IgnoreBlankWord(){
/* Mengabaikan satu atau beberapa BLANK*/
    while ((CC == BLANK) || (CC == ENTER)){
        ADVCHAR();
    }
}

void STARTWORD(){
// untuk membaca input dari user dan memasukkannya ke Cword
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
//Input enter untuk melanjutkan game
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
// Membaca huruf satu persatu
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
// Menyambung per huruf menjadi suatu kata
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
// membuat cword kosong kembali
  int i;
  for (i = 0; i <= 10; i++){
    CWord.TabKata[i] = '\0';
  }
}

int WStringToInteger (Word CWord){
// mengubah string menjadi integer
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
// mengubah karakter menjadi integer
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

int StringLength(char *S){
// mengembalikan panjang string
  int i =0;
  int sum=0;
  char c = S[0];
  while (c != '\0'){
    sum += 1;
    i += 1;
    c = S[i];
  }
  return sum;
}

int CompareTwoStrings(char *S1, char *S2){
// compare 2 string apakah sama
  int i;
  if (StringLength(S1) != StringLength(S2)){
    return 0;
  }
  else{
    for (i = 1; i <= StringLength(S1); i++){
      if (S1[i] != S2[i]){
        return 0;
      }
    }
    return 1;
  }
}