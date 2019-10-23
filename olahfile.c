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

	ADVKATA();
	*M = CKata.val;

	ADVKATA();
	*J = CKata.val;

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

		if(CKata.bangunan == 'C'){
			Elmt(*Arr,i).type = 'C';
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 40;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 40;
		}
		else if(CKata.bangunan == 'T'){
			Elmt(*Arr,i).type = 'T';
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = true;
			Elmt(*Arr,i).U = 30;
		}
		else if(CKata.bangunan == 'F'){
			Elmt(*Arr,i).type = 'F';
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 80;
		}
		else if(CKata.bangunan == 'V'){
			Elmt(*Arr,i).type = 'V';
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 20;
		}

		ADVKATA();
		Elmt(*Arr,i).letak.X = CKata.val;
		ADVKATA();
		Elmt(*Arr,i).letak.Y = CKata.val;
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
				z++;
			}
			else{
				ADVKATA();
				ElmtMat(*Mat, i, z) = CKata.val;
				z++;
			}
		}
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
}

void CetakPeta(int N, int M, TabBang Arr){ //N itu baris M itu kolom
	MATRIKS peta;
	int i;
	int j;
	int k;
	boolean found;
	CreateEmptyMatriks (N+2, M+2, &peta);

	for (i = GetFirstIdxBrs(peta); i <= GetLastIdxBrs(peta); i ++){
		for (j = GetFirstIdxKol(peta); j <= GetLastIdxKol(peta); j++){

			if (i == GetFirstIdxBrs(peta) || i == GetLastIdxBrs(peta)){
				if (j == GetLastIdxKol(peta)){
					printf("*\n");
				}
				else{
					printf("*");
				}
			}
			else if (j == GetFirstIdxKol(peta)){
				printf("*");
			}
			else if (j == GetLastIdxKol(peta)){
				printf("*\n");
			}
			else{
				found = false;
				for (k = 1; k <= NbElmtArr(Arr); k++){
					if (i == Elmt(Arr,k).letak.X + 1 && j ==  Elmt(Arr,k).letak.Y + 1){
						found = true;
						break;
					}
				}
				if (found){
					if (Elmt(Arr,k).milik == 1){
						print_red(Elmt(Arr,k).type);
					}
					else if (Elmt(Arr,k).milik == 2){
						print_yellow(Elmt(Arr,k).type);
					}
					else
					{
						printf("%c", Elmt(Arr,k).type);
					}
					
				}
				else{
					printf(" ");
				}
			}
		}
	}
}