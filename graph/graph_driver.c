#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../olahfile/olahfile.h"
#include "../typebentukan/typebentukan.h"
#include "../stack/stack.h"
#include "../command/command.h"
#include "graph.h"

int main(){
    printf("Masukkan elemen matriks 4x4 yang ada di file graph_driver.c (di copas saja)\n");
    /*  MATRIKS ADJACENCY
    0 1 0 1
    1 0 1 0
    0 1 0 0
    1 0 0 0 
    */
    MATRIKS Mat;
    GraphList Graph;
    int i,j,a;
    CreateEmptyMatriks(4,4,&Mat);
    for (i=1; i<=4; i++){
        for (j=1; j<=4; j++){
            scanf("%d", &a);
            ElmtMat(Mat, i, j) = a;
        }
    }

    CreateEmptyGraph(&Graph, Mat);
    printf("Elemen yang terhubung dengan elemen 1 = ");
    PrintInfo(Neighbors(Graph, 1));
    printf("\n");
    printf("Elemen yang terhubung dengan elemen 2 = ");
    PrintInfo(Neighbors(Graph, 2));
    printf("\n");
    printf("Elemen yang terhubung dengan elemen 3 = ");
    PrintInfo(Neighbors(Graph, 3));
    printf("\n");
    printf("Elemen yang terhubung dengan elemen 4 = ");
    PrintInfo(Neighbors(Graph, 4));
    printf("\n");

    printf("Apakah elemen 1 terhubung dengan elemen 3?\n");
    if (IsAdjacent(Graph, 1,3)){
        printf("Ya\n");
    }
    else{
        printf("Tidak\n");
    }
}