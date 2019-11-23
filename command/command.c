#include <string.h>
#include "command.h"


void Art1(){
    // Untuk menampilkan Ascii Art player 1
    printf(ANSI_COLOR_RED "       _                         __\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "      | |                       /_ |\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED " _ __ | | __ _ _   _  ___ _ __   | |\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "| '_ \\| |/ _` | | | |/ _ \\ '__|  | |\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "| |_) | | (_| | |_| |  __/ |     | |\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "| .__/|_|\\__,_|\\__, |\\___|_|     |_|\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "| |             __/ |\n" ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED "|_|            |___/\n\n" ANSI_COLOR_RESET);                
}

void Art2(){
    // Untuk menampilkan Ascii Art player 2
    printf(ANSI_COLOR_GREEN"       _                         ___\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"      | |                       |__ \\\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN" _ __ | | __ _ _   _  ___ _ __     ) |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"| '_ \\| |/ _` | | | |/ _ \\ '__|   / /\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"| |_) | | (_| | |_| |  __/ |     / /_\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"| .__/|_|\\__,_|\\__, |\\___|_|    |____|\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"| |             __/ |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"|_|            |___/\n\n"ANSI_COLOR_RESET);
}

void menuAwal(){
    printf("\n");
    printf("   #    #     #    #    #######    #    ######     #     # ####### ######  #       ######     #     #    #    ######  \n");
    printf("  # #   #     #   # #      #      # #   #     #    #  #  # #     # #     # #       #     #    #  #  #   # #   #     # \n");
    printf(" #   #  #     #  #   #     #     #   #  #     #    #  #  # #     # #     # #       #     #    #  #  #  #   #  #     # \n");
    printf("#     # #     # #     #    #    #     # ######     #  #  # #     # ######  #       #     #    #  #  # #     # ######  \n");
    printf("#######  #   #  #######    #    ####### #   #      #  #  # #     # #   #   #       #     #    #  #  # ####### #   #   \n");
    printf("#     #   # #   #     #    #    #     # #    #     #  #  # #     # #    #  #       #     #    #  #  # #     # #    #  \n");
    printf("#     #    #    #     #    #    #     # #     #     ## ##  ####### #     # ####### ######      ## ##  #     # #     # \n\n\n");
    printf("Selamat datang di Dunia Avatar!\n\n");
    printf("Saat avatar Aang belum muncul, dunia menjadi kacau dan terjadi perang dunia. Perang ini diikuti oleh 4 negara - API, AIR, \n");
    printf("TANAH, dan UDARA. Pada mulanya, keempat negara berada di keempat penjuru dunia. Mereka memiliki pasukan masing-masing dan \n");
    printf("jumlahnya terus bertambah. Tiap negara dapat bergerak dan menduduki sebuah kota. Untuk menduduki sebuah kota, sebuah negara\n");
    printf("harus menyerang dengan pasukan lebih banyak dari penghuni kota tersebut. Ketika sebuah kota diduduki, kota tersebut akan \n");
    printf("menghasilkan pasukan untuk negara yang berhasil mendudukinya. Pemenangnya adalah negara yang berhasil menduduki seluruh kota.\n\n");
    printf("Permainan ini dapat dimainkan oleh dua orang pemain. Di awal permainan, pemain 1 akan diberikan 2 buah bangunan,\n");                                                                               
    printf("sedangkan pemain kedua akan diberikan 1 buah bangunan. Dalam peta, bangunan milik pemain 1 berwarna merah, sedangkan pemain\n");
    printf("dua berwarna hijau\n\n");

    printf("Ayo mulai permainan! Apakah Anda siap untuk menguasai keempat negara?\n ");
    printf("<Tekan ENTER untuk melanjutkan permainan>");
    INPUTENTER();
void ArtWin(){
    // Untuk menampilkan Ascii Art Win
	printf(ANSI_COLOR_CYAN"           _\n" ANSI_COLOR_RESET);       
	printf(ANSI_COLOR_CYAN"          (_)\n" ANSI_COLOR_RESET);      
	printf(ANSI_COLOR_CYAN" __      ___\\ _ __\n" ANSI_COLOR_RESET);  
	printf(ANSI_COLOR_CYAN" \\ \\ /\\ / / | '_ \\\n" ANSI_COLOR_RESET); 
	printf(ANSI_COLOR_CYAN"  \\ V  V /| | | | |\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN"   \\_/\\_/ |_|_| |_|\n" ANSI_COLOR_RESET);
                  
}

void HELP(){
    // Untuk menampilkan command apa saja yang dapat dilakukan pada program
    printf("\n");
    printf("Daftar Command yang dapat dilakukan : \n");
    printf("1. ATTACK      - menyerang bangunan milik lawan dengan mengirim pasukan yang dimiliki\n");
    printf("2. LEVEL_UP    - menaikkan level suatu bangunan \n");
    printf("3. SKILL       - memakai skill yang dimiliki pemain\n");
    printf("4. UNDO        - membatalkan perintah terakhir\n");
    printf("5. END_TURN    - mengakhiri giliran pemain\n");
    printf("6. MOVE        - memindahkan pasukan ke bangunan lain\n");
    printf("7. EXIT        - keluar dari permainan\n");
    printf("8. SAVE (Mungkin)\n\n");
    printf("<Tekan ENTER untuk melanjutkan permainan>");
    INPUTENTER();

}

void CetakAwal (int N, int M, TabBang Arr, PLAYER P1, PLAYER P2, PLAYER P3, PLAYER P4, int Curr, TabInt *T1){
    // Cetak awal saat player baru dimulai
    // Cetak Player berapa
    // Cetak Daftar bangunan yang dimiliki oleh player
    // Cetak status skill
    CetakPeta(N,M,Arr,P1,P2);
<<<<<<< HEAD
    printf("\n");
=======
>>>>>>> e88b21dba303b6ae31fcc8b128d0413737447169
    printf("Player %d\n", Curr);
    DaftarBangunan(P3.ListB, Arr, &*T1);

    printf("Ini adalah skill sedang diaktifkan!\n");
    printf("Shield Lawan : "); if (P4.IsShield) printf("Aktif, sisa %d turn\n", P4.CountShield); else printf("Tidak aktif\n");
    printf("Critical Hit : "); if (P3.IsCriticalHit) printf("Aktif\n"); else printf("Tidak aktif\n");
    printf("Attack Up    : "); if (P3.IsAttackUp) printf("Aktif\n\n"); else printf("Tidak aktif\n\n");

    printf("Banyaknya skill yang dimiliki player : %d\n", NBElmtQueue(P3.Skill));
    printf("Skill yang tersedia : "); 
    CetakSkill(InfoHead(P3.Skill));
    printf("\n");
    printf("ENTER COMMAND : ");
}

void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P1, PLAYER P2, PLAYER *Pcop, stackp *SPlayer1, stackp *SPlayer2){
    // Push Array ke Stack Array, Push Player ke Stack Player
    CopyArr(Arr, &*Arrcop);
    Push(&*SBang, *Arrcop);

    CopyPlayer(P1, &*Pcop);
    Pushp(&*SPlayer1, *Pcop);

    CopyPlayer(P2, &*Pcop);
    Pushp(&*SPlayer2, *Pcop);
}

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P1, PLAYER *P2, stackp *SPlayer1, stackp *SPlayer2, PLAYER P3){
    // Undo Command Terakhir dengan cara pop stack of array dan stack of player
    // Berhasil jika command terakhir bukan Skill atau End Turn
    if (Aend(P3)){
        printf("Anda baru saja memulai permainan, tidak bisa UNDO\n");
    }
    else if (Askill(P3)){
        printf("Anda baru saja menggunakan skill, tidak bisa UNDO\n");
    }
    else{            
        Pop (&*SBang, &*Arr);
        Popp (&*SPlayer1, &*P1);
        Popp (&*SPlayer2, &*P2);
        printf("Anda Berhasil Meng-Undo Command Terakhir\n");
    }
}

void HitungJum (JumlahB *Jumlah, PLAYER P1, TabBang Arr){
    // Menghitung jumlah bangunan yang dimiliki oleh pemain dan memasukannya ke dalam Jumlah
    addresslist P;
    int i;
    boolean found;
    JCastle(*Jumlah) = 0;
    JTower(*Jumlah) = 0;
    JVillage(*Jumlah) = 0;
    JFort(*Jumlah) = 0;
    JTotal(*Jumlah) = 0;

    P = First(P1.ListB);
    while (P != NilList){
        i = 1;
        found = false;
        while (i <= NbElmtArr(Arr) && !(found)){
            if (Info(P) == i){                  //Jika Info(P) == indeks dari bangunan 
                if(Elmt(Arr,i).type == 'C'){
                    JCastle(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'T'){
                    JTower(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'V'){
                    JVillage(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'F'){
                    JFort(*Jumlah)++;
				}
				found = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
    }
    JTotal(*Jumlah) = JCastle(*Jumlah) + JFort(*Jumlah) + JVillage(*Jumlah) + JTower(*Jumlah);
}

void CekKondisi (JumlahB jumlahku, JumlahB jumlahlawan, Condition *Kondisi){
    // Untuk mengecek kondisi penambahan skill
    // Apakah berotensi untuk mendapat penambahan skill di akhir command
    (*Kondisi).AU = false;
    (*Kondisi).S = false;
    (*Kondisi).B = false;
    (*Kondisi).ET = true;
    
    if (JTotal(jumlahlawan) == 3){
        (*Kondisi).S = true;
    }
    else if (JTower(jumlahlawan) == 4){
        (*Kondisi).AU = true;
    }
    else if (JTotal(jumlahku) == 9){
        (*Kondisi).B = true;
    }
}

void Attack(TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER *P3, PLAYER *P4){
    // Untuk melakukan command attack

    addresslist A;
    int Z; //Jumlah Kita
    int Tujuan; //Jumlah lawan
    int Hasil;
    DaftarBangunan((*P3).ListB, *Arr, &*T1);
    printf("Pilih bangunan untuk menyerang : ");
    do{                                                                   //Validasi pemilihan bangunan milik player
        STARTWORD();
        *X = WStringToInteger(CWord);
        if (*X > Neff(*T1) || *X <= 0){
            printf("Pilihan tidak sesuai, silakan ulangi input\n");
            printf("Pilih bangunan untuk menyerang : ");
        }
    }while(*X > Neff(*T1) || *X <= 0);

    if (Elmt(*Arr,ElmtStat(*T1,*X)).attack){
        *Tetangga = Neighbors(Graph, ElmtStat(*T1,*X));
        AdaSerang (*Tetangga, *Arr, 1, &*ada,P1,P2);
        if (ada){
            Elmt(*Arr,ElmtStat(*T1,*X)).attack = false;
            DaftarSerang(*Tetangga, *Arr, &*T2, P, P1, P2);
            printf("\nPilih bangunan yang ingin diserang : ");

            do{                                                         //Validasi pilihan bangunan target
                STARTWORD();
                *Y = WStringToInteger(CWord);
                if (*Y > Neff(*T2) || *Y <= 0){
                    printf("Pilihan tidak sesuai, silakan ulangi input\n");
                    printf("Pilih bangunan yang ingin diserang : ");
                }
            }while(*Y > Neff(*T2) || *Y <= 0);

            printf("Jumlah pasukan yang tersedia : %d\n", Elmt(*Arr,ElmtStat(*T1,*X)).jum);
            printf("Masukan jumlah pasukan yang ingin digunakan untuk menyerang : ");
            do{                                                         //Validasi jumlah masukan pasukan
                STARTWORD();
                Z = WStringToInteger(CWord);
                if  (Z > Elmt(*Arr,ElmtStat(*T1,*X)).jum || Z < 0){
                    printf("Jumlah tidak sesuai dengan pasukan yang tersedia\n");
                    printf("Masukan jumlah pasukan yang ingin digunakan untuk menyerang : ");
                }
            }while (Z > Elmt(*Arr,ElmtStat(*T1,*X)).jum || Z < 0);

            // Z itu jumlah penyerang
            // Bangunan asal nya dikurangin sama Z dulu
            Elmt(*Arr,ElmtStat(*T1,*X)).jum -= Z;
            Tujuan = Elmt(*Arr,ElmtStat(*T2,*Y)).jum;
            printf("\n");
            //Mulai penyerangan
            if((*P3).IsCriticalHit){            //Jika critical hit aktif
                Z *= 2;
                Tujuan -= Z;
                if (Tujuan <= 0){               //Berpindah kepemilikan
                    printf("Bangunan menjadi milikmu!!!\n");
                    Tujuan *= (0.5);
                    A = Alokasi(ElmtStat(*T2,*Y));
                    DelP(&((*P4)).ListB, ElmtStat(*T2,*Y));
                    InsertFirst(&((*P3)).ListB, A);
                    Tujuan *= -1;
                    printf("Jumlah pasukan di bangunan baru : %d\n", Tujuan);
                    KeLevel1(&(Elmt(*Arr,ElmtStat(*T2,*Y))));
                }
                else{
                    printf("Bangunan gagal di rebut\n");
                    printf("Sisa pasukan di bangunan target : %d\n", Tujuan);
                }
            }
            else{                               //Jika critical hit tidak aktif
                if((*P3).IsAttackUp){           //Jika AttackUp Aktif
                    Tujuan -= Z;
                    if (Tujuan <= 0){           //Berpindah kepemilikan
                    printf("Bangunan menjadi milikmu!!!\n");
                    A = Alokasi(ElmtStat(*T2,*Y));
                    DelP(&((*P4).ListB), ElmtStat(*T2,*Y));
                    InsertFirst(&((*P3)).ListB, A);
                    Tujuan *= -1;
                    printf("Jumlah pasukan di bangunan baru : %d\n", Tujuan);
                    KeLevel1(&(Elmt(*Arr,ElmtStat(*T2,*Y))));
                    }
                    else{                       //Tidak berpindah kepemilikan
                        printf("Bangunan gagal di rebut\n");
                        printf("Sisa pasukan di bangunan target : %d\n", Tujuan);
                    }
                }
                else{                           //Jika AttackUp tidak Aktif
                    if((*P4).IsShield){         //Jika lawan memiliki shield
                        Z *= (0.75);
                        Tujuan -= Z;
                        if (Tujuan <= 0){       //Berpindah kepemilikan
                            printf("Bangunan menjadi milikmu!!!\n");
                            A = Alokasi(ElmtStat(*T2,*Y));
                            DelP(&((*P4).ListB), ElmtStat(*T2,*Y));
                            InsertFirst(&((*P3)).ListB, A);
                            Tujuan = (Tujuan*4)/3*-1;
                            printf("Jumlah pasukan di bangunan baru : %d\n", Tujuan);
                            KeLevel1(&(Elmt(*Arr,ElmtStat(*T2,*Y))));
                        }
                        else{                   //Tidak berpindah kepemilikan
                            printf("Bangunan gagal di rebut\n");
                            printf("Sisa pasukan di bangunan target : %d\n", Tujuan);
                        }
                    }
                    else{                       //Jika lawan tidak memiliki shield
                        if(Elmt(*Arr,ElmtStat(*T2,*Y)).P){  //Jika lawan memiliki pertahanan
                            Z *= (0.75);
                            Tujuan -= Z;
                            if (Tujuan <= 0){   //Berpindah kepemilikan
                                printf("Bangunan menjadi milikmu!!!\n");
                                A = Alokasi(ElmtStat(*T2,*Y));
                                DelP(&((*P4).ListB), ElmtStat(*T2,*Y));
                                InsertFirst(&((*P3)).ListB, A);
                                Tujuan = (Tujuan*4)/3*-1;
                                printf("Jumlah pasukan di bangunan baru : %d\n", Tujuan);
                                KeLevel1(&(Elmt(*Arr,ElmtStat(*T2,*Y))));
                            }
                            else{               //Tidak berpindah kepemilikan
                                printf("Bangunan gagal di rebut\n");
                                printf("Sisa pasukan di bangunan target : %d\n", Tujuan);
                            }
                        }
                        else{                        //Jika lawan tidak memiliki pertahanan
                            Tujuan -= Z;
                            if (Tujuan <= 0){       //Berpindah kepemilikan
                                printf("Bangunan menjadi milikmu!!!\n");
                                A = Alokasi(ElmtStat(*T2,*Y));
                                DelP(&((*P4).ListB), ElmtStat(*T2,*Y));
                                InsertFirst(&((*P3)).ListB, A);
                                Tujuan *= -1;
                                printf("Jumlah pasukan di bangunan baru : %d\n", Tujuan);
                                KeLevel1(&(Elmt(*Arr,ElmtStat(*T2,*Y))));
                            }
                            else{                   //Tidak berpindah kepemilikan
                                printf("Bangunan gagal di rebut\n");
                                printf("Sisa pasukan di bangunan target : %d\n", Tujuan);
                            }
                        }
                    }
                }
            }
            Elmt(*Arr,ElmtStat(*T2,*Y)).attack = true;
            Elmt(*Arr,ElmtStat(*T2,*Y)).jum = Tujuan;
            (*P3).IsCriticalHit = false;
        }
        else {  //Jika Bangunan tidak memiliki tujuan penyerangan
            printf("Tidak ada bangunan yang dapat diserang\n");
        }
    }
    else{   //Jika bangunan sudah menyerang pada turn ini
        printf("Bangunan sudah menyerang pada turn ini\n");
    }
}

void KeLevel1(Bangunan *Bang){
    // Untuk mengembalikan bangunan yang berhasil di rebut ke level 1
    (*Bang).lev = 1;
    if ((*Bang).type == 'C'){
        (*Bang).A = 10;
        (*Bang).M = 40;
        (*Bang).P = false;
    }
    else if ((*Bang).type == 'T'){
        (*Bang).A = 5;
        (*Bang).M = 20;
        (*Bang).P = true;
    }
    else if ((*Bang).type == 'F'){
        (*Bang).A = 10;
        (*Bang).M = 20;
        (*Bang).P = false;
    }
    else if ((*Bang).type == 'V'){
        (*Bang).A = 5;
        (*Bang).M = 20;
        (*Bang).P = true;
    }
}

void Move (TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER P3){
    // Memindahkan pasukan dari bangunan ke bangunan lain yang masih milik player
    int Z;
    char Bang1[10];
    char Bang2[10];

    DaftarBangunan(P3.ListB, *Arr, &*T1);
    printf("Pilih bangunan asal pemindahan : ");
    do{                                                 //Validasi pemilihan bangunan
        STARTWORD();
        *X = WStringToInteger(CWord);
        if (*X > Neff(*T1) || *X <= 0){
            printf("Pilihan tidak sesuai, silakan ulangi input\n");
            printf("Pilih bangunan asal pemindahan : ");
        }
    }while(*X > Neff(*T1) || *X <= 0);

    *X = WStringToInteger(CWord);
    
    if (Elmt(*Arr,ElmtStat(*T1,*X)).move){
            *Tetangga = Neighbors(Graph, ElmtStat(*T1,*X));
            AdaMove (*Tetangga, *Arr, P, &*ada, P1, P2);
            if (*ada){
                Elmt(*Arr,ElmtStat(*T1,*X)).move = false;
                DaftarMove(*Tetangga, *Arr, &*T2, P, P1, P2);
                printf("Pilih bangunan tujuan pemindahan : ");
                do{                                     //Validasi pemilihan bangunan target
                    STARTWORD();
                    *Y = WStringToInteger(CWord);
                    if (*Y > Neff(*T2) || *Y <= 0){
                        printf("Pilihan tidak sesuai, silakan ulangi input\n");
                        printf("Pilih bangunan tujuan pemindahan : ");
                    }
                }while(*Y > Neff(*T2) || *Y <= 0);
                printf("Jumlah pasukan yang tersedia : %d\n", Elmt(*Arr,ElmtStat(*T1,*X)).jum);
                printf("Masukan jumlah pasukan yang ingin dipindahkan : ");
                do{                                     // Validasi jumlah pasukan yang dipilih
                    STARTWORD();        
                    Z = WStringToInteger(CWord);
                    if  (Z > Elmt(*Arr,ElmtStat(*T1,*X)).jum){
                        printf("Jumlah tidak sesuai dengan pasukan yang tersedia\n");
                        printf("Masukan jumlah pasukan yang ingin dipindahkan : ");
                    }
                }while (Z > Elmt(*Arr,ElmtStat(*T1,*X)).jum);

                //Mengubah jumlah Pasukan
                if(Elmt(*Arr,ElmtStat(*T1,*X)).type == 'C'){
                    char Bang3[10] = "Castle";
                    strcpy(Bang1, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T1,*X)).type == 'T'){
                    char Bang3[10] = "Tower";
                    strcpy(Bang1, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T1,*X)).type == 'F'){
                    char Bang3[10] = "Fort";
                    strcpy(Bang1, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T1,*X)).type == 'V'){
                    char Bang3[10] = "Village";
                    strcpy(Bang1, Bang3);
                }
                if(Elmt(*Arr,ElmtStat(*T2,*Y)).type == 'C'){
                    char Bang3[10] = "Castle";
                    strcpy(Bang2, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T2,*Y)).type == 'T'){
                    char Bang3[10] = "Tower";
                    strcpy(Bang2, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T2,*Y)).type == 'F'){
                    char Bang3[10] = "Fort";
                    strcpy(Bang2, Bang3);
                }
                else if(Elmt(*Arr,ElmtStat(*T2,*Y)).type == 'V'){
                    char Bang3[10] = "Village";
                    strcpy(Bang2, Bang3);
                }

                Elmt(*Arr,ElmtStat(*T1,*X)).jum -= Z; //Bangunan Asal
                Elmt(*Arr,ElmtStat(*T2,*Y)).jum += Z; //Banguann Tujuan
            
                printf("%d pasukan dari %s (%d,%d) telah berpindah ke %s (%d,%d)\n", Z, Bang1, Elmt(*Arr,ElmtStat(*T1,*X)).letak.X, Elmt(*Arr,ElmtStat(*T1,*X)).letak.Y, Bang2, Elmt(*Arr,ElmtStat(*T2,*Y)).letak.X, Elmt(*Arr,ElmtStat(*T2,*Y)).letak.Y);
            }
            else {  //  Jika tidak ada bangunan milik player yang terhubung dengan bangunan yang dipilih
                printf("Tidak ada tujuan yang tersedia\n");
            }
        }
    else{   // Jika bangunan sudah memindahkan pasukan pada turn ini
        printf("Bangunan sudah memindahkan pasukan pada turn ini\n");
    }
}

void CekKondisiAkhir(JumlahB Jumlahku, JumlahB Jumlahlawan, int FAwal, Condition Kondisi, PLAYER *Paku, PLAYER *Plawan, TabBang Arr, int J, boolean P1Turn){
    // Mengecek kondisi yang mungkin terjadi di akhir command
    // Mengecek apakah akan terjadi penambahan skill
    // Mengecek apakah player 1/2 sudah memenangkan permainan
    boolean stop = false;
    addresslist PP = First((*Paku).ListB);

    if (Kondisi.S){ // Menambahkan skill shield
        if (JTotal(Jumlahlawan) == 2){
            AddQueue(&(*Plawan).Skill, 2);
        }
    }
    if (Kondisi.AU){ // Menambahkan skill Attack Up
        if (JTower(Jumlahlawan) == 3){
            AddQueue(&(*Paku).Skill, 4);
        }
    }
    if (Kondisi.B){ // Menambahkan skill barrage
        if (JTotal(Jumlahku) == 10){
            AddQueue(&(*Plawan).Skill, 7);
        }
    }
    if (JFort(Jumlahlawan) == FAwal-1){ // Menambahkan skill Exra Turn
        AddQueue(&(*Plawan).Skill, 3);
    }
    while (PP != NilList && !(stop)){ // Cek apakah semua bangunan level 4
        if (Elmt(Arr, Info(PP)).lev != 4){
            stop = true;
        }
        else{ 
            PP = Next(PP);
        }
    }
    if (PP == NilList){ // Jika semua bangunan level 4 maka menambahkan skill Instant Reinforcement
        AddQueue(&(*Paku).Skill, 6);
    }
    if (JTotal(Jumlahku) == J){ // Jika salah satu player sudah berhasil memiliki semua bangunan
        if(P1Turn){
            printf("Player 1 Menang\n");
            Art1();
            ArtWin();
            exit(0);
        }
        else{
            printf("Player 2 Menang\n");
            Art2();
            ArtWin();
            exit(0);
        }
    }
}

void LevelUpUp(TabBang *(Arr), PLAYER P, int *i, TabInt *T1, int IsCommand){
    // Untuk level Up bangunan yang sudah memenuhi kriteria
    // Dapat dilakukan melalui command (saat isCommand == 1)
    // Dapat diakses melalui skill Instant Upgrade

    if(IsCommand == 1){
        DaftarBangunan(P.ListB, *Arr, &*T1);
        printf("Bangunan yang akan di level up : ");
        STARTWORD();
        *i = WStringToInteger(CWord);
        *i = ElmtStat(*T1, *i);
    }
    
    
    MATRIKS MC, MT, MF, MV;
    CreateEmptyMatriks(4,4, &MC);
    CreateEmptyMatriks(4,4, &MT);
    CreateEmptyMatriks(4,4, &MF);
    CreateEmptyMatriks(4,4, &MV);

    //MC untuk castle
    ElmtMat(MC,1,1)=10;
    ElmtMat(MC,1,2)=40;
    ElmtMat(MC,1,3)=0;
    ElmtMat(MC,1,4)=40;

    ElmtMat(MC,2,1)=15;
    ElmtMat(MC,2,2)=60;
    ElmtMat(MC,2,3)=0;
    ElmtMat(MC,2,4)=0;

    ElmtMat(MC,3,1)=20;
    ElmtMat(MC,3,2)=80;
    ElmtMat(MC,3,3)=0;
    ElmtMat(MC,3,4)=0;

    ElmtMat(MC,4,1)=25;
    ElmtMat(MC,4,2)=100;
    ElmtMat(MC,4,3)=0;
    ElmtMat(MC,4,4)=0;

    //MT untuk tower
    ElmtMat(MT,1,1)=5;
    ElmtMat(MT,1,2)=20;
    ElmtMat(MT,1,3)=1;
    ElmtMat(MT,1,4)=30;

    ElmtMat(MT,2,1)=10;
    ElmtMat(MT,2,2)=30;
    ElmtMat(MT,2,3)=1;
    ElmtMat(MT,2,4)=0;

    ElmtMat(MT,3,1)=20;
    ElmtMat(MT,3,2)=40;
    ElmtMat(MT,3,3)=1;
    ElmtMat(MT,3,4)=0;

    ElmtMat(MT,4,1)=30;
    ElmtMat(MT,4,2)=50;
    ElmtMat(MT,4,3)=1;
    ElmtMat(MT,4,4)=0;

    //MF untuk fort
    ElmtMat(MF,1,1)=10;
    ElmtMat(MF,1,2)=20;
    ElmtMat(MF,1,3)=0;
    ElmtMat(MF,1,4)=80;

    ElmtMat(MF,2,1)=20;
    ElmtMat(MF,2,2)=40;
    ElmtMat(MF,2,3)=0;
    ElmtMat(MF,2,4)=0;

    ElmtMat(MF,3,1)=30;
    ElmtMat(MF,3,2)=60;
    ElmtMat(MF,3,3)=1;
    ElmtMat(MF,3,4)=0;

    ElmtMat(MF,4,1)=40;
    ElmtMat(MF,4,2)=80;
    ElmtMat(MF,4,3)=1;
    ElmtMat(MF,4,4)=0;

    //MV untuk village
    ElmtMat(MV,1,1)=5;
    ElmtMat(MV,1,2)=20;
    ElmtMat(MV,1,3)=0;
    ElmtMat(MV,1,4)=20;

    ElmtMat(MV,2,1)=10;
    ElmtMat(MV,2,2)=30;
    ElmtMat(MV,2,3)=0;
    ElmtMat(MV,2,4)=0;

    ElmtMat(MV,3,1)=15;
    ElmtMat(MV,3,2)=40;
    ElmtMat(MV,3,3)=0;
    ElmtMat(MV,3,4)=0;

    ElmtMat(MV,4,1)=20;
    ElmtMat(MV,4,2)=50;
    ElmtMat(MV,4,3)=0;
    ElmtMat(MV,4,4)=0;
    
    if (Elmt(*(Arr), *i).type == 'C'){
        if (IsCommand == 1){
            if(Elmt(*(Arr), *i).lev == 4){  // Jika sudah level 4 sudah mencapai level maksimal
                printf("Castle-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){ // Jika jumlah pasukan pada bangunan masih kurang untuk level up
                printf("Jumlah pasukan Castle kurang untuk level up\n");
            }
            else{
                Elmt(*(Arr), *i).jum=(Elmt(*(Arr), *i).jum)-(Elmt(*(Arr), *i).M)/2;
                Elmt(*(Arr), *i).lev++;
                Elmt(*(Arr), *i).A=ElmtMat(MC,Elmt(*(Arr), *i).lev,1);
                Elmt(*(Arr), *i).M=ElmtMat(MC,Elmt(*(Arr), *i).lev,2);
                Elmt(*(Arr), *i).P=ElmtMat(MC,Elmt(*(Arr), *i).lev,3);
                printf("Level Castle-mu meningkat menjadi %d!\n", Elmt(*(Arr), *i).lev);
            }
        }
        else if (Elmt(*(Arr), *i).lev < 4){ // Jika level up dilakukan melalui skill
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MC,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MC,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MC,Elmt(*(Arr), *i).lev,3);
        }
    }
    else if (Elmt(*(Arr), *i).type == 'T'){
        if(IsCommand == 1){
            if(Elmt(*(Arr), *i).lev == 4){ // Jika sudah level 4 sudah mencapai level maksimal
                printf("Tower-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){// Jika jumlah pasukan pada bangunan masih kurang untuk level up
                printf("Jumlah pasukan Tower kurang untuk level up\n");
            }
            else{
                Elmt(*(Arr), *i).jum=(Elmt(*(Arr), *i).jum)-(Elmt(*(Arr), *i).M)/2;
                Elmt(*(Arr), *i).lev++;
                Elmt(*(Arr), *i).A=ElmtMat(MT,Elmt(*(Arr), *i).lev,1);
                Elmt(*(Arr), *i).M=ElmtMat(MT,Elmt(*(Arr), *i).lev,2);
                Elmt(*(Arr), *i).P=ElmtMat(MT,Elmt(*(Arr), *i).lev,3);
                printf("Level Tower-mu meningkat menjadi %d!\n", Elmt(*(Arr), *i).lev);
            }
        }
        else if (Elmt(*(Arr), *i).lev < 4){ // Jika level up dilakukan melalui skill
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MT,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MT,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MT,Elmt(*(Arr), *i).lev,3);
        }
    }

    else if (Elmt(*(Arr), *i).type == 'F'){
        if(IsCommand == 1){
            if(Elmt(*(Arr), *i).lev == 4){ // Jika sudah level 4 sudah mencapai level maksimal
                printf("Fort-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){// Jika jumlah pasukan pada bangunan masih kurang untuk level up
                printf("Jumlah pasukan Fort kurang untuk level up\n");
            }
            else{
                Elmt(*(Arr), *i).jum=(Elmt(*(Arr), *i).jum)-(Elmt(*(Arr), *i).M)/2;
                Elmt(*(Arr), *i).lev++;
                Elmt(*(Arr), *i).A=ElmtMat(MF,Elmt(*(Arr), *i).lev,1);
                Elmt(*(Arr), *i).M=ElmtMat(MF,Elmt(*(Arr), *i).lev,2);
                Elmt(*(Arr), *i).P=ElmtMat(MF,Elmt(*(Arr), *i).lev,3);
                printf("Level Fort-mu meningkat menjadi %d!\n", Elmt(*(Arr), *i).lev);
            }
        }
        else if (Elmt(*(Arr), *i).lev < 4){ // Jika level up dilakukan melalui skill
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MF,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MF,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MF,Elmt(*(Arr), *i).lev,3);
        }
    }

    else{
        if(IsCommand== 1){
            if(Elmt(*(Arr), *i).lev == 4){ // Jika sudah level 4 sudah mencapai level maksimal
                printf("Village-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){
                printf("Jumlah pasukan Village kurang untuk level up\n");
            }
            else{
                Elmt(*(Arr), *i).jum=(Elmt(*(Arr), *i).jum)-(Elmt(*(Arr), *i).M)/2;
                Elmt(*(Arr), *i).lev++;
                Elmt(*(Arr), *i).A=ElmtMat(MF,Elmt(*(Arr), *i).lev,1);
                Elmt(*(Arr), *i).M=ElmtMat(MF,Elmt(*(Arr), *i).lev,2);
                Elmt(*(Arr), *i).P=ElmtMat(MF,Elmt(*(Arr), *i).lev,3);
                printf("Level Village-mu meningkat menjadi %d!\n", Elmt(*(Arr), *i).lev);
            }
        }
        else if (Elmt(*(Arr), *i).lev < 4){
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MF,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MF,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MF,Elmt(*(Arr), *i).lev,3);
        }
    }
}

void exitGame(){
    //Untuk keluar dari game
    exit(0);
}


void InstantUpgrade(PLAYER Pl, TabBang *Bang){
/*seluruh bangunan naik 1 level*/
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;
    TabInt Tab;

    //ALGORITMA
    //iterasi P
    P = First(ListB(Pl));

    while (P != NilList){                                       //akses daftar bangunan yang dimiliki player -> ListB(Pl)
        i = 1;
        stop = false;                                    
        while((i <= NbElmtArr(*Bang)) && !stop){                //mencari daftar bangunan yang dimiliki pemain dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){                                 //jika isi dari list bangunan yang dimiliki player = list bangunan dalam array of bangunan
                LevelUpUp(&(*Bang), Pl, &i, &Tab, 0);           //naik 1 level untuk semua bangunan
                stop = true;                                    //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                            //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki pemain
            }
        }
        P = Next(P);                                            //pindah ke bangunan selanjutnya milik player 
    }
}


// belum diperiksa
void Shield (PLAYER *Pl){
/* seluruh bangunan yang dimiliki oleh pemain akan memiliki shield selama 2 turn */
/* shield membuat jumlah pasukan yang dimiliki bertambah sebanyak 4/3 */
    (*Pl).IsShield = true;
    (*Pl).CountShield = 3;
}

void ExtraTurn (boolean *ET){
/* Setelah turn berakhir pemain mendapatkan turn lagi */
    //ALGORITMA
    *ET = true;
}

void AttackUp(PLAYER *Pl){
/* Setelah skill diaktifkan, pertahanan bangunan musuh​(termasuk Shield)​ tidak akan mempengaruhi penyerangan. */
    (*Pl).IsAttackUp = true;
}

void CriticalHit(PLAYER *Pl){
/* Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya ​(hanya berlaku 1 serangan) hanya efektif sebanyak 2 kali lipat pasukan​. ​Skill ini akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up. */
    //KAMUS LOKAL
    (*Pl).IsCriticalHit = true;
}

void InstantReinforcement(PLAYER Pl, TabBang *Bang){
/* Seluruh bangunan mendapatkan tambahan 5 pasukan */
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;

    //ALGORITMA
    //iterasi P
    P = First(ListB(Pl));
    i = 1;
    stop = false;

    while (P != NilList){                     //akses daftar bangunan yang dimiliki player -> ListB(Pl)
        i = 1;
        stop = false;
        while((i <= NbElmtArr(*Bang)) && !stop){     //mencari daftar bangunan yang dimiliki pemain dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){                       //jika isi dari list bangunan yang dimiliki player = list bangunan dalam array of bangunan
                Elmt(*Bang,i).jum += 5;              //semua bangunan jumlah pasukannya bertambah sebanyak 5
                stop = true;                        //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki pemain
            }
        }
        P = Next(P);                                //pindah ke bangunan selanjutnya milik player 
    }
}

void Barrage(PLAYER Enemy, TabBang *Bang){
/* Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10 pasukan. */
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;

    //ALGORITMA
    //iterasi P
    P = First(ListB(Enemy));
    i = 1;
    stop = false;

    while (P != NilList){                            //akses daftar bangunan yang dimiliki musuh -> ListB(Enemy)
        i = 1;
        stop = false;
        while((i <= NbElmtArr(*Bang)) && !stop){     //mencari daftar bangunan yang dimiliki musuh dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){    
                if(Elmt(*Bang,i).jum - 10 >=0){      //jika isi dari list bangunan yang dimiliki musuh = list bangunan dalam array of bangunan
                    Elmt(*Bang,i).jum -= 10;         //semua bangunan musuh jumlah pasukannya berkurang sebanyak 10
                }   
                else{
                    Elmt(*Bang,i).jum = 0;
                }         
                stop = true;                        //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki musuh
            }
        }
        P = Next(P);                                //pindah ke bangunan selanjutnya milik musuh
    }
}

void UseSkill(Queue *Skill, PLAYER *Pl, PLAYER *Enemy, TabBang *Bang, boolean *ET){
/* procedure yang dipanggil setelah command *Skill */
    infotypequeue Q;
    if (InfoHead(*Skill) == 1){
        InstantUpgrade(*Pl,&(*Bang));
        printf ("Anda berhasil menggunakan Skill Instant Upgrade!\n");
    } else if(InfoHead(*Skill) == 2){
        Shield(&(*Pl));
        printf ("Anda berhasil menggunakan Skill Shield!\n");
    } else if(InfoHead(*Skill) == 3){
        ExtraTurn(&(*ET));
        AddQueue(&(*Enemy).Skill, 5);
        printf ("Anda berhasil menggunakan SKill Extra Turn!\n");
    } else if(InfoHead(*Skill) == 4){
        AttackUp(&(*Pl));
        printf ("Anda berhasil menggunakan Skill Attack UP!\n");
    } else if(InfoHead(*Skill) == 5){
        CriticalHit(&(*Pl));
        printf ("Anda berhasil menggunakan Skill Critical Hit!\n");
    } else if(InfoHead(*Skill) == 6){
        InstantReinforcement((*Pl),&(*Bang));
        printf ("Anda berhasil menggunakan Skill Instant Reinforcement!\n");
    } else if(InfoHead(*Skill) == 7){
        Barrage(*Enemy, &(*Bang));
        printf ("Anda berhasil menggunakan Skill Barrage!\n");
    }
    else{
        printf ("Anda tidak memiliki skill yang tersedia\n");
    }
    Del(&(*Skill),&Q);
}
