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
    boolean ada;                //Ada bangunan yang dapat diserang atau ngga
    TabBang Arr, Arr2; 	        //Array menyimpan tipe data bangunan
    TabGraph ArrGraph;          //Array menyimpan graf
    Stack SBang;                //Stack menyimpan Array Bangunan
    stackp SP1, SP2;            //Stack menyimpan data Player
    MATRIKS Mat;                //Matriks menyimpan data untk graf
    PLAYER P1, P2, P3;          //Pemain 
    addresslist P;
    JumlahB Jumlah1, Jumlah2;   //Jumlah bangunan yang dimiliki pemain1
    TabInt T1, T2;              //Tab untuk membuat bangunan yang dapat dipilih
    List Tetangga;              //List yang berisi tetangga dari suatu bangunan
    int X;                      //Untuk input memilih bangunan
    int FAwal, FAkhir;          //Untuk mengecek jumlah fort apakah berkurang 1
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //PLAYER 1
        UpdateBangunan (P1.ListB, &Arr);
        while ((playing) && (P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah1, Jumlah2, &Kondisi);
            FAwal = JFort(Jumlah2);
            CetakPeta(N,M,Arr);
            printf("PLayer 1\n");
            DaftarBangunan(P1.ListB, Arr, &T1);
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
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
                DaftarBangunan(P1.ListB, Arr, &T1);
                printf("Pilih bangunan untuk menyerang : ");
                STARTWORD();
                X = WStringToInteger(CWord);

            
                if (Elmt(Arr,X).attack){
                    Tetangga = Neighbors(&ArrGraph, ElmtStat(T1,X));
                    AdaSerang (Tetangga, Arr, 1, &ada);
                    if (ada){
                        DaftarSerang(Tetangga, Arr, &T1, 1);
                        printf("Pilih bangunan yang ingin diserang : ");
                        STARTWORD();
                        X = WStringToInteger(CWord);
                    }
                    else {
                        printf("Tidak ada bangunan yang dapat diserang\n");
                    }
                    Elmt(Arr,X).attack = false;
                }
                else{
                    printf("Bangunan sudah menyerang pada turn ini\n");
                }


                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){ //sudah jalan
                PushAll(Arr, &Arr2, &SBang, P1, &P3, &SP1);
                DaftarBangunan(P1.ListB, Arr, &T1);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P1, ElmtStat(T1, X));
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                printf("nanti ya\n");
                Askill(P1) = true;
                Aend(P1) = false;
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
                DaftarBangunan(P1.ListB, Arr, &T1);
                printf("Pilih bangunan untuk dipindahkan : ");
                STARTWORD();
                X = WStringToInteger(CWord);

                if (Elmt(Arr,X).move){
                    Tetangga = Neighbors(&ArrGraph, ElmtStat(T1,X));
                    AdaMove (Tetangga, Arr, 1, &ada);
                    if (ada){
                        DaftarMove(Tetangga, Arr, &T1, 1);
                        printf("Pilih bangunan tujuan pemindahan : ");
                        STARTWORD();
                        X = WStringToInteger(CWord);
                    }
                    else {
                        printf("Tidak ada tujuan yang tersedia\n");
                    }
                    Elmt(Arr,X).move == false;
                }
                else{
                    printf("Bangunan sudah memindahkan pasukan pada turn ini\n");
                }


                Aend(P1) = false;
                Askill(P1) = false;
            }
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            FAkhir = JFort(Jumlah2);
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
            if (FAkhir == FAwal-1){
                AddQueue(&P2.Skill, 3);
            }
            //system("CLS");
        } 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //PLAYER 2
        UpdateBangunan (P2.ListB, &Arr);
        while ((playing) && !(P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah2, Jumlah1, &Kondisi);
            FAwal = JFort(Jumlah1);
            CetakPeta(N,M,Arr);
            printf("PLayer 2\n");
            DaftarBangunan(P2.ListB, Arr, &T1);
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
                Askill(P2) = false;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                DaftarBangunan(P2.ListB, Arr, &T1);
                printf("Pilih bangunan untuk menyerang : ");
                STARTWORD();
                X = WStringToInteger(CWord);

                if (Elmt(Arr,X).attack){
                    Tetangga = Neighbors(&ArrGraph, ElmtStat(T1,X));
                    AdaSerang (Tetangga, Arr, 2, &ada);
                    if (ada){
                        DaftarSerang(Tetangga, Arr, &T1, 2);
                        printf("Pilih bangunan yang ingin diserang : ");
                        STARTWORD();
                        X = WStringToInteger(CWord);
                    }
                    else {
                        printf("Tidak ada bangunan yang dapat diserang\n");
                    }
                    Elmt(Arr,X).attack = false;
                }
                else{
                    printf("Bangunan sudah menyerang pada turn ini\n");
                }

                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                DaftarBangunan(P2.ListB, Arr, &T1);
                printf("Bangunan yang akan di level up : ");
                STARTWORD();
                X = WStringToInteger(CWord);
                LevelUpUp(&Arr, P2, ElmtStat(T1, X));
                Aend(P2) = false;
                Askill(P2) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                PushAll(Arr, &Arr2, &SBang, P2, &P3, &SP2);
                printf("nanti ya\n");
                Askill(P2) = true;
                Aend(P2) = false;
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
                DaftarBangunan(P2.ListB, Arr, &T1);
                printf("Pilih bangunan untuk dipindahkan : ");
                STARTWORD();
                X = WStringToInteger(CWord);

                if (Elmt(Arr,X).move){
                    Tetangga = Neighbors(&ArrGraph, ElmtStat(T1,X));
                    AdaMove (Tetangga, Arr, 2, &ada);
                    if (ada){
                        DaftarMove(Tetangga, Arr, &T1, 2);
                        printf("Pilih bangunan tujuan pemindahan : ");
                        STARTWORD();
                        X = WStringToInteger(CWord);
                    }
                    else {
                        printf("Tidak ada tujuan yang tersedia\n");
                    }
                    Elmt(Arr,X).move == false;
                }
                else{
                    printf("Bangunan sudah memindahkan pasukan pada turn ini\n");
                }
                Aend(P2) = false;
                Askill(P2) = false;
            }

            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            FAkhir = JFort(Jumlah1);
            if (Kondisi.S){
                if (JTotal(Jumlah1) == 2){
                    AddQueue(&P1.Skill, 2);
                }
            }
            if (Kondisi.AU){
                if (JTower(Jumlah1) == 3){
                    AddQueue(&P2.Skill, 4);
                }
            }
            if (Kondisi.B){
                if (JTotal(Jumlah2) == 10){
                    AddQueue(&P1.Skill, 8);
                }
            }
            if (FAkhir == FAwal-1){
                AddQueue(&P1.Skill, 3);
            }
            //system("CLS");
        } 

    } 
	return 0;
}