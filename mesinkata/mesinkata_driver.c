#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"


int main()
{
    int i=1,j;
    Kata K[100];
    STARTKATA();
    // K[i]=CKata;
    for (j=1;j<=CKata.Length;j++)
    {
        K[i].TabKata[j]=CKata.TabKata[j];
        //printf("for (j=1;j<=CKata.Length;j++) %d\n", j);


    }
    K[i].Length=CKata.Length;
    //printf("K[i].Length=CKata.Length;\n");








    for (i=2;i<=87;i++)
    {
        ADVKATA();
        // K[i]=CKata;
        for (j=1;j<=CKata.Length;j++)
        {
            K[i].TabKata[j]=CKata.TabKata[j];
            printf("for (j=1;j<=CKata.Length;j++) %d bawah\n", j);


        }
        printf("for (i=2;i<=150;i++) %d\n", i);
        K[i].Length=CKata.Length;
        printf("K[i].Length=CKata.Length;\n");

    }
    SalinLast();
    for (j=1;j<=CKata.Length;j++)
    {
        K[i].TabKata[j]=CKata.TabKata[j];
        printf("for (j=1;j<=CKata.Length;j++) %d bawah\n", j);


    }
    printf("for (i=2;i<=150;i++) %d\n", i);
    K[i].Length=CKata.Length;
    printf("K[i].Length=CKata.Length;\n");

    //ADVKATA();
    //printf("tengah\n");
    for (i=1;i<=88;i++)
    {
        //printf("for (i=1;i<=10;i++) %d\n", i);
        for (j=1;j<=K[i].Length;j++)
        {
            printf("%c", K[i].TabKata[j]);
            //printf("for (j=1;j<=K[i].Length;j++) ketiga %d %d\n", i, j);



        }
        printf(" ");



    }
    printf("\n");
    printf("StringToInteger\n");

    printf("%d\n", StringToInteger(K[1])*10+2);



    return 0;
}