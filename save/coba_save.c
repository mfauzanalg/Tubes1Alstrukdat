#include <stdio.h>
#include "coba_save.h"

int BooleanToInteger(boolean x){
    int out;
    if(x){
        return 1;
    } else{
        return 0;
    }
}

boolean IntegerToBoolean(int x){
    boolean out;
    if(x == 0){
        return false;
    } else{
        return true;
    }
}

void SaveAll(Stack S, stackp P1, stackp P2, boolean playing, boolean P1turn){
    FILE *fp;
    //open
    fp = fopen("coba_save.txt", "w");

    char c;
    int i,j,k;
    int awal1,awal2,akhir1,akhir2;
    addresslist L;
    infotypestack X;
    infotypestackp Xp;
    fprintf(fp,"%d\n", BooleanToInteger(playing));
    fprintf(fp,"%d\n", BooleanToInteger(P1turn));
    // while(Top(S) > NilStack){
        fprintf(fp,"%d\n", InfoTop(S).MaxElArr);
        for(i = 1; i <= InfoTop(S).MaxElArr; i++){
            fprintf(fp,"%c\n", Elmt(InfoTop(S),i).type);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).jum);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).lev);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).A);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).M);
            fprintf(fp,"%d\n", BooleanToInteger(Elmt(InfoTop(S),i).P));
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).U);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).letak.X);
            fprintf(fp,"%d\n", Elmt(InfoTop(S),i).letak.Y);
            fprintf(fp,"%d\n", BooleanToInteger(Elmt(InfoTop(S),i).attack));
            fprintf(fp,"%d\n", BooleanToInteger(Elmt(InfoTop(S),i).move));
        }
        // Pop(&S,&X);
    // }
    // while (Top(P) > Nilstackp){
        awal1 = InfoTop(P1).Skill.HEAD;
        akhir1 = InfoTop(P1).Skill.TAIL;
        if(IsEmptyQueue(InfoTop(P1).Skill)){
            fprintf(fp,"%d\n", 0);
        } else{
            for(j = awal1; j <= akhir1; j++){
                fprintf(fp,"%d\n", InfoTop(P1).Skill.T[j]);
            }
        }
        L = InfoTop(P1).ListB.First;
        while(L != NilList){
            fprintf(fp,"%d\n", Info(L));
            L = Next(L);
        }
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).IsShield));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).IsAttackUp));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).IsCriticalHit));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).IsAttack));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).Askill));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).Aend));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P1).IsET));
        fprintf(fp,"%d\n", InfoTop(P1).CountShield);
        // Popp(&P,&Xp);
    // }

        awal2 = InfoTop(P2).Skill.HEAD;
        akhir2 = InfoTop(P2).Skill.TAIL;
        if(IsEmptyQueue(InfoTop(P2).Skill)){
            fprintf(fp,"%d\n", 0);
        } else{
            for(k = awal2; k <= akhir2; k++){
                fprintf(fp,"%d\n", InfoTop(P2).Skill.T[k]);
            }
        }
        L = InfoTop(P2).ListB.First;
        while(L != NilList){
            fprintf(fp,"%d\n", Info(L));
            L = Next(L);
        }
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).IsShield));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).IsAttackUp));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).IsCriticalHit));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).IsAttack));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).Askill));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).Aend));
        fprintf(fp,"%d\n", BooleanToInteger(InfoTop(P2).IsET));
        fprintf(fp,"%d\n", InfoTop(P2).CountShield);
    //close
    fclose(fp);
}