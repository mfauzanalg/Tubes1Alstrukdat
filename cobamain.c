#include "olahfile.h"
#include "typebentukan.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levelup.h"

int main(){
    int i;
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr, Arr2; //Arr menyimpan tipe data bangunan
    TabGraph ArrGraph; //Arr menyimpan graf
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L3; //List untuk kepemilikan bangunan
    PLAYER P1, P2, P3; 
    boolean exit = false;
    Stack SBang;
    stackp SP1;
    addresslist P;
    printf("Hello aku masuk sini");
    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.ListB, &P2.ListB);
    CreateEmptyQueue(&P1.Skill, 10);
    CreateEmptyQueue(&P2.Skill, 10);
    /*
    CreateEmptyArray(&Arr, 18);
    Elmt(Arr, 1).nomor=1;
    Elmt(Arr, 1).type='T';
    Elmt(Arr, 1).milik=1;
    Elmt(Arr, 1).jum=50;
    Elmt(Arr, 1).lev=1;
    Elmt(Arr, 1).A=5;
    Elmt(Arr, 1).M=20;
    Elmt(Arr, 1).P=false;
    Elmt(Arr, 1).U=30;
    Elmt(Arr, 1).letak.X=1;
    Elmt(Arr, 1).letak.Y=13;
    Elmt(Arr, 1).attack=false;
    

  //  levelUp(Arr, Arr2, P1, 1);
    printf("%d\n", Elmt(Arr, 1).jum);
    printf("%d\n", Elmt(Arr, 1).lev);
    printf("%d\n", Elmt(Arr, 1).A);
    printf("%d\n", Elmt(Arr, 1).M);
    printf("%d\n", Elmt(Arr, 1).P);
    */

    CreateEmptystackp(&SP1);

    AddQueue (&P1.Skill, 1);

    P1.Shield = true;
    P = Alokasi(9);
    InsertLast(&P1.ListB, P);

    printf ("shield %d\n", P1.Shield);
    printf ("Nbelmt Queue %d\n", NBElmtQueue(P1.Skill));
    PrintInfo (P1.ListB);
    printf("\n");

    CopyPlayer(P1, &P3);
    Pushp (&SP1, P3);

    AddQueue (&P1.Skill, 1);
    P1.Shield = false;
    P = Alokasi(7);
    InsertLast(&P1.ListB, P);

    AddQueue (&P1.Skill, 1);
    P1.Shield = false;
    P = Alokasi(7);
    InsertLast(&P1.ListB, P);

    printf ("shield %d\n", P1.Shield);
    printf ("Nbelmt Queue %d\n", NBElmtQueue(P1.Skill));
    PrintInfo (P1.ListB);
    printf("\n");

    Popp(&SP1, &P1);

    printf ("shield %d\n", P1.Shield);
    printf ("Nbelmt Queue %d\n", NBElmtQueue(P1.Skill));
    PrintInfo (P1.ListB);
    printf("\n");
    



    CreateEmptyStack(&SBang);
   // CetakPeta(N,M,Arr);
   // DaftarBangunan(P1.Bang, Arr);
  //  printf("Ayo isi woy : ");

  // STARTWORD();  



/*
    if (strcmp("Fauzannnn", "Fauzan") == 0) {
        printf("uyey sama\n");
    }
    STARTWORD();     
    if (strcmp(CWord.TabKata, "Lia") == 0) {
        printf("uyey sama\n");
    }
*/

/*
    CreateEmptyQueue(&P1.Skill, 10);
    AddQueue(&P1.Skill, 1);
    AddQueue(&P1.Skill, 2);
    AddQueue(&P1.Skill, 3);
    printf("%d\n", NBElmtQueue(P1.Skill));

    Push(&SBang, P1.Skill);
    AddQueue(&P1.Skill, 4);
    printf("%d\n", NBElmtQueue(P1.Skill));

    Pop(&SBang, &P1.Skill);
    printf("%d\n", NBElmtQueue(P1.Skill));
*/


    Elmt(Arr,1).lev = 1;
    
    CopyArr(Arr, &Arr2);
	Push (&SBang, Arr2);

	printf("satu %d \n", Elmt(Arr,1).lev);
    
    Elmt(Arr,1).lev = 2;
    printf("satu %d \n", Elmt(Arr,1).lev);

    //CopyArr(Arr, &Arr2);
    //Push (&SBang, Arr2);

    //Elmt(Arr,1).jum = 20;
    //printf("satu %d \n", Elmt(Arr,1).lev);
    
    Pop (&SBang, &Arr);
    printf("satu %d \n", Elmt(Arr,1).lev);

    return 0;
}