#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../typebentukan/typebentukan.h"
#include "../boolean/boolean.h"
#include "array.h"

void print_array(TabBang *Arr, int maxel){
    int i;
    int f;
    char input2;
    for (i = IdxMin;i <= MaxElArr(*Arr); i++){
        printf("Type bangunan ke-%d = ",i);
        input2 = Elmt(*Arr,i).type;
        if (input2 == 'C'){
            printf("Bangunan Castle");
        }
        else if (input2 == 'T'){
            printf("Bangunan Tower");
        }
        else if (input2 == 'V'){
            printf("Bangunan Village");
        }else if (input2 == 'F'){
            printf("Bangunan Fort");
        }
        printf("\n");
        printf("Jumlah Pasukan bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).jum);
        printf("Level bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).lev);
        printf("Penambahan Pasukan bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).A);
        printf("Maksimum penambahan Pasukan bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).M);
        printf("Memiliki pertahanan bangunan ke-%d",i);
        f = Elmt(*Arr,i).P;
        if (f == 0){
            printf(" false");
        }
        else{
            printf(" true");
        }
        printf("\n");
        printf("Pasukan awal bangunan yang tak dimiliki pemain bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).U);
        printf("Posisi Horizontal bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).letak.X);
        printf("Posisi vertikal bangunan ke-%d",i);
        printf(" = %d.\n",Elmt(*Arr,i).letak.Y);
        printf("Masih bisa command move, bangunan ke-%d = ",i);
        f = Elmt(*Arr,i).move;
        if (f == 0){
            printf(" false");
        }
        else{
            printf(" true");
        }
        printf("\n");
        printf("Masih bisa command attack, bangunan ke-%d = ",i);
        f = Elmt(*Arr,i).move;
        if (f == 0){
            printf(" false\n");
        }
        else{
            printf(" true\n");
        }
        printf("\n");

    }
}

void isiarray (TabBang *Arr, int maxel){
    int i;
    int G;
    char input2;
    for (i = IdxMin;i <= MaxElArr(*Arr); i++){
        printf("Masukkan Type bangunan ke-%d (C/T/F/V) = ",i);
        scanf(" %c", &input2);
        Elmt(*Arr,i).type = input2;
        printf("\n");
        printf("Masukkan jumlah Pasukan bangunan ke-%d = ",i);
		scanf(" %d",&G);
		printf("\n");
		Elmt(*Arr,i).jum = G;
        printf("Masukkan Level bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).lev = G;
        printf("Masukkan Penambahan Pasukan bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).A = G;
        printf("Masukkan Maksimum penambahan Pasukan bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).M = G;
        printf("Masuukkan bangunan Memiliki pertahanan bangunan ke-%d (0/1) = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).P = G;
        printf("Masukkan Pasukan awal bangunan yang tak dimiliki pemain bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).U = G;
        printf("Masukkan Posisi Horizontal bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).letak.X = G;
        printf("Masukkan Posisi vertikal bangunan ke-%d = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).letak.Y = G;
		printf("Masukkan Masih bisa pake command attack, bangunan ke-%d (0/1) = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).move = G;
		printf("Masukkan Masih bisa pake command move, bangunan ke-%d (0/1) = ",i);
		scanf(" %d", &G);
		printf("\n");
		Elmt(*Arr,i).letak.Y = G;
	}
}

int main(){
    TabBang arr1, arr2;
    int maxel;
    int jum, pertama, terakhir;
    printf("Masukkan jumlah bangunan yang ingin dibuat : ");
    scanf("%d", &maxel);
    printf("\n");
    CreateEmptyArray(&arr1, maxel);
    printf("Input elemen-elemen bangunan :\n\n");
    isiarray(&arr1, maxel);
    printf("Check array yang sudah di input....\n");
    printf("\n");
    print_array(&arr1, maxel);
    printf("\n");
    printf("banyak bangunan = ");
    jum = NbElmtArr(arr1);
    printf("%d\n", jum);
    printf("\n");
    printf("bangunan pertama = ");
    pertama = GetFirstIdx(arr1);
    printf("%d\n", pertama);
    printf("\n");
    printf("bangunan terakhir = ");
    terakhir = GetLastIdx(arr1);
    printf("%d\n", terakhir);
    printf("\n");
    CopyArr(arr1, &arr2);
    printf("\n");
    printf("hasil copy array\n");
    printf("\n");
    print_array(&arr2, maxel);
    printf("\n");
    printf("dealokasi\n");
    DealokasiArr(&arr1);
    printf("Hasil array arr1 yang baru di dealokasi.....\n");
    printf("\n");
    print_array(&arr1, maxel);
    printf("karena arr1 di dealokasi, sehingga tidak mencetak apa-apa\n");
    return 0;
}


