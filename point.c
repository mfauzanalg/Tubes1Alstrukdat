#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

POINT MakePOINT (float X, float Y){
 /* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return (P);
}

void BacaPOINT (POINT *P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float x;
    float y;

    scanf ("%f %f", &x, &y);

    *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
     /* Nilai P ditulis ke layar dengan format "(X,Y)"
         tanpa spasi, enter, atau karakter lain di depan, belakang,
         atau di antaranya
         Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */

    printf ("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}


boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P) == 0);
}


boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P) == 0);
}


int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

    if ((Absis(P) > 0) && (Ordinat(P) > 0)){
        return (1);
    }

    else if ((Absis(P) < 0) && (Ordinat(P) > 0)){
        return (2);
    }

    else if ((Absis(P) < 0) && (Ordinat(P) < 0)){
        return (3);
    }

    else if ((Absis(P) > 0) && (Ordinat(P) < 0)){
        return (4);
    }
}

POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
    Absis (P) = Absis (P) + 1.00;
    return (P);
}

POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
    Ordinat(P) = Ordinat(P) + 1.00;
    return (P);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return(P);
}

POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    if (SbX == true){
        Ordinat (P) = Ordinat(P) * -1;
    }
    else {
        Absis (P) = Absis (P) * -1;
    }

    return (P);
}

float Jarak0 (POINT P){
    float X;
    float Y;
    float Z;
    X = Absis(P) * Absis (P);
    Y = Ordinat (P) * Ordinat (P);
    Z = Y + X;
    return (sqrt(Z));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    float X,Y;
    X = Absis (P1) - Absis (P2);
    Y = Ordinat(P1) - Ordinat(P2);
    X *= X;
    Y *= Y;
    return (sqrt(X+Y));
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY; 
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat (*P) = 0;
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis (*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX == true) {
        Ordinat(*P) *= -1; 
    }

    else{
        Absis(*P) *= -1;
    }
}

void Putar (POINT *P, float Sudut){
 /* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
    float sudut2, x;
    sudut2 = Sudut * (M_PI/180);

    x = Absis (*P);
    Absis (*P) = (cos (-1 * sudut2) * Absis (*P)) + (-sin(-1 * sudut2) * Ordinat (*P));
    Ordinat (*P) = (sin (-1 * sudut2) * x) + (cos(-1 * sudut2) * Ordinat (*P));
}
