#include "olahfile.h"
#include "typebentukan.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr; //Arr menyimpan tipe data bangunan
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L3; //List untuk kepemilikan bangunan
    PLAYER P1, P2; 


    LoadFile (&N, &M, &J, &Arr, &Mat, &P1.Bang, &P2.Bang, &L3);
    CreateEmptyQueue(&P1.Skill, 1);
    CreateEmptyQueue(&P2.Skill, 1);
    Add (&P1.Skill, 1);
    Add (&P2.Skill, 1);
    

    CetakPeta(N,M,Arr);
    
    return 0;
}