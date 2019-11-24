/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarl.h"
#include <stdio.h>

char CC;

static FILE * pita;
static int retval;

void STARTl() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
  //printf("Masukan nama file konfigurasi : ");
  //STARTWORD();
  //CWord.TabKata
	pita = fopen("SaveGame.txt","r");
	ADVl();
}

void ADVl() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
}

void CLOSEl(){
       fclose (pita);
}
