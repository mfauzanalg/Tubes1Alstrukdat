#include <string.h>
#include "command.h"
#include "../olahfile/olahfile.h"

int main(){
    int N, M, J, X, Y, FAwal, TAwal;
    boolean Playing, P1turn, ada;
    TabBang Arr, Arr2; 
    GraphList Graph;
    Stack SBang;  
    stackp SP1, SP2;   
    PLAYER P1, P2, P3; 
    TabInt T1, T2; 
    MATRIKS Mat;
    List Tetangga;
    JumlahB Jumlah1, Jumlah2; 
    Condition Kondisi;

    LoadFile (&N, &M, &J, &Arr, &Graph, &Mat, &P1.ListB, &P2.ListB);
    StartPlayer(&P1);
    StartPlayer(&P2);
    Playing = true;
    P1turn = true;
    CreateEmptystackp(&SP1);
    CreateEmptystackp(&SP2);
    CreateEmptyStack(&SBang);
    menuAwal();
    HELP();
    Art1();
    UpdateBangunan (&P1, &P2, &P1turn, &Arr);
    HitungJum (&Jumlah1, P1, Arr);
    HitungJum (&Jumlah2, P2, Arr);
    CekKondisi (Jumlah1, Jumlah2, &Kondisi);
    FAwal = JFort(Jumlah2);
    TAwal = JFort(Jumlah2);
    printf("================== Kondisi Awal ==================\n");
    CetakAwal(N,M,Arr, P1, P2, P1, P2, 1, &T1);

    PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
    printf("\n");
    printf("================== Lakukan Attack ==================\n");
    Attack(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, Graph, &P1, &P2);
    printf("\n================== Lakukan Undo ==================\n");
    UndoAll(&Arr, &SBang, &P1, &P2, &SP1, &SP2, P1);
    printf("\n================== Lakukan Move ==================\n");
    PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
    Move(&Arr, &X, &Y, &T1, &T2, &Tetangga, P1, P2, 1, &ada, Graph, P1);
    printf("\n================== Lakukan Level Up ==================\n");
    PushAll(Arr, &Arr2, &SBang, P1, P2, &P3, &SP1, &SP2);
    LevelUpUp(&Arr, P1, &X, &T1, 1);
    printf("\n================== Gunakan Skill ==================\n");
    UseSkill(&P1.Skill, &P1, &P2, &Arr, &P1.IsET);
    printf("\n================== Exit Game ==================\n");
    exitGame();
    


}