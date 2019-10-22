#include <stdio.h>
#include <stdlib.h>
#include "olahfile.h"

int i;
int z;
addresslist P;
addresslist Prec;

void LoadFile (int *N, int *M, int *J, TabBang *Arr, MATRIKS *Mat, List *L1, List *L2, List *L3){
	STARTKATA();
	*N = CKata.val;
	printf("ini adalah N %d\n", *N);

	ADVKATA();
	*M = CKata.val;
	printf("ini adalah M %d\n", *M);

	ADVKATA();
	*J = CKata.val;
	printf("ini adalah J %d\n", *J);

	CreateEmptyMatriks(*J, *J, &*Mat);
	CreateEmptyList(&*L1);
	CreateEmptyList(&*L2);
	CreateEmptyList(&*L3);
	CreateEmptyArray(&*Arr, *J);

	for (i = 1; i <= *J; i++){
		ADVKATA();
		Elmt(*Arr,i).milik = 0;
		Elmt(*Arr,i).jum = 0;
		Elmt(*Arr,i).lev = 1;
		printf("ini adalah i %d\n", i);

		if(CKata.bangunan == 'C'){
			printf("ini adalah char %c\n", CKata.bangunan);
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 40;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 40;
		}
		else if(CKata.bangunan == 'T'){
			printf("ini adalah char %c\n", CKata.bangunan);
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = true;
			Elmt(*Arr,i).U = 30;
		}
		else if(CKata.bangunan == 'F'){
			printf("ini adalah char %c\n", CKata.bangunan);
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 80;
		}
		else if(CKata.bangunan == 'V'){
			printf("ini adalah char %c\n", CKata.bangunan);
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 20;
		}

		ADVKATA();
		Elmt(*Arr,i).letak.X = CKata.val;
		printf("ini adalah x %d\n", CKata.val);
		ADVKATA();
		Elmt(*Arr,i).letak.Y = CKata.val;
		printf("ini adalah y %d\n", CKata.val);
	}

	Elmt(*Arr,1).milik = 1;
	Elmt(*Arr,2).milik = 2;

	i = 1;
	while (i <= *J){
		z = 1;
		while (z <= *J){
			if (i == *J && z == *J){
				SalinLast();
				ElmtMat(*Mat, i, z) = CKata.val;
				printf("ini adalah i dan z %d %d\n", i, z);
				printf("ini adalah masukin %d\n", CKata.val);
				z++;
			}
			else{
				ADVKATA();
				printf("ini adalah i dan z %d %d\n", i, z);
				printf("ini adalah masukin %d\n", CKata.val);
				ElmtMat(*Mat, i, z) = CKata.val;
				z++;
			}
		}
		printf("sampe sini %d\n", i);
		i++;
	}
	CLOSE();

	P = Alokasi(1);
	InsertFirst(&*L1, P);
	P = Alokasi(2);
	InsertFirst(&*L2, P);
	P = Alokasi(3);
	InsertFirst(&*L3, P);

	for (i = 4; i <= *J; i++){
		Prec = P;
		P = Alokasi(i);
		InsertAfter(&*L3, P, Prec);
	}

	PrintInfo(*L1);
	PrintInfo(*L2);
	PrintInfo(*L3);
}