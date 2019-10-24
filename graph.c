#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
#include "list.h"
#include "graph.h"

void CreateEmptyGraph(TabGraph *Arr, int maxel, MATRIKS *Mat){
/* array untuk representasi graph, array berisikan list of bangunan yang terhubung */
	int i, j;
	MaxElArr(*Arr) = maxel;
	TI(*Arr) = (ElType1*) malloc((maxel+1)*sizeof(ElType1));
	for (i = IdxMin;i <= MaxElArr(*Arr); i++){
		CreateEmptyList(&Elmt(*Arr, i));
		for (j = IdxMin; j <= MaxElArr(*Arr); j++){
			if (ElmtMat(*Mat, i, j) == 1){
				InsVLast(&Elmt(*Arr, i), j);
			}
		}
	}
}

boolean IsAdjacent(TabGraph *Arr, int a, int b){
    if (Search (Elmt(*Arr, a), b) == NilList){
        return false;
    }
    else{
        return true;
    }
}

List Neighbors(TabGraph *Arr, int a){
    return (Elmt(*Arr, a));
}
