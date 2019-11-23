#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"


int main()
{
    MATRIKS MC, M2;
    int i, j;
    CreateEmptyMatriks(100, 100, &MC);
    printf("%d\n", GetFirstIdxBrs(MC));
    printf("%d\n", GetLastIdxBrs(MC));
    printf("%d\n", GetFirstIdxKol(MC));
    printf("%d\n", GetLastIdxKol(MC));

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

    printf("Matriks MC :\n");
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            printf("%d ", ElmtMat(MC, i, j));



        }
        printf("\n");


    }
    printf("Sebelum Copy\n");
    CopyMATRIKS(MC, &M2);


    printf("Matriks M2 :\n");
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            printf("%d ", ElmtMat(M2, i, j));



        }
        printf("\n");


    }

    return 0;
}