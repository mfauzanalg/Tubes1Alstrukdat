#include "stack.h"
#include <stdio.h>
#include "../typebentukan/typebentukan.h"
#include "../array/array.h"
#include "../point/point.h"
#include "../boolean/boolean.h"

void printBool(boolean X){
    if(X){
        printf("benar\n");
    }else{
        printf("salah\n");
    }
}

int main(){
    Stack S,SI,SC,SV;
    boolean stop = false;
    char code,inputchar;
    infotypestack inp,X,inpfpush;
    int input,N,i;
    i=0;
    CreateEmptyStack(&S);
    CreateEmptyStack(&SI);
    CreateEmptyStack(&SC);
    CreateEmptyStack(&SV);
    while(!stop){
        printf("Masukkan kode!\n");
        printf("A = Push\n");
        printf("D = Pop\n");
        printf("E = Cek Kosong\n");
        printf("F = Cek Full\n");
        printf("X = Stop\n");
        printf(">> ");
        scanf(" %c", &code);
        if(code == 'A'){
            printf("Tambah elemen top nomor bangunan: \n");
            printf("Masukkan max elmt TabBang : ");
            scanf("%d", &input);
            inp.MaxElArr = input;
            CreateEmptyArray(&inp,inp.MaxElArr);
            printf("Masukkaan array of Bangunan : \n");
            printf("Masukkaan ada berapa elemen of bangunan yang mau ditempatkan ke array : ");
            scanf("%d", &N);
            if(N <= inp.MaxElArr){
                for(i = 1; i <= N; i++){
                    printf("\nMasukkan type bangunan : ");
                    scanf(" %c", &inputchar);
                    Elmt(inp,i).type = inputchar;
                    printf("Masukkan jum bangunan : ");
                    scanf("%d", &input);
                    Elmt(inp,i).jum = input;
                    printf("Masukkan lev bangunan : ");
                    scanf("%d", &input);
                    Elmt(inp,i).lev = input;
                    printf("Masukkan A bangunan : ");
                    scanf("%d", &input);
                    Elmt(inp,i).A = input;
                    printf("Masukkan M bangunan : ");
                    scanf("%d", &input);
                    Elmt(inp,i).M = input;
                    printf("Masukkan P bangunan 0/1: ");
                    scanf("%d", &input);
                    if(input == 0){
                        Elmt(inp,i).P = false;
                    } else{
                        Elmt(inp,i).P = true;
                    }
                    printf("Masukkan U bangunan : ");
                    scanf("%d", &input);
                    Elmt(inp,i).U = input;
                    printf("Masukkan letak bangunan x: ");
                    scanf("%d", &input);
                    Elmt(inp,i).letak.X = input;
                    printf("Masukkan letak bangunan y: ");
                    scanf("%d", &input);
                    Elmt(inp,i).letak.Y = input;
                    printf("Masukkan attack bangunan 0/1: ");
                    scanf("%d", &input);
                    if(input == 0){
                        Elmt(inp,i).attack = false;
                    } else{
                        Elmt(inp,i).attack = true;
                    }
                    printf("Masukkan move bangunan 0/1: ");
                    scanf("%d", &input);
                    if(input == 0){
                        Elmt(inp,i).move = false;
                    } else{
                        Elmt(inp,i).move = true;
                    }
                }
            }
            Push(&S,inp);
        } else if(code == 'D') {
            Pop(&S,&X);
        } else if(code == 'F'){
            if(IsFullStack(S)){
                printf("Stack penuh\n\n");
            } else{
                printf("Stack tak penuh\n\n");
            }
        } else if(code == 'E'){
            if(IsEmptyStack(S)){
                printf("Stack kosong\n\n");
            } else{
                printf("Stack tak kosong\n\n");
            }
        }  
        else if(code == 'X'){
            stop = true;
        } else{
            printf("Masukkan salah, hehe...\n");
        }
    }
    printf("Stack : \n");
    while (Top(S) > NilStack){
        for(i = 1; i <= N; i++){
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
        Pop(&S,&X);
    }
    return 0;
}