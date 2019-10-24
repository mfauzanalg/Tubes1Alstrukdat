#include "olahfile.h"
#include "typebentukan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr; //Arr menyimpan tipe data bangunan
    TabGraph ArrGraph; //Arr menyimpan graf
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L3; //List untuk kepemilikan bangunan
    PLAYER P1, P2; 
    boolean exit = false;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.Bang, &P2.Bang);
    CreateEmptyQueue(&P1.Skill, 10);
    CreateEmptyQueue(&P2.Skill, 10);

    //input.Kata[1] = 'I';
    //input.Kata[2] = 'U';
    //AddQueue (&P1.Skill, input);
    //AddQueue (&P2.Skill, input);

    CetakPeta(N,M,Arr);
    DaftarBangunan(P1.Bang, Arr);
    printf("Ayo isi woy : ");

    STARTWORD();
    for (i = 0; i <= 10; i++){
        printf("%c",CWord.TabKata[i]);
    }    
    if (strcmp(CWord.TabKata, "Lia") == 0) {
        printf("uyey sama\n");
    }

    STARTWORD();
    for (i = 0; i <= 10; i++){
        printf("%c",CWord.TabKata[i]);
    }    
    if (strcmp(CWord.TabKata, "Fauzan") == 0) {
        printf("uyey sama lagi\n");
    }

    STARTWORD();
    for (i = 0; i <= 10; i++){
        printf("%c",CWord.TabKata[i]);
    }    
    if (strcmp(CWord.TabKata, "Lia") == 0) {
        printf("uyey sama lagi lagi\n");
    }
    
    return 0;
}