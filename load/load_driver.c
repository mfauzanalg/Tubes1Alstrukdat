#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../save/save.h"
#include "../boolean/boolean.h"
#include "../stack/stack.h"
#include "../stackplayer/stackplayer.h"
//#include "../boolean/boolean.h"
#include "../list/list.h"
#include "../array/array.h"

// to run:  gcc -o load load/load_driver.c array/array.c list/list.c queue/queue.c stack/stack.c stackplayer/stackplayer.c load/load.c mesinkatal/mesinkatal.c mesinkarl/mesinkarl.c

void printBool(boolean X){
    if(X){
        printf("benar\n");
    }else{
        printf("salah\n");
    }
}

int main()
{
    Stack S;
    stackp P1, P2;
    boolean playing, P1turn;
    int i,N;

    CreateEmptyStack(&S);
    CreateEmptystackp(&P1);
    CreateEmptystackp(&P2);

    load(&S, &P1, &P2, &playing, &P1turn);
    //printf("%d\n", S.T[1].TI[1]);
    printf("%d\n", playing);
    printf("%d\n", P1turn);
    N = 17;
 
 /*   for(i = 1; i <= N; i++){
        printf("%d\n\n", i);
        printf("Type Bangunan : %c\n", Elmt(InfoTop(S),i).type);
        printf("Jum Bangunan : %d\n", Elmt(InfoTop(S),i).jum);
        printf("Lev Bangunan : %d\n", Elmt(InfoTop(S),i).lev);
        printf("A Bangunan : %d\n", Elmt(InfoTop(S),i).A);
        printf("M Bangunan : %d\n", Elmt(InfoTop(S),i).M);
        printf("P Bangunan : ");
        printBool(Elmt(InfoTop(S),i).P);
        printf("U Bangunan : %d\n", Elmt(InfoTop(S),i).U);
        printf("P Bangunan (x,y) : (%d,%d)\n ", Elmt(InfoTop(S),i).letak.X,Elmt(InfoTop(S),i).letak.Y);
        printf("Attack Bangunan : ");
        printBool(Elmt(InfoTop(S),i).attack);
        printf("Move Bangunan : ");
        printBool(Elmt(InfoTop(S),i).move);
    }
*/
    // printf("Head skill : %d Tail skill : %d\n",InfoHead(InfoTop(S).Skill), InfoTail(InfoTop(P1).Skill));
    PrintInfo(InfoTop(P1).ListB);
    printf("\n");
    printf("IsShield : ");
    printBool(InfoTop(P1).IsShield);
    printf("IsAttackUp : ");
    printBool(InfoTop(P1).IsAttackUp);
    printf("IsCriticalHit : ");
    printBool(InfoTop(P1).IsCriticalHit);
    printf("IsAttack : ");
    printBool(InfoTop(P1).IsAttack);
    printf("Askill : ");
    printBool(InfoTop(P1).Askill);
    printf("Aend : ");
    printBool(InfoTop(P1).Aend);

    // printf("Head skill : %d Tail skill : %d\n",InfoHead(InfoTop(P2).Skill), InfoTail(InfoTop(S).Skill));
    PrintInfo(InfoTop(P2).ListB);
    printf("\n");
    printf("IsShield : ");
    printBool(InfoTop(P2).IsShield);
    printf("IsAttackUp : ");
    printBool(InfoTop(P2).IsAttackUp);
    printf("IsCriticalHit : ");
    printBool(InfoTop(P2).IsCriticalHit);
    printf("IsAttack : ");
    printBool(InfoTop(P2).IsAttack);
    printf("Askill : ");
    printBool(InfoTop(P2).Askill);
    printf("Aend : ");
    printBool(InfoTop(P2).Aend);

    return 0;
}