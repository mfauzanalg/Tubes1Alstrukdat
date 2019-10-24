#ifndef __TYPEBENTUKAN_H__
#define __TYPEBENTUKAN_H__

#include "boolean.h"
#include "point.h"
#include "matriks.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "point.h"
#include "queue.h"
#include "stack.h"
#include "list.h"
#include "pcolor.h"
#include "mesinchar.h"
#include "mesinword.h"


typedef struct {
    int nomor; //indeks bangunan
	char type; //type bangunann
    int milik; //kepemilikan bangunan 0,1,2
    int jum; //jumlah pasukan dalam bangunan
    int lev; //level bangunan
    int A; //nilai penambahan pasukan
    int M; //maksimum penambahan pasukan
    boolean P; //pertahanan
    int U; //pasukan awal
    POINT letak; //letak pasukan
    boolean attacked; //berisi informasi apakah bangunan sudah pernah menyerang
} Bangunan;

typedef struct {
    int num; //Player.num = 1 maksudnya adalah player 1
    Queue Skill; //Skill yang dimiliki oleh Player
    List ListB; //List Bangunan yang dimiliki oleh Player
    Stack State; //State Player untuk mengaplikasikan fungsi Undo nanti
    boolean Shield; //menyatakan shield aktif
} PLAYER;

#define num(PLAYER)     (PLAYER).num
#define Skill(PLAYER)   (PLAYER).Skill
#define ListB(PLAYER)   (PLAYER).ListB
#define State(PLAYER)   (PLAYER).State

#define nomor(Bangunan) (Bangunan).nomor
#define type(Bangunan)  (Bangunan).type
#define milik(Bangunan) (Bangunan).milik
#define jum(Bangunan)   (Bangunan).jum
#define lev(Bangunan)   (Bangunan).lev
#define A(Bangunan)     (Bangunan).A
#define M(Bangunan)     (Bangunan).M
#define P(Bangunan)     (Bangunan).P
#define U(Bangunan)     (Bangunan).U
#define letak(Bangunan) (Bangunan).letak

#endif