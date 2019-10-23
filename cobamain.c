#include "olahfile.h"
#include "typebentukan.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr; //Arr menyimpan tipe data bangunan
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L3; //List untuk kepemilikan bangunan
    PLAYER P1, P2; 
    boolean exit = false;


    LoadFile (&N, &M, &J, &Arr, &Mat, &P1.Bang, &P2.Bang);
 //   CreateEmptyQueue(&P1.Skill, 1);
 //   CreateEmptyQueue(&P2.Skill, 1);
 //   Add (&P1.Skill, 1);
 //  Add (&P2.Skill, 1);
    CetakPeta(N,M,Arr);
    DaftarBangunan(P1.Bang, Arr);
    printf("Ayo isi woy : ");
    STARTWORD();
    for (i = 1; i <= 10; i++){
        printf("%c", CWord.TabKata[i]);
    }

    
    return 0;
}