#include <stdio.h>
#include <stdlib.h>
#include "olahfile.h"

int main(){
    // KAMUS

    int N, M, J, X, Y, FAwal, TAwal;
    // N adalah tinggi peta
    // M adalah lebar peta
    // J adalah jumlah bangunan dalam peta
    // X dan Y digunakan untuk memilih bangunan
    // FAwal adalah jumlah Fort lawan di awal  
    // TAwal adalah jumlah Tower lawan di awal          		            
    boolean Playing, P1turn, ada;
    // P1turn untuk menentukan turn siapa yang bermain
    // Playing untuk menentukan apakah masih bermain atau tidak
    // ada untuk mengecek ada/tidaknya bangunan target saat move/attack
    TabBang Arr, Arr2; 	        
    // Arr untuk menyimpang data-data bangunan
    // Arr2 sebagai wadah sekunder TabBang sebelum di push
    GraphList Graph;            
    // Graph Untuk merepresentasikan keterhubungan antar bangunan
    MATRIKS Mat;
    // Mat untuk menyimpan data matriks 
    PLAYER P1, P2;         
    // P1 menyimpan data Player 1
    // P2 menyimpan data Player 2
    TabInt T1, T2;              
    // T1 untuk menampung bangunan yang dapat dipilih saat level up/move/battle
    // T2 untuk menampung bangunan yang dapat dipilih saat level up/move/battle
    List Tetangga;
    // Tetangga list yang berisi tettangga dari suatu bangunan                 
    addresslist P;

    printf("Load file bernama pitakar.txt\n");
    LoadFile (&N, &M, &J, &Arr, &Graph, &Mat, &P1.ListB, &P2.ListB);
    P = Alokasi(4);
	InsertFirst(&P2.ListB, P);
    P = Alokasi(8);
	InsertFirst(&P2.ListB, P);
    Elmt(Arr,4).jum = 0;
	Elmt(Arr,8).jum = 0;

    printf("Konfigurasi peta sesuai dengan file pitakar.txt\n");
    CetakPeta(N,M,Arr,P1,P2);

    printf("Player 1 :\n");
    DaftarBangunan(P1.ListB, Arr, &T1);

    printf("Player 2 :\n");
    DaftarBangunan(P2.ListB, Arr, &T1);

    printf("\n<Tekan ENTER untuk melanjutkan pengecekan prosedur AdaSerang dan Daftarserang>");
    INPUTENTER();

    printf("Apakah Bangunan Castle (10,1) Memiliki bangunan yang dapat diserang?\n");
    Tetangga = Neighbors(Graph, 1); 
    AdaSerang (Tetangga, Arr, 1, &ada,P1,P2);
    if(ada){
        printf("Ada\n\n");
        DaftarSerang(Tetangga, Arr, &T2, 1, P1, P2);
        printf("\n");
    }
    else{
        printf("Tidak ada\n\n");
    }

    printf("Apakah Bangunan Castle (1,15) Memiliki bangunan yang dapat diserang?\n");
    Tetangga = Neighbors(Graph, 2); 
    AdaSerang (Tetangga, Arr, 2, &ada,P1,P2);
    if(ada){
        printf("Ada\n\n");
        DaftarSerang(Tetangga, Arr, &T2, 2, P1, P2);
        printf("\n");
    }
    else{
        printf("Tidak ada\n\n");
    }

    printf("\n<Tekan ENTER untuk melanjutkan pengecekan prosedur AdaMove dan DaftarMove>");
    INPUTENTER();

    printf("Apakah Bangunan Castle (10,1) memiliki tujuan pemindahan pasukan?\n");
    Tetangga = Neighbors(Graph, 1); 
    AdaMove (Tetangga, Arr, 1, &ada,P1,P2);
    if(ada){
        printf("Ada\n\n");
        DaftarMove(Tetangga, Arr, &T2, 1, P1, P2);
    }
    else{
        printf("Tidak ada\n\n");
    }

    printf("Apakah Bangunan Castle (1,15) memiliki tujuan pemindahan pasukan?\n");
    Tetangga = Neighbors(Graph, 2); 
    AdaMove (Tetangga, Arr, 2, &ada,P1,P2);
    if(ada){
        printf("Ada\n\n");
        DaftarMove(Tetangga, Arr, &T2, 2, P1, P2);
    }
    else{
        printf("Tidak ada\n\n");
    }

    printf("\n<Tekan ENTER untuk melanjutkan pengecekan prosedur StartPlayer>");
    INPUTENTER();
    
    printf("Untuk player 1\n");
    StartPlayer(&P1);
    printf("Apakah skill player kosong? ");
    if(IsEmptyQueue(P1.Skill)){
        printf("iya\n");
    }
    else{
        printf("tidak\n");
    }

    printf("Apakah shield player aktif? ");
    if (IsShield(P1)){
        printf("aktif\n");
    }
    else{
        printf("tidak aktif\n");
    }

    printf("Apakah Attack Up player aktif? ");
    if (IsAttackUp(P1)){
        printf("aktif\n");
    }
    else{
        printf("tidak aktif\n");
    }

    printf("Apakah Critical Hit player aktif? ");
    if (IsCriticalHit(P1)){
        printf("aktif\n");
    }
    else{
        printf("tidak aktif\n");
    }

    printf("Apakah player baru saja menggunakan skill? ");
    if (Askill(P1)){
        printf("ya\n");
    }
    else{
        printf("tidak\n");
    }

    printf("Apakah Player baru saja memulai permainan? ");
    if (Aend(P1)){
        printf("ya\n");
    }
    else{
        printf("tidak\n");
    }

    printf("Apakah player baru saja menggunakan skill Extra Turn? ");
    if (P1.IsET){
        printf("ya\n");
    }
    else{
        printf("tidak\n");
    }

    printf("Berapa turn lagi player memiliki shield aktif, jika 0 berarti tidak memiliki shield? %d\n\n", P1.CountShield);

    printf("<Tekan ENTER untuk melanjutkan pengecekan prosedur cetak skill>");
    INPUTENTER();

    printf("input angka 1-7 : ");
    STARTWORD();
    X = WStringToInteger(CWord);
    printf("Skill sesuai input angka adalah : "); CetakSkill(X);
    printf("\n\n");

    printf("<Tekan ENTER untuk melanjutkan pengecekan fungsi owner>");
    INPUTENTER();    

    for (X = 1; X <= 3; X++){
        printf("Bangunan berindeks %d, adalah milik player %d\n", X, owner(X, P1.ListB, P2.ListB));
    }
    printf("\n");
}