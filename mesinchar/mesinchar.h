/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"

#define MARK 0x0A
/* State Mesin */
extern char CC;
extern boolean EOP;

void STARTCHAR();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita*/

void ADVCHAR();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama */

#endif
