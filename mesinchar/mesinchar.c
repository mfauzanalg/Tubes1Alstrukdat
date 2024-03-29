/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinchar.h"
#include <stdio.h>

char CC;
boolean EOP;

static char *pita[10];
static int retval;

void STARTCHAR() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita

	/* Algoritma */
	ADVCHAR();
}

void ADVCHAR() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendla = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = scanf("%c",&CC);
}
