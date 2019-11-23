#include <stdio.h>
#include <stdlib.h>
#include "../list/list.h"

int main(){
	List L, L1;
	infotypelist a, b, c, d, e, f;
	addresslist P1, P2, P3, P4, P5, P6;

	CreateEmptyList(&L);
	if (IsEmptyList(L)){
		printf("List kosong\n");
	}

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	scanf("%d", &f);

	printf("Insert First Input 1\n");
	P1 = Alokasi(a);
	InsertFirst(&L, P1);
	PrintInfo(L);
	printf("\n");

	printf("Insert Last Input 2\n");
	P2 = Alokasi(b);
	InsertLast(&L,P2);
	PrintInfo(L);
	printf("\n");

	printf("Insert After Elemen 1 Input 3\n");
	P3 = Alokasi(c);
	InsertAfter(&L, P3, P1);
	PrintInfo(L);
	printf("\n");
	
	printf("Insert Last Input 4\n");
	InsVLast(&L,d);
	PrintInfo(L);
	printf("\n");

	printf("Insert First Input 5\n");
	InsVFirst(&L,e);
	PrintInfo(L);
	printf("\n");

	printf("Del Input 1\n");
	DelP(&L, a);
	PrintInfo(L);
	printf("\n");
	
	printf("Banyaknya elemen list = %d\n", NbElmtList(L));

	printf("Copy List\n");
	CopyList(L, &L1);
	PrintInfo(L1);
	printf("\n");

	if (Search(L,1) != NilList){
		printf("Angka 1 berada didalam list\n");
	}
	else{
		printf("Angka 1 tidak berada didalam list\n");
	}

}
