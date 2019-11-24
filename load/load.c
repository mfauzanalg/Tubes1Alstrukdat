#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../save/save.h"
#include "../boolean/boolean.h"

boolean IntegerToBoolean(int x){
    boolean out;
    if(x == 0){
        return false;
    } else{
        return true;
    }
}

// void load2(boolean playing, boolean P1turn){
//     FILE *fp;

//     fp = fopen("coba.txt","r+");
//     int i,temp1,temp2;
//     fscanf(fp, "%d", &temp1);
//     playing = IntegerToBoolean(temp1);
//     fscanf(fp, "%d", &temp2);
//     P1turn = IntegerToBoolean(temp2);

//     fclose(fp);
// }

// void save2(boolean playing, boolean P1turn);
/*{
    FILE *fp;

    fp = fopen("out.txt","w+");
    fprintf(fp,"%d\n", BooleanToInteger(playing));
    fprintf(fp,"%d\n", BooleanToInteger(P1turn));

    fclose(fp);
}
*/

void load (Stack *S, stackp *P1, stackp *P2, boolean *playing, boolean *P1turn){
    int i,maxel;
    static FILE * pita;
    static int retval;
    // FILE *fp;
    
    // fp = fopen("coba_save.txt","r");
	pita = fopen("coba_save.txt","r");
    
	STARTKATA();
    ADVKATA();
    
    SalinKata();
    
	*playing = IntegerToBoolean(StringToInteger(CKata));
	ADVKATA();
    
	*P1turn = IntegerToBoolean(StringToInteger(CKata));
	ADVKATA();
    
    CreateEmptyStack(&(*S));
    CreateEmptystackp(&(*P1));
    CreateEmptystackp(&(*P2));
    
    InfoTop(*S).MaxElArr = StringToInteger(CKata);
    
    
    maxel = InfoTop(*S).MaxElArr;
    CreateEmptyArray(&InfoTop(*S),maxel);
    
    for(i = 1; i <= maxel; i++){
        ADVKATA();
        if(CKata.TabKata[1] == 'C'){
            Elmt(InfoTop(*S),i).type = 'C';
        } else if(CKata.TabKata[1] == 'T'){
            Elmt(InfoTop(*S),i).type = 'T';
        } else if(CKata.TabKata[1] == 'V'){
            Elmt(InfoTop(*S),i).type = 'V';
        } else if(CKata.TabKata[1] == 'F'){
            Elmt(InfoTop(*S),i).type = 'F';
        }

        
        ADVKATA();
        
        Elmt(InfoTop(*S),i).jum = StringToInteger(CKata);
        
        ADVKATA();
        Elmt(InfoTop(*S),i).lev = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).A = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).M = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).P = IntegerToBoolean(StringToInteger(CKata));
        ADVKATA();
        Elmt(InfoTop(*S),i).U = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).letak.X = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).letak.Y = StringToInteger(CKata);
        ADVKATA();
        Elmt(InfoTop(*S),i).attack = IntegerToBoolean(StringToInteger(CKata));
        ADVKATA();
        Elmt(InfoTop(*S),i).move = IntegerToBoolean(StringToInteger(CKata));
        // ADVKATA();
        
    }
    ADVKATA();
    CreateEmptyQueue(&(InfoTop(*P1).Skill),10);
    while(CKata.TabKata[1] != 'X'){
        AddQueue(&InfoTop(*P1).Skill,StringToInteger(CKata));
        ADVKATA();
        
    }
    
    CreateEmptyList(&InfoTop(*P1).ListB);
    while(CKata.TabKata[1] != 'X'){
        InsVLast(&InfoTop(*P1).ListB,StringToInteger(CKata));
        ADVKATA();
    }
    
    InfoTop(*P1).IsShield = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).IsAttackUp = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).IsCriticalHit = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).IsAttack = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).Askill = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).Aend = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).IsET = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P1).IsShield = StringToInteger(CKata);
    ADVKATA();

    CreateEmptyQueue(&(InfoTop(*P2).Skill),10);
    while(StringToInteger(CKata) != -999){
        AddQueue(&InfoTop(*P2).Skill,StringToInteger(CKata));
        ADVKATA();
    }
    CreateEmptyList(&InfoTop(*P2).ListB);
    while(StringToInteger(CKata) != -999){
        InsVLast(&InfoTop(*P2).ListB,StringToInteger(CKata));
        ADVKATA();
    }
    InfoTop(*P2).IsShield = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).IsAttackUp = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).IsCriticalHit = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).IsAttack = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).Askill = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).Aend = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).IsET = IntegerToBoolean(StringToInteger(CKata));
    ADVKATA();
    InfoTop(*P2).IsShield = StringToInteger(CKata);
    CLOSE();
}