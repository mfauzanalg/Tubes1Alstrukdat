#include <stdio.h>
#include <stdlib.h>
#include "olahfile.h"

addresslist P;
addresslist Prec;

int i;
int z;

void LoadFile (int *N, int *M, int *J, TabBang *Arr, TabGraph *ArrGraph, MATRIKS *Mat, List *L1, List *L2){
	STARTKATA();
	*N = StringToInteger(CKata);

	ADVKATA();
	*M = StringToInteger(CKata);

	ADVKATA();
	*J = StringToInteger(CKata);

	CreateEmptyMatriks(*J, *J, &*Mat);
	CreateEmptyList(&*L1);
	CreateEmptyList(&*L2);
	CreateEmptyArray(&*Arr, *J);

	for (i = 1; i <= *J; i++){
		ADVKATA();
		Elmt(*Arr,i).milik = 0;
		Elmt(*Arr,i).jum = 0;
		Elmt(*Arr,i).lev = 1;
		Elmt(*Arr,i).nomor = i;
		Elmt(*Arr,i).attack = false;

		if(CKata.TabKata[1] == 'C'){
			Elmt(*Arr,i).type = 'C';
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 40;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 40;
		}
		else if(CKata.TabKata[1] == 'T'){
			Elmt(*Arr,i).type = 'T';
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = true;
			Elmt(*Arr,i).U = 30;
		}
		else if(CKata.TabKata[1] == 'F'){
			Elmt(*Arr,i).type = 'F';
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 80;
		}
		else if(CKata.TabKata[1] == 'V'){
			Elmt(*Arr,i).type = 'V';
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 20;
		}

		ADVKATA();
		Elmt(*Arr,i).letak.X = StringToInteger(CKata);
		ADVKATA();
		Elmt(*Arr,i).letak.Y = StringToInteger(CKata);
	}

	Elmt(*Arr,1).milik = 1;
	Elmt(*Arr,2).milik = 2;

	i = 1;
	while (i <= *J){
		z = 1;
		while (z <= *J){
			if (i == *J && z == *J){
				SalinLast();
				ElmtMat(*Mat, i, z) = StringToInteger(CKata);
				z++;
			}
			else{
				ADVKATA();
				ElmtMat(*Mat, i, z) = StringToInteger(CKata);
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

	CreateEmptyGraph(ArrGraph, *J, Mat);

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
	printf("\n");
}

void DaftarBangunan(List L, TabBang Arr){
	int i =1;
	int num = 1;
	boolean found;
	addresslist P;
	P = First(L);
	
	printf("Daftar bangunan :\n");
	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i){
				printf("%d. ", num);
				num++;

				if(Elmt(Arr,i).type == 'C'){
					printf("Castle (%d,%d) %d lv. %d\n", Elmt(Arr,i).letak.X, Elmt(Arr,i).letak.Y, Elmt(Arr,i).jum, Elmt(Arr,i).lev);
				}
				else if(Elmt(Arr,i).type == 'T'){
					printf("Tower (%d,%d) %d lv. %d\n", Elmt(Arr,i).letak.X, Elmt(Arr,i).letak.Y, Elmt(Arr,i).jum, Elmt(Arr,i).lev);
				}
				else if(Elmt(Arr,i).type == 'V'){
					printf("Village (%d,%d) %d lv. %d\n", Elmt(Arr,i).letak.X, Elmt(Arr,i).letak.Y, Elmt(Arr,i).jum, Elmt(Arr,i).lev);
				}
				else if(Elmt(Arr,i).type == 'F'){
					printf("Fort (%d,%d) %d lv. %d\n", Elmt(Arr,i).letak.X, Elmt(Arr,i).letak.Y, Elmt(Arr,i).jum, Elmt(Arr,i).lev);
				}
				found = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
	}
	printf("\n");
}

void StartPlayer (PLAYER *P){
	CreateEmptyQueue(&(*P).Skill, 10);
	AddQueue(&(*P).Skill, 1);
	Shield(*P) = false;
	AttackUp(*P) = false;
	CriticalHit(*P) = false;
}

