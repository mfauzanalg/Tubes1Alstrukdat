#include "stack.h"
#include <stdio.h>
#include "typebentukan.h"
#include "array.h"
#include "point.h"

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
        printf("I = Inverse\n");
        printf("C = Copy\n");
        printf("V = FPush\n");
        printf("X = Stop\n");
        printf(">> ");
        scanf(" %c", &code);
        if(code == 'A'){
            printf("Tambah elemen top nomor bangunan: \n");
            printf("Masukkan max elmt TabBang : ");
            scanf("%d", &input);
            inp.MaxElArr = input;
            printf("Masukkaan array of Bangunan : \n");
            printf("Masukkaan ada berapa elemen of bangunan yang mau ditempatkan ke array : ");
            scanf("%d", &N);
            for(i = 1; i <= N; i++){
                printf("Masukkan no bangunan : ");
                scanf("%d", &input);
                Elmt(inp,i).nomor = input;
                printf("Masukkan type bangunan : ");
                scanf(" %c", &inputchar);
                Elmt(inp,i).nomor = inputchar;
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
            Push(&S,inp);
        } else if(code == 'D') {
            Pop(&S,&X);
        } else if(code == 'F'){
            if(IsFullStack(S)){
                printf("Stack penuh\n");
            } else{
                printf("Stack tak penuh\n");
            }
        } else if(code == 'E'){
            if(IsEmptyStack(S)){
                printf("Stack kosong\n");
            } else{
                printf("Stack tak kosong\n");
            }
        } else if(code == 'I'){
            SI = InverseStack(S);
            printf("Success to Inverse!\n");
            printf("Stack Inverse: \n");
            while (Top(SI) != NilStack){
                for(i = 1; i <= N; i++){
                    printf("No Bangunan : %d\n", Elmt(InfoTop(SI),i).nomor);
                    printf("Type Bangunan : %c\n", Elmt(InfoTop(SI),i).type);
                    printf("Jum Bangunan : %d\n", Elmt(InfoTop(SI),i).jum);
                    printf("Lev Bangunan : %d\n", Elmt(InfoTop(SI),i).lev);
                    printf("A Bangunan : %d\n", Elmt(InfoTop(SI),i).A);
                    printf("M Bangunan : %d\n", Elmt(InfoTop(SI),i).M);
                    printf("P Bangunan : ");
                    printBool(Elmt(InfoTop(SI),i).P);
                    printf("U Bangunan : %d\n", Elmt(InfoTop(SI),i).U);
                    printf("P Bangunan (x,y) : (%d,%d)\n ", Elmt(InfoTop(SI),i).letak.X,Elmt(InfoTop(SI),i).letak.Y);
                    printf("Attack Bangunan : ");
                    printBool(Elmt(InfoTop(SI),i).attack);
                    printf("Move Bangunan : ");
                    printBool(Elmt(InfoTop(SI),i).move);
                }
                Pop(&SI,&X);
            }
        } else if(code == 'C'){
            SC = CopyStack(S);
            printf("Coppied!\n");
            printf("Stack Copy: \n");
            while (Top(SC) != NilStack){
                for(i = 1; i <= N; i++){
                    printf("No Bangunan : %d\n", Elmt(InfoTop(SC),i).nomor);
                    printf("Type Bangunan : %c\n", Elmt(InfoTop(SC),i).type);
                    printf("Jum Bangunan : %d\n", Elmt(InfoTop(SC),i).jum);
                    printf("Lev Bangunan : %d\n", Elmt(InfoTop(SC),i).lev);
                    printf("A Bangunan : %d\n", Elmt(InfoTop(SC),i).A);
                    printf("M Bangunan : %d\n", Elmt(InfoTop(SC),i).M);
                    printf("P Bangunan : ");
                    printBool(Elmt(InfoTop(SC),i).P);
                    printf("U Bangunan : %d\n", Elmt(InfoTop(SC),i).U);
                    printf("P Bangunan (x,y) : (%d,%d)\n ", Elmt(InfoTop(SC),i).letak.X,Elmt(InfoTop(SC),i).letak.Y);
                    printf("Attack Bangunan : ");
                    printBool(Elmt(InfoTop(SC),i).attack);
                    printf("Move Bangunan : ");
                    printBool(Elmt(InfoTop(SC),i).move);
                }
                Pop(&SC,&X);
            }
        } else if(code == 'V'){
            printf("Masukkan input X FPush : \n");
            printf("Masukkan max elmt TabBang : ");
            scanf("%d", &input);
            inpfpush.MaxElArr = input;
            printf("Masukkaan array of Bangunan : \n");
            printf("Masukkaan ada berapa elemen of bangunan yang mau ditempatkan ke array : ");
            scanf("%d", &N);
            for(i = 1; i <= N; i++){
                printf("Masukkan no bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).nomor = input;
                printf("Masukkan type bangunan : ");
                scanf(" %c", &inputchar);
                Elmt(inpfpush,i).nomor = inputchar;
                printf("Masukkan jum bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).jum = input;
                printf("Masukkan lev bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).lev = input;
                printf("Masukkan A bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).A = input;
                printf("Masukkan M bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).M = input;
                printf("Masukkan P bangunan 0/1: ");
                scanf("%d", &input);
                if(input == 0){
                    Elmt(inpfpush,i).P = false;
                } else{
                    Elmt(inpfpush,i).P = true;
                }
                printf("Masukkan U bangunan : ");
                scanf("%d", &input);
                Elmt(inpfpush,i).U = input;
                printf("Masukkan letak bangunan x: ");
                scanf("%d", &input);
                Elmt(inpfpush,i).letak.X = input;
                printf("Masukkan letak bangunan y: ");
                scanf("%d", &input);
                Elmt(inpfpush,i).letak.Y = input;
                printf("Masukkan attack bangunan 0/1: ");
                scanf("%d", &input);
                if(input == 0){
                    Elmt(inpfpush,i).attack = false;
                } else{
                    Elmt(inpfpush,i).attack = true;
                }
                printf("Masukkan move bangunan 0/1: ");
                scanf("%d", &input);
                if(input == 0){
                    Elmt(inpfpush,i).move = false;
                } else{
                    Elmt(inpfpush,i).move = true;
                }
            }
            SV = FPush(S,inpfpush);
        } else if(code == 'X'){
            stop = true;
        } else{
            printf("Masukkan salah, hehe...\n");
        }
    }
    printf("Stack : \n");
    while (Top(S) > NilStack){
        for(i = 1; i <= N; i++){
            printf("No Bangunan : %d\n", Elmt(InfoTop(S),i).nomor);
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

    printf("Stack FPush : \n");
    while (Top(SV) != NilStack){
        for(i = 1; i <= N; i++){
            printf("No Bangunan : %d\n", Elmt(InfoTop(SV),i).nomor);
            printf("Type Bangunan : %c\n", Elmt(InfoTop(SV),i).type);
            printf("Jum Bangunan : %d\n", Elmt(InfoTop(SV),i).jum);
            printf("Lev Bangunan : %d\n", Elmt(InfoTop(SV),i).lev);
            printf("A Bangunan : %d\n", Elmt(InfoTop(SV),i).A);
            printf("M Bangunan : %d\n", Elmt(InfoTop(SV),i).M);
            printf("P Bangunan : ");
            printBool(Elmt(InfoTop(SV),i).P);
            printf("U Bangunan : %d\n", Elmt(InfoTop(SV),i).U);
            printf("P Bangunan (x,y) : (%d,%d)\n ", Elmt(InfoTop(SV),i).letak.X,Elmt(InfoTop(SV),i).letak.Y);
            printf("Attack Bangunan : ");
            printBool(Elmt(InfoTop(SV),i).attack);
            printf("Move Bangunan : ");
            printBool(Elmt(InfoTop(SV),i).move);
        }
        Pop(&SV,&X);
    }
    return 0;
}