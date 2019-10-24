#include "boolean.h"
#include "point.h"

typedef struct {
	int owner;  //1,2,0
    int pasukan;    //jml pasukan
    int lvl;    //level bangunan
    int A;  //nilai penambahan pasukan
    int M;  //maksimum penambahan
    boolean P;  //kondisi ada tidaknya pertahanan
    int U;  //jml pasukan awal
    point koordinate;
} Bangunan;

#define owner(Bangunan)     (Bangunan).owner
#define pasukan(Bangunan)   (Bangunan).pasukan
#define lvl(Bangunan)       (Bangunan).lvl
#define A(Bangunan)         (Bangunan).A
#define M(Bangunan)         (Bangunan).M
#define P(Bangunan)         (Bangunan).P
#define U(Bangunan)         (Bangunan).U

Bangunan C,T,F,V;

void ShowBangunanData(Bangunan X){
    if(X == C){
        pritnf("Castle ");
    }else if(X == T){
        printf("Tower ");
    }else if(X == F){
        printf("Fort ");
    }else if(X == V){
        printf("Village ")
    }
    printf("(%d,%d) %d lv. %d\n", koordinate(X).x, koordinate(X).y, pasukan(X), lvl(X));
}

void Attack(int pasukan,Bangunan Enemy){
    if(P(Enemy)){
        pasukan(Enemy) *= 4/3;
    }
    if(pasukan >= pasukan(Enemy)){
        pasukan -= pasukan(Enemy);
        if(owner(Enemy) == 1){
            owner(Enemy) = 2;
        } else if(owner(Enemy) == 2){
            owner(Enemy) =1;
        }
        pasukan(Enemy) = pasukan;
    }else{
        pasukan(Enemy)   -= pasukan;
    }
}

void ShowAttack(){
    printf("Daftar Bangunan");

}