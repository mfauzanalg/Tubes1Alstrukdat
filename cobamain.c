#include "olahfile.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr; //Arr menyimpan tipe data bangunan
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L1, L2, L3; //List untuk kepemilikan bangunan

    N = 0;
    M = 0;
    J = 0;
    
    LoadFile (&N, &M, &J, &Arr, &Mat, &L1, &L2, &L3);
    CetakPeta(N,M,Arr);
    DaftarBangunan(P1, Arr);
    DaftarBangunan(P2, Arr);
    DaftarBangunan(P3, Arr);
    return 0;
}