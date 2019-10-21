#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>

Kata CKata;
boolean EndKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK*/
  //  char CC;
    while (CC == BLANK){
        ADV();
    }
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : atau EndKata = false, CKata adalah kata yang sudah diakuisisi,          
          CC karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlank();
    EndKata = false;
    SalinKata();
}


void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  IgnoreBlank();
  SalinKata();
  IgnoreBlank();
}

void SalinKata(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    int hasil = 0;
    int CI = 0;
    
    while (CC != BLANK){
		if (CC == 'C' || CC == 'V' || CC == 'T' || CC == 'F'){
			CKata.bangunan = CC;
			CKata.val = -1;
			ADV();
		}
		else{
			CKata.bangunan = 'A';
			while (CC != BLANK){
				if (CC == '0'){
					CI = 0;
				}
				else if (CC == '1'){
					CI = 1;
				}
				else if (CC == '2'){
					CI = 2;
				}
				else if (CC == '3'){
					CI = 3;
				}
				else if (CC == '4'){
					CI = 4;
				}
				else if (CC == '5'){
					CI = 5;
				}
				else if (CC == '6'){
					CI = 6;
				}
				else if (CC == '7'){
					CI = 7;
				}
				else if (CC == '8'){
					CI = 8;
				}
				else if (CC == '9'){
					CI = 9;
				}
				hasil = (hasil*10) + CI;
				ADV();
			}
			CKata.val = hasil;
		}
		i++;
    }
}
