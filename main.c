#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "olahfile/olahfile.h"
#include "command/command.h"
#include "save/coba_save.h"

int main(){
    //KAMUS
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
    Stack SBang;                
    // Sbang Untuk menyimpan data bangunan yang di push
    stackp SP1, SP2;            
    // SP1 Stack menyimpan data player 1 yang di push
    // SP2 Stack menyimpan data player 2 yang di push
    MATRIKS Mat;
    // Mat untuk menyimpan data matriks 
    PLAYER P1, P2, P3;          
    // P1 menyimpan data Player 1
    // P2 menyimpan data Player 2
    // P3 sebagai wadah sekunder PLAYER sebelum di push
    JumlahB Jumlah1, Jumlah2;   
    // Jumlah 1 menampung jumlah bangunan player 1
    // Jumlah 2 menampung jumlah bangunan player 2
    TabInt T1, T2;              
    // T1 untuk menampung bangunan yang dapat dipilih saat level up/move/battle
    // T2 untuk menampung bangunan yang dapat dipilih saat level up/move/battle
    List Tetangga;
    // Tetangga list yang berisi tettangga dari suatu bangunan                 
    Condition Kondisi;
    // Pengecekan apakah ada kemungkinan bertambah skillnya atau tidak

    // ALGORITMA
    // Inisialisasi awal data-data
    LoadFile (&N, &M, &J, &Arr, &Graph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    Playing = true;
    P1turn = true;
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyStack(&SBang);
    Aend(P1) = true;
    menuAwal();
    HELP();
    while (Playing){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //PLAYER 1
        Art1();
        printf("\nPlayer 1, sekarang giliran Anda!\n");
        printf("Apakah Anda siap untuk menaklukkan dunia?\n");
        UpdateBangunan (&P1, &P2, &P1turn, &Arr);
        while ((Playing) && (P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah1, Jumlah2, &Kondisi);
            FAwal = JFort(Jumlah2);
            TAwal = JTower(Jumlah2);
            CetakAwal(N,M,Arr, P1, P2, P1, P2, 1, &T1);                     // Mencetak peta daninformasi lainnya
            STARTWORD();                                                    // Input command dari user
    
            if (CompareTwoStrings(CWord.TabKata, "EXIT") == 0){                        // EXIT
                Playing = false;
                exitGame();
            }

            else if (CompareTwoStrings(CWord.TabKata, "END_TURN") == 0){ //sudah jalan
                printf("Anda berhasil mengakhiri turn ini\n");
                printf("Player 2, ayo bersiap!\n");
                P1turn = false;
                Aend(P2) = true;
                Askill(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "ATTACK") == 0){                 // ATTACK
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                printf("\n");
                Attack(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, Graph, &P1, &P2);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "LEVEL_UP") == 0){               // LEVEL_UP
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                LevelUpUp(&Arr, P1, &X, &T1, 1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "SKILL") == 0){                  // SKILL
                UseSkill(&P1.Skill, &P1, &P2, &Arr, &P1.IsET);
                Askill(P1) = true;
                Aend(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "UNDO") == 0){                   // UNDO
                UndoAll (&Arr, &SBang, &P1, &P2, &SP1, &SP2, P1);
            }

            else if (CompareTwoStrings(CWord.TabKata, "MOVE") == 0){                   // MOVE
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Move(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, Graph, P1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "HELP") == 0){                   // HELP
                HELP();
            }
            
            else{                                                           // Jika input salah
                printf("Input Salah, jalankan command HELP untuk bantuan\n");
            }
            
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisiAkhir(Jumlah1, Jumlah2, FAwal, TAwal, Kondisi, &P1, &P2, Arr, J, P1turn);
            printf("\n<Tekan ENTER untuk melanjutkan permainan>");
            INPUTENTER();
        } 

        //PLAYER 2
        Art2();
        printf("\nPlayer 2, sekarang giliran Anda!\n");
        printf("Apakah Anda siap untuk menaklukkan dunia?\n");
        UpdateBangunan (&P2, &P1, &P1turn, &Arr);
        while ((Playing) && !(P1turn)){
            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisi (Jumlah2, Jumlah1, &Kondisi);                        // Mencetak peta daninformasi lainnya
            FAwal = JFort(Jumlah1);
            TAwal = JTower(Jumlah1);

            CetakAwal(N,M,Arr, P1, P2, P2, P1, 2, &T1); 
            STARTWORD();                                                    // Input command dari user
            if (CompareTwoStrings(CWord.TabKata, "EXIT") == 0){                        // EXIT
                Playing = false;
                exitGame();
            }

            else if(CompareTwoStrings(CWord.TabKata, "SAVE") == 0){
                SaveAll(SBang,SP1,SP2,Playing,P1turn);
            }

            else if (CompareTwoStrings(CWord.TabKata, "END_TURN") == 0){
                printf("Anda berhasil mengakhiri turn ini\n");
                printf("Player 1, ayo bersiap!\n");
                P1turn = true;
                Aend(P1) = true;
                Askill(P2) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "ATTACK") == 0){                 // ATTACK
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Attack(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 2, &ada, Graph, &P2, &P1);
                Aend(P1) = false;
                Askill(P1) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "LEVEL_UP") == 0){                // LEVEL_UP
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                LevelUpUp(&Arr, P2, &X, &T1, 1);
                Aend(P2) = false;
                Askill(P2) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "SKILL") == 0){                   // SKILL
                UseSkill(&P2.Skill, &P2, &P1, &Arr, &P2.IsET);;
                Askill(P2) = true;
                Aend(P2) = false;
            }

            else if (CompareTwoStrings(CWord.TabKata, "UNDO") == 0){                   // UNDO
                UndoAll (&Arr, &SBang, &P1, &P2, &SP1, &SP2, P2);
                printf("Anda Berhasil Meng-Undo Command Terakhir");
            }

            else if (CompareTwoStrings(CWord.TabKata, "MOVE") == 0){                   // MOVE
                PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
                Move(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 2, &ada, Graph, P2);
                Aend(P2) = false;
                Askill(P2) = false;
            }
            else if (CompareTwoStrings(CWord.TabKata, "HELP") == 0){                   // HELP
                HELP();
            }
            else{
                printf("Input Salah, jalankan command HELP untuk bantuan\n");
            }

            HitungJum (&Jumlah1, P1, Arr);
            HitungJum (&Jumlah2, P2, Arr);
            CekKondisiAkhir(Jumlah2, Jumlah1, FAwal, TAwal, Kondisi, &P2, &P1, Arr, J, P1turn);
            printf("\n<Tekan ENTER untuk melanjutkan permainan>");
            INPUTENTER();
        }
    } 
	return 0;
}