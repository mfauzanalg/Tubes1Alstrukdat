#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olahfile.h"
#include "typebentukan.h"
#include "stack.h"
#include "command.h"

int main(){
	int i;
    int N; 			            //Jumlah baris
    int M;			            //Jumlah kolom
    int J; 			            //Jumlah bangunan
    boolean playing;            //Status bermain
    boolean P1turn;
    TabBang Arr, Arr2; 	        //Array menyimpan tipe data bangunan
    TabGraph ArrGraph;          //Array menyimpan graf
    Stack SBang;                //Stack menyimpan Array Bangunan
    stackp SP1, SP2;            //Stack menyimpan data Player
    MATRIKS Mat;                //Matriks menyimpan data untk graf
    PLAYER P1, P2, P3;          //Pemain 
    addresslist P;
    JumlahB Jumlah1, Jumlah2;    //Jumlah bangunan yang dimiliki pemain1
    TabInt T;                   //Tab untuk membuat bangunan yang dapat dipilih
    int X;                      //Untuk input memilih bangunan
    Condition Kondisi;
    int ET;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    playing = true;
    P1turn = true;
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyStack(&SBang);
    Aend(P1) = true;
    system("CLS");

    while (playing){
        //PLAYER 1
        UpdateBangunan (P1.ListB, &Arr);
        while ((playing) && (P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah1, Jumlah2, &Kondisi);
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
                Aend(P2) = true;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){ //sudah jalan
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
                DaftarBangunan(P1.ListB, Arr, &T);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P1, ElmtStat(T, X));
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                printf("nanti ya\n");
                Askill(P1) = true;
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                if (Aend(P1)){
                    printf("Anda baru saja memulai permainan, tidak bisa UNDO\n");
                }
                else if (Askill(P1)){
                    printf("Anda baru saja menggunakan skill, tidak bisa UNDO\n");
                }
                else{
                    UndoAll (&Arr, &SBang, &P1, &SP1);
                }
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
            }
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            if (Kondisi.S){
                if (JTotal(Jumlah2) == 2){
                    AddQueue(&P2.Skill, 2);
                }
            }
            if (Kondisi.AU){
                if (JTower(Jumlah2) == 3){
                    AddQueue(&P1.Skill, 4);
                }
            }
            if (Kondisi.B){
                if (JTotal(Jumlah1) == 10){
                    AddQueue(&P2.Skill, 8);
                }
            }
            //system("CLS");
        } 


        //PLAYER 2
        UpdateBangunan (P2.ListB, &Arr);
        while ((playing) && !(P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah2, Jumlah1, &Kondisi);
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
                Aend(P2) = true;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                DaftarBangunan(P2.ListB, Arr, &T);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P2, ElmtStat(T, X));
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                printf("nanti ya\n");
                Askill(P1) = true;
                
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                if (Aend(P2)){
                    printf("Anda baru saja memulai permainan, tidak bisa UNDO\n");
                }
                else if (Askill(P2)){
                    printf("Anda baru saja menggunakan skill, tidak bisa UNDO\n");
                }
                else{
                    UndoAll (&Arr, &SBang, &P1, &SP1);
                }
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                printf("nanti ya\n");
                Aend(P1) = false;
                Askill(P1) = false;
            }

            //system("CLS");
        } 

    } 
	return 0;
}