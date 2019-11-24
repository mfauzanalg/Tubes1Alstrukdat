#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../save/coba_save.h"
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
    int i;
	STARTKATA();
	*playing = IntegerToBoolean(StringToInteger(CKata));
	ADVKATA();
	*P1turn = IntegerToBoolean(StringToInteger(CKata));
	ADVKATA();
    InfoTop(*S).MaxElArr = StringToInteger(CKata);
    ADVKATA();
    for(i = 1; i <= InfoTop(*S).MaxElArr; i++){
        Elmt(InfoTop(*S),i).type = CC;
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
        ADVKATA();
    }
    CreateEmptyQueue(&(InfoTop(*P1).Skill),10);
    while(StringToInteger(CKata) != -999){
        AddQueue(&InfoTop(*P1).Skill,StringToInteger(CKata));
        ADVKATA();
    }
    CreateEmptyList(&InfoTop(*P1).ListB);
    while(StringToInteger(CKata) != -999){
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

// int main(){
//     // stackp SP1,SP2;
//     // Stack SBang;
//     boolean playing;
//     boolean P1turn;
//     load2(playing,P1turn);
//     if(playing){
//         printf("ya\n");
//     }else{
//         printf("tidak\n");
//     }
//     if(P1turn){
//         printf("ya\n");
//     }else{
//         printf("tidak\n");
//     }
    
//     // save2(playing,P1turn);
//     return 0;
// }

// int main () {
//    char str1[10], str2[10], str3[10];
//    int year,yes;
//    FILE * fp;

//    fp = fopen ("coba.txt", "w+");

//    fscanf(fp, "%d", &year);
//    yes = year+7;
//     printf("Read Integer |%d|\n", year );
//    printf("Read Integer |%d|\n", yes );

//    fclose(fp);
   
//    return(0);
// }