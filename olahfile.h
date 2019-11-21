#ifndef __OLAHFILE_H__
#define __OLAHFILE_H__

#include "boolean.h"
#include "array.h"
#include "typebentukan.h"
#include "graph_baru.h"

void LoadFile (int *N, int *M, int *J, TabBang *Arr, GraphList *Graph, MATRIKS *Mat, List *L1, List *L2);
// Load file data inisialisasi awal
// Akan terbentuk
// N = tinggi peta
// M = lebar peta
// J = Jumlah bangunan
// Array of bangunan
// Matriks untuk Graf

void CetakPeta(int N, int M, TabBang Arr, PLAYER P1, PLAYER P2);
// Mencatak Peta sesuai dengan file yang sudah di load

void DaftarBangunan(List L, TabBang Arr, TabInt *TOut);
// Mencetak Daftar Bangunan yang dimiliki oleh Playe P

void AdaSerang (List L, TabBang Arr, int player, boolean *ada, PLAYER P1, PLAYER P2);
//Apakah ada bangunan yang dapat diserang

void DaftarSerang(List L, TabBang Arr, TabInt *TOut, int player, PLAYER P1, PLAYER P2);
//Mencetak Daftar Bangunan yang dapat diserang

void AdaMove (List L, TabBang Arr, int player, boolean *ada, PLAYER P1, PLAYER P2);
//Apakah ada bangunan yang menjadi tujuan pemindahan

void DaftarMove(List L, TabBang Arr, TabInt *TOut, int player, PLAYER P1, PLAYER P2);
//Mencetak Daftar Bangunan yang dapat dipindahkan

void StartPlayer (PLAYER *P);
// Status player waktu baru mulai

void UpdateBangunan (PLAYER Pl, PLAYER *Enemy, boolean *P1turn,TabBang *Arr);
// Penambahan tiap turnnya

void CetakSkill (int x);
// Cetak skill karena di queue isinya integer

int owner (int i, List P1, List P2);
// Mengembalikan 1 jika bangunan berindeks i milik player 1
// Mengembalikan 2 jika bangunan berindeks i milik player 2
// Mengembalikan 0 jika bangunan berindeks i bukan milik siapa pun

#endif
