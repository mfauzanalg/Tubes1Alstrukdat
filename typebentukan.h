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
  int TI[1000]; /* memori tempat penyimpan elemen (container) */
  int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;

typedef struct{
    int JCastle;
    int JTower;
    int JFort;
    int JVillage;
    int JTotal;
} JumlahB;

typedef struct{
    boolean S;
    boolean ET;
    boolean AU;
    boolean B;
} Condition;

typedef struct {
    int nomor; //indeks bangunan
	char type; //type bangunann
    int jum; //jumlah pasukan dalam bangunan
    int lev; //level bangunan
    int A; //nilai penambahan pasukan
    int M; //maksimum penambahan pasukan
    boolean P; //pertahanan
    int U; //pasukan awal
    POINT letak; //letak pasukan
    boolean attack; //true : masih bisa menyerang
    boolean move; //true : masih bisa move
} Bangunan;

typedef struct {
    Queue Skill;         //Skill yang dimiliki oleh Player
    List ListB;          //List Bangunan yang dimiliki oleh Player
    boolean IsShield;      //menyatakan shield player aktif/tidak
    boolean IsAttackUp;    //menyatakan attack up player aktif/tidak
    boolean IsCriticalHit; //menyatakan critical hit player aktif/tidak
    boolean IsAttack;      //Apakah sedang menyerang. aktif setelah dipanggil command attack
    boolean Askill;      //After Skill
    boolean Aend;        //After END_TURN
    boolean IsET;       //Untuk 
    int CountShield;     //untuk menerima 
} PLAYER;

#define JCastle(JumlahB) (JumlahB).JCastle
#define JTower(JumlahB)  (JumlahB).JTower
#define JFort(JumlahB)   (JumlahB).JFort
#define JVillage(JumlahB) (JumlahB).JVillage
#define JTotal(JumlahB)  (JumlahB).JTotal

#define Neff(T)             (T).Neff
#define T(T)                (T).T
#define ElmtStat(T,i)       (T).TI[(i)]

#define Skill(PLAYER)       (PLAYER).Skill
#define ListB(PLAYER)       (PLAYER).ListB
#define IsShield(PLAYER)      (PLAYER).IsShield
#define IsAttack(PLAYER)    (PLAYER).IsAttack
#define IsAttackUp(PLAYER)    (PLAYER).IsAttackUp
#define IsCriticalHit(PLAYER) (PLAYER).IsCriticalHit
#define Askill(PLAYER)      (PLAYER).Askill
#define Aend(PLAYER)        (PLAYER).Aend

#define nomor(Bangunan)     (Bangunan).nomor
#define type(Bangunan)      (Bangunan).type
#define milik(Bangunan)     (Bangunan).milik
#define jum(Bangunan)       (Bangunan).jum
#define lev(Bangunan)       (Bangunan).lev
#define A(Bangunan)         (Bangunan).A
#define M(Bangunan)         (Bangunan).M
#define P(Bangunan)         (Bangunan).P
#define U(Bangunan)         (Bangunan).U
#define letak(Bangunan)     (Bangunan).letak
#define attack(Bangunan)    (Bangunan).attack
#define move(Bangunan)      (Bangunan).move  

#endif
