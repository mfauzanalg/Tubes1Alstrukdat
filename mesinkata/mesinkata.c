#include "mesinkata.h"
#include <stdio.h>

Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK ENTER dan \r*/
    while (CC == BLANK || CC == ENTER || CC == '\r'){
        ADV();
    }
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : atau EndKata = false, CKata adalah kata yang sudah diakuisisi,          
          CC karakter pertama sesudah karakter terakhir kata */
    START();
    SalinKata();
}


void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  IgnoreBlank();
  SalinKata();
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = ENTER atau /r;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.*/
    int i = 1;
    CKata.Length = 0;
    while (CC != ENTER && CC != BLANK && CC != '\r'){
        CKata.TabKata[i] = CC;
        CKata.Length++;
        i++;
        ADV();
    }
	IgnoreBlank();
}

void SalinLast(){
// Seperti Salin kata tetapi untuk character terakhir
    IgnoreBlank();
	if (CC == '0'){
		CKata.TabKata[1] = 0;
	}
	else{
		CKata.TabKata[1] = 1;
	}
}

int StringToInteger (Kata CKata){
// Mengubah String ke Integer
	int i;
	int hasil = 0;
	int CI;
	for (i = 1; i <= CKata.Length; i++){
		CI = CharToInt(CKata.TabKata[i]);
		hasil = (hasil*10) + CI;
	}
	return hasil;
}

int CharToInt(char CC){
// Mengubah character ke integer
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
	else{
		return 9;
	}
}
