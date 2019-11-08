#ifndef __OLAHFILE_H__
#define __OLAHFILE_H__

#include "boolean.h"
#include "array.h"
#include "typebentukan.h"
#include "graph.h"

void LoadFile (int *N, int *M, int *J, TabBang *Arr, TabGraph *ArrGraph, MATRIKS *Mat, List *L1, List *L2);
// Load file data inisialisasi awal
// Akan terbentuk
// N = tinggi peta
// M = lebar peta
// J = Jumlah bangunan
// Array of bangunan
// Matriks untuk Graf

void CetakPeta(int N, int M, TabBang Arr);
// Mencatak Peta sesuai dengan file yang sudah di load

void DaftarBangunan(List L, TabBang Arr, TabInt *TOut);
// Mencetak Daftar Bangunan yang dimiliki oleh Playe P

void DaftarSerang(List L, TabBang Arr, TabInt *TOut, int player, boolean *ada);
//Mencetak Daftar Bangunan yang dapat diserang

void DaftarMove(List L, TabBang Arr, TabInt *TOut, int player, boolean *ada);
//Mencetak Daftar Bangunan yang dapat dipindahkan

void StartPlayer (PLAYER *P);
// Status player waktu baru mulai

void UpdateBangunan (List L, TabBang *Arr);
// Penambahan tiap turnnya

void CetakSkill (int x);
// Cetak skill karena di queue isinya integer

#endif
