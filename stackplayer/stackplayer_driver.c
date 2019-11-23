#include <stdio.h>
#include "stackplayer.h"
#include "queue.h"
#include "../typebentukan/typebentukan.h"
#include "list.h"


void printBool(boolean X){
    if(X){
        printf("benar\n");
    }else{
        printf("salah\n");
    }
}

int main(){
    stackp S,SC;
    boolean stop = false;
    char code;
    int input;
    infotypestackp inp,X,out;
    CreateEmptystackp(&S);
    CreateEmptystackp(&SC);
    CreateEmptyQueue(&(inp.Skill),10);
    CreateEmptyList(&(inp.ListB));
    while(!stop){
        printf("Masukkan kode!\n");
        printf("A = Push\n");
        printf("D = Pop\n");
        printf("E = Cek Kosong\n");
        printf("F = Cek Full\n");
        printf("C = Copy\n");
        printf("X = Stop\n");
        printf(">> ");
        scanf(" %c", &code);
        if(code == 'A'){
            printf("Tambah elemen top nomor bangunan: \n");
            printf("Queue skill : ");
            scanf("%d", &input);
            AddQueue(&(inp.Skill),input);
            printf("List ListB : ");
            scanf("%d", &input);
            InsVLast(&(inp.ListB),input);
            printf("IsShield 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.IsShield = false;
            } else{
                inp.IsShield = true;
            }
            printf("IsAttackUp 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.IsAttackUp = false;
            } else{
                inp.IsAttackUp = true;
            }
            printf("IsCriticalHit 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.IsCriticalHit = false;
            } else{
                inp.IsCriticalHit = true;
            }
            printf("IsAttack 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.IsAttack = false;
            } else{
                inp.IsAttack = true;
            }
            printf("Askill 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.Askill = false;
            } else{
                inp.Askill = true;
            }
            printf("Aend 0/1: ");
            scanf("%d", &input);
            if(input == 0){
                inp.Aend = false;
            } else{
                inp.Aend = true;
            }
            Pushp(&S,inp);
        } else if(code == 'D') {
            Popp(&S,&X);
        } else if(code == 'F'){
            if(IsFullstackp(S)){
                printf("Stack penuh\n");
            } else{
                printf("Stack tak penuh\n");
            }
        } else if(code == 'E'){
            if(IsEmptystackp(S)){
                printf("Stack kosong\n");
            } else{
                printf("Stack tak kosong\n");
            }
        } else if(code == 'C'){
            CopyPlayer(InfoTop(S),&out);
            if(InfoTop(S) <= 0){
                printf("Stack Kosong cuy");
            } else{
                printf("Coppied!\n");
                printf("Head skill : %d Tail skill : %d\n",InfoHead(InfoTop(S).Skill), InfoTail(InfoTop(S).Skill));
                PrintInfo(InfoTop(S).ListB);
                printf("\n");
                printf("IsShield : ");
                printBool(InfoTop(S).IsShield);
                printf("IsAttackUp : ");
                printBool(InfoTop(S).IsAttackUp);
                printf("IsCriticalHit : ");
                printBool(InfoTop(S).IsCriticalHit);
                printf("IsAttack : ");
                printBool(InfoTop(S).IsAttack);
                printf("Askill : ");
                printBool(InfoTop(S).Askill);
                printf("Aend : ");
                printBool(InfoTop(S).Aend);
            }
        } else if(code == 'X'){
            stop = true;
        } else{
            printf("Masukkan salah, hehe...");
        }
    }
    printf("Stack : \n");
    while (Top(S) != Nilstackp){
        printf("Head skill : %d Tail skill : %d\n",InfoHead(InfoTop(S).Skill), InfoTail(InfoTop(S).Skill));
        PrintInfo(InfoTop(S).ListB);
        printf("\n");
        printf("IsShield : ");
        printBool(InfoTop(S).IsShield);
        printf("IsAttackUp : ");
        printBool(InfoTop(S).IsAttackUp);
        printf("IsCriticalHit : ");
        printBool(InfoTop(S).IsCriticalHit);
        printf("IsAttack : ");
        printBool(InfoTop(S).IsAttack);
        printf("Askill : ");
        printBool(InfoTop(S).Askill);
        printf("Aend : ");
        printBool(InfoTop(S).Aend);
        Popp(&S,&X);
    }
    return 0;
}