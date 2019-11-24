/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;

static FILE * pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita

/* Algoritma */
  //printf("Masukan nama file konfigurasi : ");
  //STARTWORD();
  //CWord.TabKata
	pita = fopen("pitakar.txt","r");
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
}

void CLOSE(){
// menutup file
       fclose (pita);
}
