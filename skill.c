/*skill.c */
/*berisi semua fungsi yang berkaitan dengan pemanggilan skill*/

#include "typebentukan.h"
#include "queue.h"
#include "array.h"

void AddSkill(int x, Queue *Skill){
    Add(Skill,x);
}

void InstantUpgrade(PLAYER Pl, TabBang Arr){
    addresslist P;
    int i;

    P = First(ListB(Pl));
    i = 1;

    while (Next(P) != NilList){
        while(i <= NbElmtArr(Arr)){
            if(Info(P) == i){
                Elmt(Arr,i). += 1;
            }
            i++;
        }
        P = Next(P);
    }
}

void Shield (PLAYER Pl, TabBang Arr){
    addresslist P;
    int i;
    int state; // state = 2 -> awal pakai skill, state = 1 -> skill yang didapat tersisa 1 turn, state = 0 -> shield habis

    P = First(ListB(Pl));
    i = 1;
    state = 2;

    while (state > 0){
        while (Next(P) != NilList){
            while(i <= NbElmtArr(Arr)){
                if(Info(P) == i){
                    Elmt(Arr,i).P += true;
                }
                i++;
            }
            P = Next(P);
        }
        state--;
    }
}

void ExtraTurn (PLAYER Pl, int state){
    if (state == 1){
        state = 2;
    }else if (state == 2){
        state =1;
    }
}

void AttackUp (PLAYER Pl, TabBang Arr){
    addresslist P;
    int i;
    boolean found;

    P = First(ListB(Pl));
    i = 1;
    found  = false;
    while (Next(P) != NilList){
        while(i <= NbElmtArr(Arr)){
            if(Info(P) == i){
                Elmt(Arr,i).P += false;
            }
            i++;
        }
        P = Next(P);
    }
}

void Critical_Hit(PLAYER aktif){
    queue Q;
    infotype X;
    Pop(*Q,*X);  
    int temp_Critical += 1;
}


 void Instant_Reinforcement(PLAYER aktif){
    
    infotype X;
    Pop(*Q,*X);   
    if (aktif.num == 1){
        P = First(*L1); 
}
    else //kalau buat player 2
    {
        P = First(*L2);
    }
    while (P != Nil){
            
            Elmt(Arr,Info(P)).jum += 5;
        } 

    }

}

void barrage(PLAYER aktif){
    
    infotype X;
    Pop(*Q,*X);
    int i;
    if (aktif.num == 1){
       address P = First(*L2);
        } 

    else //kalau buat player 2
    {
        address P = First(*L1);
    }
    while (next(P) != Nil){
            
            Elmt(Arr,Info(P)).jum -= 10;
            P = Next(P);
        } 

    }





void UseSkill(Queue Skill, PLAYER P, TabBang Arr){
    if (InfoHead(Skill) == 1){
        InstantUpgrade(P,Arr);
    } else if(InfoHead(Skill) == 2){
        Shield(P,Arr);
    } else if(InfoHead(Skill) == 3){
        ExtraTurn(P,num(P));
    } else if(InfoHead(Skill) == 4){
        AttackUp(P,Arr);
    } else if(InfoHead(Skill) == 5){
        CriticalHit();
    } else if(InfoHead(Skill) == 6){
        InstantReinforcement();
    } else if(InfoHead(Skill) == 7){
        Barrage();
    }
}
