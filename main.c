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
    PLAYER P1, P2, P3;          //Pemain P3 untuk push aja
    addresslist P;
    JumlahB Jumlah1, Jumlah2;   //Jumlah bangunan yang dimiliki pemain1
    TabInt T1, T2;              //Tab untuk membuat bangunan yang dapat dipilih
    List Tetangga;              //List yang berisi tetangga dari suatu bangunan
    int X, Y;                      //Untuk input memilih bangunan
    int FAwal, FAkhir;          //Untuk mengecek jumlah fort apakah berkurang 1
    Condition Kondisi;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    playing = true;
    P1turn = true;
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyStack(&SBang);
    Aend(P1) = true;
    HELP();
    
    while (playing){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //PLAYER 1
        //Art1();
        UpdateBangunan (P1.ListB, &Arr);
        while ((playing) && (P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah1, Jumlah2, &Kondisi);
            FAwal = JFort(Jumlah2);

            CetakAwal(N,M,Arr, P1, P2, P1, 1, &T1);
            STARTWORD();
    
            if (strcmp(CWord.TabKata, "EXIT") == 0){ //sudah jalan
                playing = false;
            }

            else if (strcmp(CWord.TabKata, "END_TURN") == 0){ //sudah jalan
                printf("Anda Berhasil Mengakhiri Turn Ini\n");
                P1turn = false;
                Aend(P2) = true;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Attack(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, ArrGraph, P1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){ //sudah jalan
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                LevelUpUp(&Arr, P1, &X, &T1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                printf("nanti ya\n");
                Askill(P1) = true;
                Aend(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                UndoAll (&Arr, &SBang, &P1, &P2, &SP1, &SP2, P1);
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Move(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, ArrGraph, P1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "HELP") == 0){
                HELP();
            }
            
            else{
                printf("Input Salah, jalankan command HELP untuk bantuan\n");
            }
            
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            FAkhir = JFort(Jumlah2);
            TambahSkill(Jumlah1, Jumlah2, FAwal, FAkhir, Kondisi, &P1, &P2);
            printf("\nPress Enter to Continue...");
            INPUTENTER();
            clear;              //untuk clear console di ubuntu
            //system("CLS");    //untuk clear console di windows
        } 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //PLAYER 2
        //Art2();
        UpdateBangunan (P2.ListB, &Arr);
        while ((playing) && !(P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah2, Jumlah1, &Kondisi);
            FAwal = JFort(Jumlah1);

            CetakAwal(N,M,Arr, P1, P2, P2, 2, &T1); 
            STARTWORD();
            if (strcmp(CWord.TabKata, "EXIT") == 0){
                playing = false;
            }

            else if (strcmp(CWord.TabKata, "END_TURN") == 0){
                printf("Anda Berhasil Mengakhiri Turn Ini\n");
                P1turn = true;
                Aend(P1) = true;
                Askill(P2) = false;
            }

            else if (strcmp(CWord.TabKata, "ATTACK") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Attack(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 2, &ada, ArrGraph, P2);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (strcmp(CWord.TabKata, "LEVEL_UP") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                LevelUpUp(&Arr, P2, &X, &T1);
                Aend(P2) = false;
                Askill(P2) = false;
            }

            else if (strcmp(CWord.TabKata, "SKILL") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                printf("nanti ya\n");
                Askill(P2) = true;
                Aend(P2) = false;
            }

            else if (strcmp(CWord.TabKata, "UNDO") == 0){
                UndoAll (&Arr, &SBang, &P1, &P2, &SP1, &SP2, P2);
            }

            else if (strcmp(CWord.TabKata, "MOVE") == 0){
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Move(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 2, &ada, ArrGraph, P2);
                Aend(P2) = false;
                Askill(P2) = false;
            }
            else if (strcmp(CWord.TabKata, "HELP") == 0){
                HELP();
            }
            else{
                printf("Input Salah, jalankan command HELP untuk bantuan\n");
            }

            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            FAkhir = JFort(Jumlah1);
            TambahSkill(Jumlah2, Jumlah1, FAwal, FAkhir, Kondisi, &P2, &P1);
            printf("\nPress Enter to Continue...");
            INPUTENTER();
            clear;              //untuk clear console di ubuntu
            //system("CLS");    //untuk clear console di windows
        } 

    } 
	return 0;
}