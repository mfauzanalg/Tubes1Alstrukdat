#include "save.h"
#include "../stack/stack.h"
#include "../stackplayer/stackplayer.h"

//to run use :gcc -o save save_driver.c save.c ../queue/queue.c ../list/list.c ../stack/stack.c ../stackplayer/stackplayer.c ../array/array.c

int main(){
    Stack S;
    stackp SP1,SP2;
    boolean playing,P1turn;
    char inputchar;
    infotypestack inp;
    infotypestackp inp1,inp2;
    int input,N,i;
    i=0;
    CreateEmptyStack(&S);
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyQueue(&(inp1.Skill),10);
    CreateEmptyList(&(inp1.ListB));
    CreateEmptyQueue(&(inp2.Skill),10);
    CreateEmptyList(&(inp2.ListB));

    printf("Save data inputanmu!\n");
    printf("Stack:\n");

    //Stack
    printf("Tambah elemen top bangunan: \n");
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

    //Stackp 1
    printf("Stackp1 : \n");
    printf("Tambah elemen top nomor bangunan: \n");
    printf("Queue skill : ");
    scanf("%d", &input);
    AddQueue(&(inp1.Skill),input);
    printf("List ListB : ");
    scanf("%d", &input);
    InsVLast(&(inp1.ListB),input);
    printf("IsShield 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.IsShield = false;
    } else{
        inp1.IsShield = true;
    }
    printf("IsAttackUp 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.IsAttackUp = false;
    } else{
        inp1.IsAttackUp = true;
    }
    printf("IsCriticalHit 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.IsCriticalHit = false;
    } else{
        inp1.IsCriticalHit = true;
    }
    printf("IsAttack 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.IsAttack = false;
    } else{
        inp1.IsAttack = true;
    }
    printf("Askill 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.Askill = false;
    } else{
        inp1.Askill = true;
    }
    printf("Aend 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp1.Aend = false;
    } else{
        inp1.Aend = true;
    }
    Pushp(&SP1,inp1);


    //Stackp 2
    printf("Tambah elemen top nomor bangunan: \n");
    printf("Queue skill : ");
    scanf("%d", &input);
    AddQueue(&(inp2.Skill),input);
    printf("List ListB : ");
    scanf("%d", &input);
    InsVLast(&(inp2.ListB),input);
    printf("IsShield 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.IsShield = false;
    } else{
        inp2.IsShield = true;
    }
    printf("IsAttackUp 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.IsAttackUp = false;
    } else{
        inp2.IsAttackUp = true;
    }
    printf("IsCriticalHit 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.IsCriticalHit = false;
    } else{
        inp2.IsCriticalHit = true;
    }
    printf("IsAttack 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.IsAttack = false;
    } else{
        inp2.IsAttack = true;
    }
    printf("Askill 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.Askill = false;
    } else{
        inp2.Askill = true;
    }
    printf("Aend 0/1: ");
    scanf("%d", &input);
    if(input == 0){
        inp2.Aend = false;
    } else{
        inp2.Aend = true;
    }
    Pushp(&SP2,inp2);

    printf("Masukkan boolean playing 0/1 : \n");
    scanf("%d", &input);
    if(input == 0){
        playing = false;
    } else{
        playing = true;
    }
    printf("Masukkan boolean P1 0/1 : \n");
    scanf("%d", &input);
    if(input == 0){
        P1turn = false;
    } else{
        P1turn = true;
    }

    SaveAll(S,SP1,SP2,playing,P1turn);
    printf("Selamat! File sudah tersimpan...\n");

}