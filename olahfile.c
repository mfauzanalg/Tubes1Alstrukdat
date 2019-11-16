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
		Elmt(*Arr,i).lev = 1;
		Elmt(*Arr,i).nomor = i;
		Elmt(*Arr,i).attack = false;
		Elmt(*Arr,i).move = false;

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
		Elmt(*Arr,i).jum = Elmt(*Arr,i).U;
		ADVKATA();
		Elmt(*Arr,i).letak.X = StringToInteger(CKata);
		ADVKATA();
		Elmt(*Arr,i).letak.Y = StringToInteger(CKata);
	}
	

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
	P = Alokasi(17);
	InsertFirst(&*L1, P);
	P = Alokasi(2);
	InsertFirst(&*L2, P);

	CreateEmptyGraph(ArrGraph, *J, Mat);

}

void CetakPeta(int N, int M, TabBang Arr, PLAYER P1, PLAYER P2){ //N itu baris M itu kolom
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
					if (owner(k, P1.ListB, P2.ListB) == 1){
						print_red(Elmt(Arr,k).type);
					}
					else if (owner(k, P1.ListB, P2.ListB) == 2){
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

void DaftarBangunan(List L, TabBang Arr, TabInt *TOut){
	int i = 1;
	int j = 1;
	int num = 1;
	boolean found;
	addresslist P;
	P = First(L);
	Neff(*TOut) = 0;

	printf("Daftar bangunan :\n");
	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i){
				printf("%d. ", num);
				num++;
				ElmtStat(*TOut,j) = i;
				Neff(*TOut) ++;
				j++;

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

void AdaSerang (List L, TabBang Arr, int player, boolean *ada, PLAYER P1, PLAYER P2){
	int i = 1;
	boolean found;
	addresslist P;
	P = First(L);
	*ada = false;

	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i && owner(i, P1.ListB, P2.ListB) != player){
				*ada = true;
				found = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
	}
}

void DaftarSerang(List L, TabBang Arr, TabInt *TOut, int player, PLAYER P1, PLAYER P2){
	int i = 1;
	int j = 1;
	int num = 1;
	boolean found;
	addresslist P;
	P = First(L);
	Neff(*TOut) = 0;

	printf("Daftar bangunan Untuk diserang :\n");
	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i && owner(i, P1.ListB, P2.ListB) != player){
				printf("%d. ", num);
				num++;
				ElmtStat(*TOut,j) = i;
				Neff(*TOut) ++;
				j++;

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
}

void AdaMove (List L, TabBang Arr, int player, boolean *ada, PLAYER P1, PLAYER P2){
	int i = 1;
	boolean found;
	addresslist P;
	P = First(L);
	*ada = false;

	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i && owner(i, P1.ListB, P2.ListB) == player){
				printf("ini i %d", i);
				*ada = true;
				found = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
	}
}

void DaftarMove(List L, TabBang Arr, TabInt *TOut, int player, PLAYER P1, PLAYER P2){
	int i = 1;
	int j = 1;
	int num = 1;
	boolean found;
	addresslist P;
	P = First(L);
	Neff(*TOut) = 0;

	printf("Daftar bangunan tujuan pemindahan pasukan :\n");
	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(Arr) && !(found)){
			if (Info(P) == i && owner(i, P1.ListB, P2.ListB) == player){
				printf("%d. ", num);
				num++;
				ElmtStat(*TOut,j) = i;
				Neff(*TOut) ++;
				j++;

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
}

void StartPlayer (PLAYER *P){
	CreateEmptyQueue(&(*P).Skill, 10);
	AddQueue(&(*P).Skill, 1);
	IsShield(*P) = false;
	IsAttackUp(*P) = false;
	IsCriticalHit(*P) = false;
	Askill(*P) = false;
	Aend(*P) = false;
}

void UpdateBangunan (List L, TabBang *Arr){
	int i =1;
	boolean found;
	addresslist P;
	P = First(L);

	while (P != NilList){
		i = 1;
		found = false;
		while (i <= NbElmtArr(*Arr) && !(found)){
			if (Info(P) == i){
				if (!(Elmt(*(Arr),i).jum >= Elmt(*(Arr),i).M)){ //kalo blm lebih dari M maka ditambah
					Elmt(*(Arr),i).jum += Elmt(*(Arr),i).A ;
				}
				found = true;
				Elmt(*(Arr),i).attack = true;
				Elmt(*(Arr),i).move = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
	}
}

void CetakSkill (int x){
	if (x == 1){
		printf ("IU");
	}
	else if (x == 2){
		printf ("S");
	}
	else if (x == 3){
		printf ("ET");
	}
	else if (x == 4){
		printf ("AU");
	}
	else if (x == 5){
		printf ("CH");
	}
	else if (x == 6){
		printf ("IR");
	}
	else if (x == 7){
		printf ("B");
	}
}

int owner (int i, List P1, List P2){
	addresslist addr1 = Search(P1, i);
	addresslist addr2 = Search(P2, i);
	if(addr1 != NilList && addr2 == NilList){
		return 1;
	}
	else if(addr1 == NilList && addr2 != NilList){
		return 2;
	}
	else{
		return 0;
	}
}

