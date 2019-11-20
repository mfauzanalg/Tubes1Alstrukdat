/*skill.c */
/*berisi semua fungsi yang berkaitan dengan pemanggilan skill*/


#include "skill.h"
#include "stdlib.h"


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
            if(Info(P) == i){   
                printf("masuk\n");                              //jika isi dari list bangunan yang dimiliki player = list bangunan dalam array of bangunan
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
    (*Pl).CountShield = 2;
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

void Barrage(PLAYER Enemy,TabBang *Bang){
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

void UseSkill(Queue *Skill, PLAYER Pl, PLAYER Enemy, TabBang *Bang, boolean *ET){
/* procedure yang dipanggil setelah command *Skill */
    infotypequeue Q;
    if (InfoHead(*Skill) == 1){
        InstantUpgrade(Pl,&(*Bang));
    } else if(InfoHead(*Skill) == 2){
        Shield(&Pl);
    } else if(InfoHead(*Skill) == 3){
        ExtraTurn(&(*ET));
    } else if(InfoHead(*Skill) == 4){
        AttackUp(&Pl);
    } else if(InfoHead(*Skill) == 5){
        CriticalHit(&Pl);
    } else if(InfoHead(*Skill) == 6){
        InstantReinforcement(Pl,&(*Bang));
    } else if(InfoHead(*Skill) == 7){
        Barrage(Enemy, &(*Bang));
    }
    Del(&(*Skill),&Q);
}
