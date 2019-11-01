#ifndef COMMAND_H
#define COMMAND_H


#include <stdio.h>
#include <stdlib.h>
#include "typebentukan.h"
#include "stack.h"
#include "array.h"


void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P, PLAYER *Pcop, stackp *SPlayer);

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P, stackp *SPlayer);

void HitungJum (JumlahB *Jumlah, PLAYER P, TabBang Arr);
//Menghitung jumlah bangunan yang dimiliki 

void CekKondisi (JumlahB jumlahku, JumlahB jumlahlawan, Condition *Kondisi);
//Mengecek kemungkinan penambahan skill

void LevelUpUp(TabBang *(Arr), PLAYER P, int i);

#endif