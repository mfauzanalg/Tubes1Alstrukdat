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
    boolean found;

    P = First(ListB(Pl));
    i = 1;
    found  = false;
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
    boolean found;

    P = First(ListB(Pl));
    i = 1;
    found  = false;
    while (Next(P) != NilList){
        while(i <= NbElmtArr(Arr)){
            if(Info(P) == i){
                Elmt(Arr,i).P += true;
            }
            i++;
        }
        P = Next(P);
    }
}

void ExtraTurn (PLAYER Pl){
    if (state == 1){
        state = 2;
    }else if (state == 2){
        state =1;
    }
}

void AttackUp ()

void QueueSkill(){
    CreateEmpty(&Skill,10);
    Add(&Skill,1);
}

void UseSkill(Queue Q,Bangunan B, state Player, Bangunan Enemy){  //seluruh bangunan??? ngehubungin bangunan satu ke yg lain yg dimiliki itu gimana??
    
    //ini cuma buat 1 bangunan dulu
    if (InfoHead(Q) == 1){

        lev(B) += 1;
    }else if (InfoHead(Q) == 2){
        P(B) = true;
    }else if (InfoHead(Q) == 3){
        //fungsi turn nya mau howw???
    }else if(InfoHead(Q) == 4){
        P(Enenmy) = false;
    }else if(InfoHead(Q) == 5){

    }

}


//how to get skill
//dipanggil tergantung main(tergantung aksi yang telah dilaukan di main)
void GetSkill(Queue Skill, int x){
    if(x == 2){
        Add(&Skill,2);
    }else if(x == 3){
        Add(&Skill,3);
    }else if(x == 4){
        Add(&Skill,4);
    }else if(x == 5){
        Add(&Skill,5);
    }else if(x == 6){
        Add(&Skill,6);
    }else if(x == 7){
        Add(&Skill,7);
    }
}