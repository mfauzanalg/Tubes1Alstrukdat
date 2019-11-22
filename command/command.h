#ifndef COMMAND_H
#define COMMAND_H


#include <stdio.h>
#include <stdlib.h>

#include "../typebentukan/typebentukan.h"
#include "../stack/stack.h"
#include "../array/array.h"
#include "../olahfile/olahfile.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../command/command.h"

void Art1();
// Untuk menampilkan Ascii Art player 1

void Art2();
// Untuk menampilkan Ascii Art player 1

void HELP();
// Untuk menampilkan command apa saja yang dapat dilakukan pada program

void CetakAwal (int N, int M, TabBang Arr, PLAYER P1, PLAYER P2, PLAYER P3, PLAYER P4, int Curr, TabInt *T1);
// Cetak awal saat player baru dimulai

void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P1, PLAYER P2, PLAYER *Pcop, stackp *SPlayer1, stackp *SPlayer2);
// Untuk Push ke stacknya

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P1, PLAYER *P2, stackp *SPlayer1, stackp *SPlayer2, PLAYER P3);
// Untuk Undo

void HitungJum (JumlahB *Jumlah, PLAYER P, TabBang Arr);
//Menghitung jumlah bangunan yang dimiliki 

void CekKondisi (JumlahB jumlahku, JumlahB jumlahlawan, Condition *Kondisi);
//Mengecek kemungkinan penambahan skill

void Attack(TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER *P3, PLAYER *P4);
//Attack

void KeLevel1(Bangunan *Bang);

void Move(TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER P3);
//Move pasukan

void CekKondisiAkhir(JumlahB Jumlahku, JumlahB Jumlahlawan, int FAwal, Condition Kondisi, PLAYER *Paku, PLAYER *Plawan, TabBang Arr, int J, boolean P1Turn);
// Menambah skill atau tidak di akhir

void LevelUpUp(TabBang *(Arr), PLAYER P, int *i, TabInt *T1, int IsCommand);
// Untuk level up

void exitGame();

void InstantUpgrade(PLAYER Pl, TabBang *Bang);

void Shield(PLAYER *Pl);

void ExtraTurn(boolean *ET);

void AttackUp(PLAYER *Pl);

void CriticalHit(PLAYER *Pl);

void InstantReinforcement(PLAYER Pl, TabBang *Bang);

void Barrage(PLAYER Enemy,TabBang *Bang);

void UseSkill(Queue *Skill, PLAYER *Pl, PLAYER *Enemy, TabBang *Bang, boolean *ET);

void ActiveTurn();

#endif