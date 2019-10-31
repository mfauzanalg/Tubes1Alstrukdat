#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olahfile.h"
#include "typebentukan.h"
#include "stack.h"
#include "command.h"

int main(){
	int i;
    int N; 			    //Jumlah baris
    int M;			    //Jumlah kolom
    int J; 			    //Jumlah bangunan
    boolean playing;    //Status bermain
    boolean P1turn;
    TabBang Arr, Arr2; 	//Array menyimpan tipe data bangunan
    TabGraph ArrGraph;  //Array menyimpan graf
    Stack SBang;        //Stack menyimpan Array Bangunan
    stackp SP1, SP2;    //Stack menyimpan data Player
    MATRIKS Mat;        //Matriks menyimpan data untk graf
    PLAYER P1, P2, P3;  //Pemain 
    addresslist P;
    TabInt T; 
    int X;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    playing = true;
    P1turn = true;
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyStack(&SBang);
    system("CLS");

    while (playing){
        UpdateBangunan (P1.ListB, &Arr);
        while ((playing) && (P1turn)){
            CetakPeta(N,M,Arr);
            printf("PLayer 1\n");
            DaftarBangunan(P1.ListB, Arr, &T);
            printf("Skill Available : "); 
            CetakSkill(InfoHead(P1.Skill));
            printf("\n");
            printf("ENTER COMMAND : ");
            STARTWORD();
    
            if (strcmp(CWord.TabKata, "EXIT") == 0){ //sudah jalan
                playing = false;
            }

            else if (strcmp(CWord.TabKata, "END_TURN") == 0){ //sudah jalan
                P1turn = false;
                Aend(P1) = true;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){ //sudah jalan
                DaftarBangunan(P1.ListB, Arr, &T);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P1, ElmtStat(T, X));
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                printf("nanti ya\n");
                Askill(P1) = true;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                printf("nanti ya\n");
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }
            system("CLS");
        } 

        UpdateBangunan (P2.ListB, &Arr);
        while ((playing) && !(P1turn)){
            CetakPeta(N,M,Arr);
            printf("PLayer 2\n");
            DaftarBangunan(P2.ListB, Arr, &T);
            printf("Skill Available : "); 
            CetakSkill(InfoHead(P2.Skill));
            printf("\n");
            printf("ENTER COMMAND : "); 
            STARTWORD();
            if (strcmp(CWord.TabKata, "EXIT") == 0){
                playing = false;
            }

            else if (strcmp(CWord.TabKata, "END_TURN") == 0){
                P1turn = true;
                Aend(P1) = true;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){
                DaftarBangunan(P2.ListB, Arr, &T);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P2, ElmtStat(T, X));
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                printf("nanti ya\n");
                Askill(P1) = true;
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                printf("nanti ya\n");
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
            }

            system("CLS");
        } 

    } 
	return 0;
}