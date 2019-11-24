#include <stdio.h>
#include <stdlib.h>
#include "load.h"

boolean IntegerToBoolean(int x){
    boolean out;
    if(x == 0){
        return false;
    } else{
        return true;
    }
}

void load (Stack *SB, stackp *P1, stackp *P2, boolean *playing, boolean *P1turn){
    
    int i,maxel;
    infotypestack S;
    infotypestackp SP1,SP2;
	STARTKATAl();
    // ADVKATA();
    
    // SalinKata();
    
	*playing = IntegerToBoolean(StringToIntegerl(CKatal));
	ADVKATAl();
	*P1turn = IntegerToBoolean(StringToIntegerl(CKatal));
	ADVKATAl();

    maxel = 17;
    S.MaxElArr = 17;
    ADVKATAl();
    
    CreateEmptyStack(&(*SB));
    CreateEmptystackp(&(*P1));
    CreateEmptystackp(&(*P2));
    
    CreateEmptyArray(&S,maxel);
    
    for(i = 1; i <= maxel; i++){
        
        if(CKatal.TabKatal[1] == 'C'){
            Elmt(S,i).type = 'C';
        } else if(CKatal.TabKatal[1] == 'T'){
            Elmt(S,i).type = 'T';
        } else if(CKatal.TabKatal[1] == 'V'){
            Elmt(S,i).type = 'V';
        } else if(CKatal.TabKatal[1] == 'F'){
            Elmt(S,i).type = 'F';
        }
        ADVKATAl();
        Elmt(S,i).jum = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).lev = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).A = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).M = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).P = IntegerToBoolean(StringToIntegerl(CKatal));
        ADVKATAl();
        Elmt(S,i).U = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).letak.X = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).letak.Y = StringToIntegerl(CKatal);
        ADVKATAl();
        Elmt(S,i).attack = IntegerToBoolean(StringToIntegerl(CKatal));
        ADVKATAl();
        Elmt(S,i).move = IntegerToBoolean(StringToIntegerl(CKatal));
        ADVKATAl();
    }
    Push(&(*SB),S);
    
    CreateEmptyQueue(&(SP1.Skill),10);
    while(CKatal.TabKatal[1] != 'X'){
        AddQueue(&(SP1.Skill),StringToIntegerl(CKatal));
        ADVKATAl();
    }
    
    CreateEmptyList(&(SP1.ListB));
    while(CKatal.TabKatal[1] != 'Y'){
        InsVLast(&(SP1.ListB),StringToIntegerl(CKatal));
        ADVKATAl();
    }
    SP1.IsShield = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.IsAttackUp = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.IsCriticalHit = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.IsAttack = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.Askill = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.Aend = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.IsET = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP1.IsShield = StringToIntegerl(CKatal);
    ADVKATAl();

    Pushp(&(*P1),SP1);


    CreateEmptyQueue(&(SP2.Skill),10);
    while(CKatal.TabKatal[1] != 'X'){
        AddQueue(&(SP2.Skill),StringToIntegerl(CKatal));
        ADVKATAl();
    }
    CreateEmptyList(&(SP2.ListB));
    while(CKatal.TabKatal[1] != 'Y'){
        InsVLast(&(SP2.ListB),StringToIntegerl(CKatal));
        ADVKATAl();
    }
    SP2.IsShield = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.IsAttackUp = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.IsCriticalHit = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.IsAttack = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.Askill = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.Aend = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.IsET = IntegerToBoolean(StringToIntegerl(CKatal));
    ADVKATAl();
    SP2.IsShield = StringToIntegerl(CKatal);
    Pushp(&(*P2),SP2);

    CLOSEl();
}