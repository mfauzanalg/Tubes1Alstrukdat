#include "olahfile.h"
#include "typebentukan.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levelup.h"

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
    PLAYER P1, P2;      //Pemain 
    addresslist P;

    LoadFile (&N, &M, &J, &Arr, &ArrGraph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    playing = true;
    P1turn = true;

    while (playing){
        CetakPeta(N,M,Arr);
        while ((playing) && (P1turn)){
            printf("PLayer 1\n");
            DaftarBangunan(P1.ListB, Arr);
            STARTWORD();
            if (strcmp(CWord.TabKata, "EXIT") == 0){
                playing = false;
            }
            else if (strcmp(CWord.TabKata, "END_TURN") == 0){
                P1turn = false;
            }
        } 
        system("CLS");

        CetakPeta(N,M,Arr);
        while ((playing) && !(P1turn)){
            printf("PLayer 2\n");
            DaftarBangunan(P2.ListB, Arr);
            STARTWORD();
            if (strcmp(CWord.TabKata, "EXIT") == 0){
                playing = false;
            }
            else if (strcmp(CWord.TabKata, "END_TURN") == 0){
                P1turn = true;
            }
        }
        system("CLS");

    } 
	return 0;
}