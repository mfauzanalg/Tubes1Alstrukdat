#ifndef __TYPEBENTUKAN_H__
#define __TYPEBENTUKAN_H__

#include "boolean.h"
#include "point.h"
#include "matriks.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "point.h"
#include "queue.h"
#include "list.h"
#include "pcolor.h"
#include "mesinchar.h"
#include "mesinword.h"


typedef struct {
    int nomor; //indeks bangunan
	char type; //type bangunann
    int milik; //kepemilikan bangunan
    int jum; //jumlah pasukan dalam bangunan
    int lev; //level bangunan
    int A; //nilai penambahan pasukan
    int M; //maksimum penambahan pasukan
    boolean P; //pertahanan
    int U; //pasukan awal
    POINT letak; //letak pasukan
} Bangunan;

typedef struct {
    int num; //Player.num = 1 maksudnya adalah player 1
    Queue Skill; //Skill yang dimiliki oleh Player
    List Bang; //List Bangunan yang dimiliki oleh Player
} PLAYER;

#endif