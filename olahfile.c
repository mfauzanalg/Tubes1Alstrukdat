#include <stdio.h>
#include <stdlib.h>
#include "olahfile.h"

void LoadFile (int *N, int *M, int *J, TabBang *Arr, MATRIKS *Mat, List *L1, List *L2, List *L3){
	int i;
	int j;
	address P1;
	address P2;
	
	STARTKATA();
	*N = CKata.val;

	ADVKATA();
	*M = CKata.val;

	ADVKATA();
	*J = CKata.val;

	for (i = 1; i <= *J; i++){
		ADVKATA();
		Elmt(*Arr,i).milik = 0;
		Elmt(*Arr,i).jum = 0;
		Elmt(*Arr,i).lev = 1;

		if(CKata.bangunan == 'C'){
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 40;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 40;
		}
		else if(CKata.bangunan == 'T'){
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = true;
			Elmt(*Arr,i).U = 30;
		}
		else if(CKata.bangunan == 'F'){
			Elmt(*Arr,i).A = 10;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 80;
		}
		else if(CKata.bangunan == 'V'){
			Elmt(*Arr,i).A = 5;
			Elmt(*Arr,i).M = 20;
			Elmt(*Arr,i).P = false;
			Elmt(*Arr,i).U = 20;
		}
	Elmt(*Arr,1).milik = 1;
	Elmt(*Arr,2).milik = 2;

		ADVKATA();
		Elmt(*Arr,i).letak.X = CKata.val;
		ADVKATA();
		Elmt(*Arr,i).letak.Y = CKata.val;
	}

	for (i = 1; i <= *J; i++){
		for (j = 1; j <= *J; i++){
			ADVKATA();
			ElmtMat(*Mat, i, j) == CKata.val;
		}
	}

	CLOSE();
	
	InsVFirst(&*L1, 1);
	InsVFirst(&*L2, 2);

	for (i = 3; i <= *J; i++){
		InsVFirst(&L3, i);
	}
}