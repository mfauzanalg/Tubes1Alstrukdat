/*skill.c */
/*berisi semua fungsi yang berkaitan dengan pemanggilan skill*/

#include "typebentukan.h"
#include "queue.h"
#include "array.h"
#include <stdlib.h>
#include "stack.h"

void AddSkill(int x, Queue Skill){
/*Menambahkan skill dalam tipe iteger. Misal InstantUpgrade ditambahkan sebagai queue dengan angka 1 */
/*  1 = InstantUpgrade
    2 = Shield
    3 = ExtraTurn
    4 = AttackUp
    5 = CriticalHit
    6 = InstantReinforcement
    7 = Barrage
*/
    if(NBElmtQueue(Skill) < 10){        //Menambahkan Queue jika jumlah skill masih di bawah 10. Max Queue = 10
        AddQueue(&Skill,x);
    }
}

void InstantUpgrade(PLAYER Pl, TabBang Bang){
/*seluruh bangunan naik 1 level*/
    
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;

    //ALGORITMA
    //iterasi P
    P = First(ListB(Pl));
    i = 1;
    stop = false;

    while (Next(P) != NilList){                     //akses daftar bangunan yang dimiliki player -> ListB(Pl)
        while((i <= NbElmtArr(Bang)) && !stop){      //mencari daftar bangunan yang dimiliki pemain dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){                       //jika isi dari list bangunan yang dimiliki player = list bangunan dalam array of bangunan
                Elmt(Bang,i).lev += 1;               //naik 1 level untuk semua bangunan
                stop = true;                        //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki pemain
            }
        }
        P = Next(P);                                //pindah ke bangunan selanjutnya milik player 
    }
}

void Shield (PLAYER Pl, TabBang Arr){
/* seluruh bangunan yang dimiliki oleh pemain akan memiliki shield selama 2 turn */
/* shield membuat jumlah pasukan yang dimiliki bertambah sebanyak 4/3 */
    
    //KAMUS LOKAL
    addresslist P;
    int i;
    int state;                      // state = 2 -> awal pakai skill, state = 1 -> skill yang didapat tersisa 1 turn, state = 0 -> shield habis
    boolean stop;

    //ALGORITMA
    P = First(ListB(Pl));           //Isi P dengan awal list bangunan dari player
    i = 1;
    state = 2;                      //awal memiliki shield -> masih punya 2 turn/shield belum digunakan
    stop = false;

    while (state > 0){                          //ketika masih memiliki pertahanan
        IsShield(Pl) = true;
        while (Next(P) != NilList){             //menelusuri daftar bangunan yang dimiliki pemain
            while(i <= NbElmtArr(Arr)){         //menelusuri daftar bangunan pada array of bangunan
                if((Info(P) == i) && !stop){               //apabila bangunan milik pemain = bangunan pada array of bangunan
                    Elmt(Arr,i).P += true;      //mengaktifkan pertahanan seluruh bangunan milik pemain
                    /* JANGAN LUPA DI MAIN KALAU PERTAHANAN AKTIF,JUMLAH PEMAIN NAMBAH 4/3 WAKTU DISERANG */
                }
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki pemain
            }
            P = Next(P);                                //pindah ke bangunan selanjutnya milik player 
        }
    }
    state--;                                    //setelah skill terpakai, state berkurang
}

void ExtraTurn (PLAYER Pl, int turnp){
/* Setelah turn berakhir pemain mendapatkan turn lagi */
/* turnp mengembalikan nilai turn pemain. turnp = 1 adalah turn pemain 1, turnp = 2 adalah turn pemain 2 */
    //KAMUS LOKAL

    //ALGORITMA
    if(Aend(Pl)){                   //kondisi setelah pemain mengetikkan end turn
        if (turnp == 1){            //jika turn pemain 1: turn pemain -> 2 dan sebaliknya
            turnp = 2;
        }else if (turnp == 2){
            turnp =1;
        }
    }
}

void AttackUp(PLAYER Pl,PLAYER Enemy,TabBang Bang){
/* Setelah skill diaktifkan, pertahanan bangunan musuh​(termasuk Shield)​ tidak akan mempengaruhi penyerangan. */
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;

    //ALGORITMA
    P = First(ListB(Enemy));                    //Isi P dengan awal list bangunan dari lawan
    i = 1;
    stop = false;

    if(IsAttack(Pl)){
        while (Next(P) != NilList){             //menelusuri daftar bangunan yang dimiliki lawan
            while(i <= NbElmtArr(Bang)){        //menelusuri daftar bangunan pada array of bangunan
                if((Info(P) == i) && !stop){    //apabila bangunan milik lawan = bangunan pada array of bangunan
                    Elmt(Bang,i).P += false;    //menon-aktifkan pertahanan seluruh bangunan milik lawan
                }
                i++;                            //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki lawan
            }
            P = Next(P);                        //pindah ke bangunan selanjutnya milik lawan
        }
    }
}

void CriticalHit(PLAYER Pl,PLAYER Enemy,TabBang Bang){
/* Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya ​(hanya berlaku 1 serangan) hanya efektif sebanyak 2 kali lipat pasukan​. ​Skill ini akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up. */
    //KAMUS LOKAL
    addresslist P;
    int i;
    boolean stop;

    //ALGORITMA
    P = First(ListB(Enemy));                    //Isi P dengan awal list bangunan dari lawan
    i = 1;
    stop = false;

    if(IsAttack(Pl)){
        while (Next(P) != NilList){             //menelusuri daftar bangunan yang dimiliki lawan
            while(i <= NbElmtArr(Bang)){        //menelusuri daftar bangunan pada array of bangunan
                if((Info(P) == i) && !stop){    //apabila bangunan milik lawan = bangunan pada array of bangunan
                    Elmt(Bang,i).P += false;    //menon-aktifkan pertahanan seluruh bangunan milik lawan
                }
                i++;                            //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki lawan
            }
            P = Next(P);                        //pindah ke bangunan selanjutnya milik lawan
        }
        Elmt(Bang,i).jum *= 2;                  //jika pemain melakukan attack jumlah pasukannya akan bertambah 2 kali lipat
    }
}

void InstantReinforcement(PLAYER Pl, TabBang Bang){
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

    while (Next(P) != NilList){                     //akses daftar bangunan yang dimiliki player -> ListB(Pl)
        while((i <= NbElmtArr(Bang)) && !stop){     //mencari daftar bangunan yang dimiliki pemain dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){                       //jika isi dari list bangunan yang dimiliki player = list bangunan dalam array of bangunan
                Elmt(Bang,i).jum += 5;              //semua bangunan jumlah pasukannya bertambah sebanyak 5
                stop = true;                        //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki pemain
            }
        }
        P = Next(P);                                //pindah ke bangunan selanjutnya milik player 
    }
}

void Barrage(PLAYER Enemy,TabBang Bang){
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

    while (Next(P) != NilList){                     //akses daftar bangunan yang dimiliki musuh -> ListB(Enemy)
        while((i <= NbElmtArr(Bang)) && !stop){     //mencari daftar bangunan yang dimiliki musuh dalam array of bangunan dari 1 sampai NbElmt array of bangunan
            if(Info(P) == i){                       //jika isi dari list bangunan yang dimiliki musuh = list bangunan dalam array of bangunan
                Elmt(Bang,i).jum -= 10;             //semua bangunan musuh jumlah pasukannya berkurang sebanyak 10
                stop = true;                        //menghentikan pencarian jika bangunan x sudah naik level
            }else{
                i++;                                //pindah ke elmt array of bangunan selanjutnya jika bangunan tak dimiliki musuh
            }
        }
        P = Next(P);                                //pindah ke bangunan selanjutnya milik musuh
    }
}

void UseSkill(Queue Skill, PLAYER Pl, PLAYER Enemy, TabBang Bang,int turnp){
/* procedure yang dipanggil setelah command skill */
    infotypequeue Q;
    if (InfoHead(Skill) == 1){
        InstantUpgrade(Pl,Bang);
    } else if(InfoHead(Skill) == 2){
        Shield(Pl,Bang);
    } else if(InfoHead(Skill) == 3){
        ExtraTurn(Pl,turnp);
    } else if(InfoHead(Skill) == 4){
        AttackUp(Pl,Enemy,Bang);
    } else if(InfoHead(Skill) == 5){
        CriticalHit(Pl,Enemy,Bang);
    } else if(InfoHead(Skill) == 6){
        InstantReinforcement(Pl,Bang);
    } else if(InfoHead(Skill) == 7){
        Barrage(Enemy,Bang);
    }
    DelQueuee(&Skill,&Q);
}
