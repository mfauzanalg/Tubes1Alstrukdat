#include "olahfile.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int M;
    int J;
    TabBang Arr;
    MATRIKS Mat;
    List L1, L2, L3;

    N = 0;
    M = 0;
    J = 0;
    
    LoadFile (&N, &M, &J, &Arr, &Mat, &L1, &L2, &L3);
    CetakPeta(N,M,Arr);
    return 0;
}