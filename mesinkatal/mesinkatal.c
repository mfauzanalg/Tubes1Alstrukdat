#include "mesinkatal.h"
#include <stdio.h>

Katal CKatal;

void IgnoreBlankl(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK*/
  //  char CC;
    while (CC == BLANKl || CC == ENTERl || CC == '\r'){
        ADVl();
    }
}

void STARTKATAl(){
/* I.S. : CC sembarang
   F.S. : atau EndKata = false, CKata adalah kata yang sudah diakuisisi,          
          CC karakter pertama sesudah karakter terakhir kata */
    STARTl();
    SalinKatal();
}


void ADVKATAl(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  IgnoreBlankl();
  SalinKatal();
}

void SalinKatal(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 1;
    CKatal.Lengthl = 0;
    while (CC != ENTERl && CC != BLANKl && CC != '\r'){
        CKatal.TabKatal[i] = CC;
        CKatal.Lengthl++;
        i++;
        ADVl();
    }
	IgnoreBlankl();
}

void SalinLastl(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    IgnoreBlankl();
	if (CC == '0'){
		CKatal.TabKatal[1] = 0;
	}
	else{
		CKatal.TabKatal[1] = 1;
	}
}

int StringToIntegerl (Katal CKatal){
	int i;
	int hasil = 0;
	int CI;
	for (i = 1; i <= CKatal.Lengthl; i++){
		CI = CharToIntl(CKatal.TabKatal[i]);
		hasil = (hasil*10) + CI;
	}
	return hasil;
}

int CharToIntl(char CC){
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
