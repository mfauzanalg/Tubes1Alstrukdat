#include "olahfile.h"
#include "typebentukan.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    int N; //baris
    int M; //kolom
    int J; //jumlah bangunan
    TabBang Arr, Arr2; //Arr menyimpan tipe data bangunan
    TabBang Arr; //Arr menyimpan tipe data bangunan
    TabGraph ArrGraph; //Arr menyimpan graf
    MATRIKS Mat; //Matriks menyimpan data untk graf
    List L3; //List untuk kepemilikan bangunan
    PLAYER P1, P2; 
    boolean exit = false;
    Stack SBang;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.Bang, &P2.Bang);
    CreateEmptyQueue(&P1.Skill, 10);
    CreateEmptyQueue(&P2.Skill, 10);

    //input.Kata[1] = 'I';
    //input.Kata[2] = 'U';
    //AddQueue (&P1.Skill, input);
    //AddQueue (&P2.Skill, input);
    CreateEmptyStack(&SBang);
   // CetakPeta(N,M,Arr);
   // DaftarBangunan(P1.Bang, Arr);
  //  printf("Ayo isi woy : ");

   // STARTWORD();
   // for (i = 0; i <= 10; i++){
   //     printf("%c",CWord.TabKata[i]);
   // }    
   // if (strcmp(CWord.TabKata, "Lia") == 0) {
   //     printf("uyey sama\n");
    //}

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


    Elmt(Arr,1).jum = 100;
    CopyArr(Arr, &Arr2);
	Push (&SBang, Arr2);
	printf("satu %d ", Elmt(Arr,1).jum);
    
    Elmt(Arr,1).jum = 80;
    printf("satu %d ", Elmt(Arr,1).jum);

    CopyArr(Arr, &Arr2);
    Push (&SBang, Arr2);

    Elmt(Arr,1).jum = 90;
    printf("satu %d ", Elmt(Arr,1).jum);
    
    Pop (&SBang, &Arr);
    Pop (&SBang, &Arr);
    printf("tiga %d ", Elmt(Arr,1).jum);


    return 0;
}