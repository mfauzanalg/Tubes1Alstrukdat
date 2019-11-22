#include <stdio.h>
#include "queue.h"

int main(){
    int N;
    boolean stop;
    char code;
    infotypequeue inp,X;
    Queue Q;
    stop = false;
    printf("Masukkan panjang Queue maks : ");
    scanf("%d", &N);
    CreateEmptyQueue(&Q,N);
    while(!stop){
        printf("Masukkan kode!\n");
        printf("A = Add\n");
        printf("D = Del\n");
        printf("E = Cek Kosong\n");
        printf("F = Cek Full\n");
        printf("N = Cek Banyak Elemen Queue\n");
        printf("X = Stop\n");
        printf(">> ");
        scanf(" %c", &code);
        if(code == 'A'){
            printf("Tambah elemen : ");
            scanf("%d", &inp);
            AddQueue(&Q,inp);
        } else if(code == 'D') {
            Del(&Q,&X);
        } else if(code == 'F'){
            if(IsFullQueue(Q)){
                printf("Queue penuh\n");
            } else{
                printf("Queue tak penuh\n");
            }
        } else if(code == 'E'){
            if(IsEmptyQueue(Q)){
                printf("Queue kosong\n");
            } else{
                printf("Queue tak kosong\n");
            }
        } else if(code == 'N'){
            printf("Panjang queue : %d\n", NBElmtQueue(Q));
        } else if(code == 'X'){
            stop = true;
        } else{
            printf("Masukkan salah, hehe...");
        }
        printf("Head : %d\n", InfoHead(Q));
        printf("Tail : %d\n", InfoTail(Q));
    }
    return 0;
}