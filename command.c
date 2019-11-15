#include "command.h"

void PushAll (TabBang Arr, TabBang *Arrcop, Stack *SBang, PLAYER P1, PLAYER P2, PLAYER *Pcop, stackp *SPlayer1, stackp *SPlayer2){
    CopyArr(Arr, &*Arrcop);
    Push(&*SBang, *Arrcop);
    CopyPlayer(P1, &*Pcop);
    Pushp(&*SPlayer1, *Pcop);
    CopyPlayer(P2, &*Pcop);
    Pushp(&*SPlayer2, *Pcop);
}

void UndoAll (TabBang *Arr, Stack *SBang, PLAYER *P1, PLAYER *P2, stackp *SPlayer1, stackp *SPlayer2){
    Pop (&*SBang, &*Arr);
    Popp (&*SPlayer1, &*P1);
    Popp (&*SPlayer2, &*P2);
}

void HitungJum (JumlahB *Jumlah, PLAYER P1, TabBang Arr){
    addresslist P;
    int i;
    boolean found;
    JCastle(*Jumlah) = 0;
    JTotal(*Jumlah) = 0;
    JVillage(*Jumlah) = 0;
    JFort(*Jumlah) = 0;
    JTotal(*Jumlah) =0;

    P = First(P1.ListB);
    while (P != NilList){
        i = 1;
        found = false;
        while (i <= NbElmtArr(Arr) && !(found)){
            if (Info(P) == i){ //kalo misalnya dia sama kayak indeks bangunan
                if(Elmt(Arr,i).type == 'C'){
                    JCastle(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'T'){
                    JTower(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'V'){
                    JVillage(*Jumlah)++;
				}
				else if(Elmt(Arr,i).type == 'F'){
                    JFort(*Jumlah)++;
				}
				found = true;
			}
			else{
				i++;
			}
		}
		P = Next(P);
    }
    JTotal(*Jumlah) = JCastle(*Jumlah) + JFort(*Jumlah) + JVillage(*Jumlah) + JTower(*Jumlah);
}

void CekKondisi (JumlahB jumlahku, JumlahB jumlahlawan, Condition *Kondisi){
    (*Kondisi).AU = false;
    (*Kondisi).S = false;
    (*Kondisi).B = false;
    (*Kondisi).ET = true;
    
    if (JTotal(jumlahlawan) == 3){
        (*Kondisi).S = true;
    }
    else if (JTower(jumlahlawan) == 4){
        (*Kondisi).AU = true;
    }
    else if (JTotal(jumlahku) == 9){
        (*Kondisi).B = true;
    }
}

void Move (TabBang *Arr, int *X, TabInt *T1, List *Tetangga, PLAYER P1, PLAYER P2, int P, boolean *ada, TabGraph ArrGraph){
    DaftarBangunan(P1.ListB, *Arr, &*T1);
    printf("Pilih bangunan asal pemindahan : ");
    STARTWORD();
    *X = WStringToInteger(CWord);
    
    if (Elmt(*Arr,ElmtStat(*T1,*X)).move){
            *Tetangga = Neighbors(&ArrGraph, ElmtStat(*T1,*X));
            AdaMove (*Tetangga, *Arr, P, &*ada, P1, P2);
            if (ada){
                Elmt(*Arr,ElmtStat(*T1,*X)).move = false;
                DaftarMove(*Tetangga, *Arr, &*T1, P, P1, P2);
                printf("Pilih bangunan tujuan pemindahan : ");
                STARTWORD();
                *X = WStringToInteger(CWord);
            }
            else {
                printf("Tidak ada tujuan yang tersedia\n");
            }
        }
    else{
        printf("Bangunan sudah memindahkan pasukan pada turn ini\n");
    }
}

void LevelUpUp(TabBang *(Arr), PLAYER P, int i){
    MATRIKS MC, MT, MF, MV;
    CreateEmptyMatriks(4,4, &MC);
    CreateEmptyMatriks(4,4, &MT);
    CreateEmptyMatriks(4,4, &MF);
    CreateEmptyMatriks(4,4, &MV);

    //MC
    ElmtMat(MC,1,1)=10;
    ElmtMat(MC,1,2)=40;
    ElmtMat(MC,1,3)=0;
    ElmtMat(MC,1,4)=40;

    ElmtMat(MC,2,1)=15;
    ElmtMat(MC,2,2)=60;
    ElmtMat(MC,2,3)=0;
    ElmtMat(MC,2,4)=0;

    ElmtMat(MC,3,1)=20;
    ElmtMat(MC,3,2)=80;
    ElmtMat(MC,3,3)=0;
    ElmtMat(MC,3,4)=0;

    ElmtMat(MC,4,1)=25;
    ElmtMat(MC,4,2)=100;
    ElmtMat(MC,4,3)=0;
    ElmtMat(MC,4,4)=0;

    //MT
    ElmtMat(MT,1,1)=5;
    ElmtMat(MT,1,2)=20;
    ElmtMat(MT,1,3)=1;
    ElmtMat(MT,1,4)=30;

    ElmtMat(MT,2,1)=10;
    ElmtMat(MT,2,2)=30;
    ElmtMat(MT,2,3)=1;
    ElmtMat(MT,2,4)=0;

    ElmtMat(MT,3,1)=20;
    ElmtMat(MT,3,2)=40;
    ElmtMat(MT,3,3)=1;
    ElmtMat(MT,3,4)=0;

    ElmtMat(MT,4,1)=30;
    ElmtMat(MT,4,2)=50;
    ElmtMat(MT,4,3)=1;
    ElmtMat(MT,4,4)=0;

    //MF
    ElmtMat(MF,1,1)=10;
    ElmtMat(MF,1,2)=20;
    ElmtMat(MF,1,3)=0;
    ElmtMat(MF,1,4)=80;

    ElmtMat(MF,2,1)=20;
    ElmtMat(MF,2,2)=40;
    ElmtMat(MF,2,3)=0;
    ElmtMat(MF,2,4)=0;

    ElmtMat(MF,3,1)=30;
    ElmtMat(MF,3,2)=60;
    ElmtMat(MF,3,3)=1;
    ElmtMat(MF,3,4)=0;

    ElmtMat(MF,4,1)=40;
    ElmtMat(MF,4,2)=80;
    ElmtMat(MF,4,3)=1;
    ElmtMat(MF,4,4)=0;

    //MV
    ElmtMat(MV,1,1)=5;
    ElmtMat(MV,1,2)=20;
    ElmtMat(MV,1,3)=0;
    ElmtMat(MV,1,4)=20;

    ElmtMat(MV,2,1)=10;
    ElmtMat(MV,2,2)=30;
    ElmtMat(MV,2,3)=0;
    ElmtMat(MV,2,4)=0;

    ElmtMat(MV,3,1)=15;
    ElmtMat(MV,3,2)=40;
    ElmtMat(MV,3,3)=0;
    ElmtMat(MV,3,4)=0;

    ElmtMat(MV,4,1)=20;
    ElmtMat(MV,4,2)=50;
    ElmtMat(MV,4,3)=0;
    ElmtMat(MV,4,4)=0;
    
    if (Elmt(*(Arr), i).type == 'C'){
        if ((Elmt(*(Arr), i).jum-Elmt(*(Arr), i).M/2)<0){
            printf("Jumlah pasukan Castle kurang untuk level up\n");
        }
        else{
            Elmt(*(Arr), i).jum=(Elmt(*(Arr), i).jum)-(Elmt(*(Arr), i).M)/2;
            Elmt(*(Arr), i).lev++;
            Elmt(*(Arr), i).A=ElmtMat(MC,Elmt(*(Arr), i).lev,1);
            Elmt(*(Arr), i).M=ElmtMat(MC,Elmt(*(Arr), i).lev,2);
            Elmt(*(Arr), i).P=ElmtMat(MC,Elmt(*(Arr), i).lev,3);
            printf("Level Castle-mu meningkat menjadi %d!\n", Elmt(*(Arr), i).lev);
        }
    }
    else if (Elmt(*(Arr), i).type == 'T'){
        if ((Elmt(*(Arr), i).jum-Elmt(*(Arr), i).M/2)<0){
            printf("Jumlah pasukan Tower kurang untuk level up\n");
        }
        else{
            Elmt(*(Arr), i).jum=(Elmt(*(Arr), i).jum)-(Elmt(*(Arr), i).M)/2;
            Elmt(*(Arr), i).lev++;
            Elmt(*(Arr), i).A=ElmtMat(MT,Elmt(*(Arr), i).lev,1);
            Elmt(*(Arr), i).M=ElmtMat(MT,Elmt(*(Arr), i).lev,2);
            Elmt(*(Arr), i).P=ElmtMat(MT,Elmt(*(Arr), i).lev,3);
            printf("Level Tower-mu meningkat menjadi %d!\n", Elmt(*(Arr), i).lev);
        }
    }

    else if (Elmt(*(Arr), i).type == 'F'){
        if ((Elmt(*(Arr), i).jum-Elmt(*(Arr), i).M/2)<0){
            printf("Jumlah pasukan Fort kurang untuk level up\n");
        }
        else{
            Elmt(*(Arr), i).jum=(Elmt(*(Arr), i).jum)-(Elmt(*(Arr), i).M)/2;
            Elmt(*(Arr), i).lev++;
            Elmt(*(Arr), i).A=ElmtMat(MF,Elmt(*(Arr), i).lev,1);
            Elmt(*(Arr), i).M=ElmtMat(MF,Elmt(*(Arr), i).lev,2);
            Elmt(*(Arr), i).P=ElmtMat(MF,Elmt(*(Arr), i).lev,3);
            printf("Level Fort-mu meningkat menjadi %d!\n", Elmt(*(Arr), i).lev);
        }
    }

    else{
        if ((Elmt(*(Arr), i).jum-Elmt(*(Arr), i).M/2)<0){
            printf("Jumlah pasukan Village kurang untuk level up\n");
        }
        else{
            Elmt(*(Arr), i).jum=(Elmt(*(Arr), i).jum)-(Elmt(*(Arr), i).M)/2;
            Elmt(*(Arr), i).lev++;
            Elmt(*(Arr), i).A=ElmtMat(MF,Elmt(*(Arr), i).lev,1);
            Elmt(*(Arr), i).M=ElmtMat(MF,Elmt(*(Arr), i).lev,2);
            Elmt(*(Arr), i).P=ElmtMat(MF,Elmt(*(Arr), i).lev,3);
            printf("Level Village-mu meningkat menjadi %d!\n", Elmt(*(Arr), i).lev);
        }
    }
}