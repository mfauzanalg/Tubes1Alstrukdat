#include <string.h>
#include "command.h"


void Art1(){
    printf("       _                         __\n"); 
    printf("      | |                       /_ |\n"); 
    printf(" _ __ | | __ _ _   _  ___ _ __   | |\n"); 
    printf("| '_ \\| |/ _` | | | |/ _ \\ '__|  | |\n"); 
    printf("| |_) | | (_| | |_| |  __/ |     | |\n"); 
    printf("| .__/|_|\\__,_|\\__, |\\___|_|     |_|\n"); 
    printf("| |             __/ |\n"); 
    printf("|_|            |___/\n\n");                
}

void Art2(){
    printf("       _                         ___\n");
    printf("      | |                       |__ \\\n");
    printf(" _ __ | | __ _ _   _  ___ _ __     ) |\n");
    printf("| '_ \\| |/ _` | | | |/ _ \\ '__|   / /\n");
    printf("| |_) | | (_| | |_| |  __/ |     / /_\n");
    printf("| .__/|_|\\__,_|\\__, |\\___|_|    |____|\n");
    printf("| |             __/ |\n");
    printf("|_|            |___/\n\n");
}


void HELP(){
    printf("Daftar Command yang dapat dilakukan : \n");
    printf("1. ATTACK \n");
    printf("2. LEVEL_UP \n");
    printf("3. SKILL \n");
    printf("4. UNDO \n");
    printf("5. END_TURN \n");
    printf("6. MOVE\n");
    printf("7. EXIT\n");
    printf("8. SAVE (Mungkin)\n");
    printf("\n");
}

void CetakAwal (int N, int M, TabBang Arr, PLAYER P1, PLAYER P2, PLAYER P3, PLAYER P4, int Curr, TabInt *T1){
    CetakPeta(N,M,Arr,P1,P2);
    printf("PLayer %d\n", Curr);
    DaftarBangunan(P3.ListB, Arr, &*T1);

    printf("Skill Aktif : \n");
    printf("Shield Lawan : "); if (P4.IsShield) printf("Aktif, sisa %d turn\n", P4.CountShield); else printf("Tidak aktif\n");
    printf("Critical Hit : "); if (P3.IsCriticalHit) printf("Aktif\n"); else printf("Tidak aktif\n");
    printf("Attack Up    : "); if (P3.IsAttackUp) printf("Aktif\n\n"); else printf("Tidak aktif\n\n");

    printf("Banyaknya skill yang dimiliki player : %d\n", NBElmtQueue(P3.Skill));
    printf("Skill Available : "); 
    CetakSkill(InfoHead(P3.Skill));
    printf("\n");
    printf("ENTER COMMAND : ");
}

void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P1, PLAYER P2, PLAYER *Pcop, stackp *SPlayer1, stackp *SPlayer2){
    CopyArr(Arr, &*Arrcop);
    Push(&*SBang, *Arrcop);

    CopyPlayer(P1, &*Pcop);
    Pushp(&*SPlayer1, *Pcop);

    CopyPlayer(P2, &*Pcop);
    Pushp(&*SPlayer2, *Pcop);
}

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P1, PLAYER *P2, stackp *SPlayer1, stackp *SPlayer2, PLAYER P3){
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
            if (Info(P) == i){ //kalo misalnya dia sama kayak indeks bangunan
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
    //*P3 itu milik kita
    //*P4 itu milik lawan
    addresslist A;
    int Z; //Jumlah Kita
    int Tujuan; //Jumlah lawan
    int Hasil;
    DaftarBangunan((*P3).ListB, *Arr, &*T1);
    printf("Pilih bangunan untuk menyerang : ");
    do{
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

            do{
                STARTWORD();
                *Y = WStringToInteger(CWord);
                if (*Y > Neff(*T2) || *Y <= 0){
                    printf("Pilihan tidak sesuai, silakan ulangi input\n");
                    printf("Pilih bangunan yang ingin diserang : ");
                }
            }while(*Y > Neff(*T2) || *Y <= 0);

            printf("Jumlah pasukan yang tersedia : %d\n", Elmt(*Arr,ElmtStat(*T1,*X)).jum);
            printf("Masukan jumlah pasukan yang ingin digunakan untuk menyerang : ");
            do{
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
            if((*P3).IsCriticalHit){           //Jika critical hit aktif
                Z *= 2;
                Tujuan -= Z;
                if (Tujuan <= 0){           //Berpindah kepemilikan
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
            else{                           //Jika critical hit tidak aktif
                if((*P3).IsAttackUp){          //Jika AttackUp Aktif
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
                else{                       //Jika AttackUp tidak Aktif
                    if((*P4).IsShield){        //Jika lawan memiliki shield
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
                    else{                   //Jika lawan tidak memiliki shield
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
                        else{                               //Jika lawan tidak memiliki pertahanan
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
        else {
            printf("Tidak ada bangunan yang dapat diserang\n");
        }
    }
    else{
        printf("Bangunan sudah menyerang pada turn ini\n");
    }
}

void KeLevel1(Bangunan *Bang){
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
    int Z;
    char Bang1[10];
    char Bang2[10];

    DaftarBangunan(P3.ListB, *Arr, &*T1);
    printf("Pilih bangunan asal pemindahan : ");
    do{
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
                do{
                    STARTWORD();
                    *Y = WStringToInteger(CWord);
                    if (*Y > Neff(*T2) || *Y <= 0){
                        printf("Pilihan tidak sesuai, silakan ulangi input\n");
                        printf("Pilih bangunan tujuan pemindahan : ");
                    }
                }while(*Y > Neff(*T2) || *Y <= 0);
                printf("Jumlah pasukan yang tersedia : %d\n", Elmt(*Arr,ElmtStat(*T1,*X)).jum);
                printf("Masukan jumlah pasukan yang ingin dipindahkan : ");
                do{
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
            else {
                printf("Tidak ada tujuan yang tersedia\n");
            }
        }
    else{
        printf("Bangunan sudah memindahkan pasukan pada turn ini\n");
    }
}

void CekKondisiAkhir(JumlahB Jumlahku, JumlahB Jumlahlawan, int FAwal, Condition Kondisi, PLAYER *Paku, PLAYER *Plawan, TabBang Arr, int J, boolean P1Turn){
    boolean stop = false;
    addresslist PP = First((*Paku).ListB);

    if (Kondisi.S){
        if (JTotal(Jumlahlawan) == 2){
            AddQueue(&(*Plawan).Skill, 2);
        }
    }
    if (Kondisi.AU){
        if (JTower(Jumlahlawan) == 3){
            AddQueue(&(*Paku).Skill, 4);
        }
    }
    if (Kondisi.B){
        if (JTotal(Jumlahku) == 10){
            AddQueue(&(*Plawan).Skill, 7);
        }
    }
    if (JFort(Jumlahlawan) == FAwal-1){
        AddQueue(&(*Plawan).Skill, 3);
    }
    while (PP != NilList && !(stop)){
        if (Elmt(Arr, Info(PP)).lev != 4){
            stop = true;
        }
        else{ 
            PP = Next(PP);
        }
    }
    if (PP == NilList){
        AddQueue(&(*Paku).Skill, 6);
    }
    if (JTotal(Jumlahku) == J){
        if(P1Turn){
            printf("Player 1 Menang\n");
            exit(0);
        }
        else{
            printf("Player 2 Menang\n");
            exit(0);
        }
    }
}

void LevelUpUp(TabBang *(Arr), PLAYER P, int *i, TabInt *T1, int IsCommand){
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

    //MC
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

    //MT
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

    //MF
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

    //MV
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
            if(Elmt(*(Arr), *i).lev == 4){
                printf("Castle-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){
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
        else if (Elmt(*(Arr), *i).lev < 4){
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MC,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MC,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MC,Elmt(*(Arr), *i).lev,3);
        }
    }
    else if (Elmt(*(Arr), *i).type == 'T'){
        if(IsCommand == 1){
            if(Elmt(*(Arr), *i).lev == 4){
                printf("Tower-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){
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
        else if (Elmt(*(Arr), *i).lev < 4){
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MT,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MT,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MT,Elmt(*(Arr), *i).lev,3);
        }
    }

    else if (Elmt(*(Arr), *i).type == 'F'){
        if(IsCommand == 1){
            if(Elmt(*(Arr), *i).lev == 4){
                printf("Fort-mu sudah mencapai level masksimal");
            }
            else if ((Elmt(*(Arr), *i).jum-Elmt(*(Arr), *i).M/2)<0){
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
        else if (Elmt(*(Arr), *i).lev < 4){
            Elmt(*(Arr), *i).lev++;
            Elmt(*(Arr), *i).A=ElmtMat(MF,Elmt(*(Arr), *i).lev,1);
            Elmt(*(Arr), *i).M=ElmtMat(MF,Elmt(*(Arr), *i).lev,2);
            Elmt(*(Arr), *i).P=ElmtMat(MF,Elmt(*(Arr), *i).lev,3);
        }
    }

    else{
        if(IsCommand== 1){
            if(Elmt(*(Arr), *i).lev == 4){
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

void exitGame()
{
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
