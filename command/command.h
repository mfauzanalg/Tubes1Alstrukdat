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
// Untuk menampilkan Ascii Art player 2

void ArtWin();
// Untuk menampilkan Ascii Art Win

void HELP();
// Untuk menampilkan command apa saja yang dapat dilakukan pada program

void CetakAwal (int N, int M, TabBang Arr, PLAYER P1, PLAYER P2, PLAYER P3, PLAYER P4, int Curr, TabInt *T1);
// Cetak awal saat player baru dimulai
// Cetak Player berapa
// Cetak Daftar bangunan yang dimiliki oleh player
// Cetak status skill

void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P1, PLAYER P2, PLAYER *Pcop, stackp *SPlayer1, stackp *SPlayer2);
// Push Array ke Stack Array, Push Player ke Stack Player

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P1, PLAYER *P2, stackp *SPlayer1, stackp *SPlayer2, PLAYER P3);
// Undo Command Terakhir dengan cara pop stack of array dan stack of player
// Berhasil jika command terakhir bukan Skill atau End Turn

void HitungJum (JumlahB *Jumlah, PLAYER P, TabBang Arr);
// Menghitung jumlah bangunan yang dimiliki oleh pemain dan memasukannya ke dalam Jumlah

void CekKondisi (JumlahB jumlahku, JumlahB jumlahlawan, Condition *Kondisi);
// Untuk mengecek kondisi penambahan skill
// Apakah berotensi untuk mendapat penambahan skill di akhir command

void Attack(TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER *P3, PLAYER *P4);
// Untuk melakukan command attack

void KeLevel1(Bangunan *Bang);
// Untuk mengembalikan bangunan yang berhasil di rebut ke level 1

void Move(TabBang *Arr, int *X, int *Y, TabInt *T1, TabInt *T2, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, GraphList Graph, PLAYER P3);
// Memindahkan pasukan dari bangunan ke bangunan lain yang masih milik player

void CekKondisiAkhir(JumlahB Jumlahku, JumlahB Jumlahlawan, int FAwal, Condition Kondisi, PLAYER *Paku, PLAYER *Plawan, TabBang Arr, int J, boolean P1Turn);
// Mengecek kondisi yang mungkin terjadi di akhir command
// Mengecek apakah akan terjadi penambahan skill
// Mengecek apakah player 1/2 sudah memenangkan permainan

void LevelUpUp(TabBang *(Arr), PLAYER P, int *i, TabInt *T1, int IsCommand);
// Untuk level Up bangunan yang sudah memenuhi kriteria
// Dapat dilakukan melalui command (saat isCommand == 1)
// Dapat diakses melalui skill Instant Upgrade

void exitGame();
// Untuk keluar dari game

void InstantUpgrade(PLAYER Pl, TabBang *Bang);
// Seluruh Bangunan Naik satu level

void Shield(PLAYER *Pl);
/* seluruh bangunan yang dimiliki oleh pemain akan memiliki shield selama 2 turn */
/* shield membuat jumlah pasukan yang dimiliki bertambah sebanyak 4/3 */

void ExtraTurn(boolean *ET);
/* Setelah turn berakhir pemain mendapatkan turn lagi */

void AttackUp(PLAYER *Pl);
/* Setelah skill diaktifkan, pertahanan bangunan musuh​(termasuk Shield)​ tidak akan mempengaruhi penyerangan. */

void CriticalHit(PLAYER *Pl);
/* Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya ​(hanya berlaku 1 serangan) hanya efektif sebanyak 2 kali lipat pasukan​. ​Skill ini akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up. */

void InstantReinforcement(PLAYER Pl, TabBang *Bang);
/* Seluruh bangunan mendapatkan tambahan 5 pasukan */

void Barrage(PLAYER Enemy,TabBang *Bang);
/* Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10 pasukan. */

void UseSkill(Queue *Skill, PLAYER *Pl, PLAYER *Enemy, TabBang *Bang, boolean *ET);
/* procedure yang dipanggil setelah command *Skill */


#endif