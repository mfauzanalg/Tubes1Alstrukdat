#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"


int main()
{
    MATRIKS MC;
    int i, j;
    printf("Membuat matriks 4 x 4\n");
    CreateEmptyMatriks(4, 4, &MC);
    printf("Indeks baris pertama    : %d\n", GetFirstIdxBrs(MC));
    printf("Indeks baris terakhir   : %d\n", GetLastIdxBrs(MC));
    printf("Indeks kolom pertama    : %d\n", GetFirstIdxKol(MC));
    printf("Indeks kolom terakhir   : %d\n", GetLastIdxKol(MC));

    ElmtMat(MC,1,1)=10;
    ElmtMat(MC,1,2)=40;
    ElmtMat(MC,1,3)=0;
    ElmtMat(MC,1,4)=40;

    ElmtMat(MC,2,1)=15;
    ElmtMat(MC,2,2)=60;
    ElmtMat(MC,2,3)=0;
    ElmtMat(MC,2,4)=0;

    ElmtMat(MC,3,1)=20;
    ElmtMat(MC,3,2)=80;
    ElmtMat(MC,3,3)=0;
    ElmtMat(MC,3,4)=0;

    ElmtMat(MC,4,1)=25;
    ElmtMat(MC,4,2)=100;
    ElmtMat(MC,4,3)=0;
    ElmtMat(MC,4,4)=0;

    printf("isi matriks Matriks MC di print manual : \n");
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            printf("%d ", ElmtMat(MC, i, j));
        }
        printf("\n\n");
    }
    
    printf("Dengan fungsi print matriks : \n");
    TulisMATRIKS(MC);
    printf("\n");

    return 0;
}