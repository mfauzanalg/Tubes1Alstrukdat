void attack(PLAYER player_serang){
    int temp_critical, temp_Attack_Up;
    List L1, L2;
    address P, P_next;
    address P2, P2_next;
    address P_player1att, P_player2att;
    Bangunan mau_attack;
    Bangunan mau_attack2;
    address Psinggah;
    address P2singgah;
    int infop;
    array arr_temp, arr_diserang;
    int diserang;
    int infop2;
    array arr2_temp, arr2_diserang;
    int jum_pasukan;
    int pindah_pemilik;
    

    printf("Daftar Bangunan\n");
    
    if (player_serang.num == 1){
        if (!(IsEmpty(L1))){
            P = First(L1);
            P_next = next(First(L1));
            for (int i =1 ; i<= NbElmtList(L1); i++){
                printf("%d. ", i);  
                if (i == 1){
                    DelFirst(&L1, &P_player1att);
                    infop = info(&P_player1att);
                    arr_temp[i] = &P_player1att;

                }
                else {
                    DelAfter(L,P_next,P);
                    infoP = info(P_next);
                     arr_temp[i] = P_next;
                }
                    if (mau_attack[infop].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack[infop].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack[infop].type == 'v'){
                        printf("Village ");
                    }
                    printf("(%d,%d) ", mau_attack[infop].letak);
                    printf("%d ", mau_attack[infop].jum)
                    printf("lv. ");
                    printf("%d\n",mau_attack[infop]. lev);
                } 
                printf("Bangunan yang digunakan untuk menyerang: ");
                scanf("%d\n", diserang);
                printf("Daftar bangunan yang dapat diserang");
                /* fungsi lewat graph
                
                
                
                
                */ if (!(IsEmpty(L2))){
            P2 = First(L2);
            P2_next = next(First(L2));
            for (int i =1 ; i<= NbElmtList(L2); i++){
                printf("%d. ", i);  
                if (i == 1){
                    DelFirst(&L2, &P_player2att);
                    infop2 = info(&P_player2att);
                    arr2_temp[i] = &P_player2att;

                }
                else {
                    DelAfter(L2,P2_next,P2);
                    infoP2 = info(P2_next);
                     arr2_temp[i] = P2_next;
                }
                    if (mau_attack2[infop].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack2[infop].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack2[infop].type == 'v'){
                        printf("Village ");
                    }
                    printf("(%d,%d) ", mau_attack2[infop].letak);
                    printf("%d ", mau_attack2[infop].jum)
                    printf("lv. ");
                    printf("%d\n",mau_attack2[infop]. lev);

                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                    mau_attack[diserang].jum - jum_pasukan;
                    if (jum_pasukan >= mau_attack2[jum_pasukan].jum){
                        mau_attack2[jum_pasukan].jum = jum_pasukan - mau_attack2[jum_pasukan].jum;
                        printf("Bangunan menjadi milikmu");
                        DelP(*L2,pindah_pemilik );
                        InsertVFirst(*L1, pindah_pemilik);

                    }
                    else if (jum_pasukan < mau_attack2[jum_pasukan].jum){
                        mau_attack2[jum_pasukan].jum = mau_attack2[jum_pasukan].jum - jum_pasukan;
                        printf("Bangunan gagal direbut");

                    }
        } 
        }
    }
    else //yang nyerang pemain 2
    {   if (!(IsEmpty(L2))){
            P = First(L2);
            P_next = next(First(L2));
        for (int k =1 ; k<= NbElmtList(L2); k++){
        printf("%d ", k);  
        
          printf("%d. ", i);  
                if (i == 1){
                    DelFirst(&L1, &P_player1att);
                    infop = info(&P_player1att);
                    arr_temp[i] = &P_player1att;

                }
                else {
                    DelAfter(L,P_next,P);
                    infoP = info(P_next);
                     arr_temp[i] = P_next;
                }
                    if (mau_attack[infop].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack[infop].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack[infop].type == 'v'){
                        printf("Village ");
                    }
                    printf("(%d,%d) ", mau_attack[infop].letak);
                    printf("%d ", mau_attack[infop].jum)
                    printf("lv. ");
                    printf("%d\n",mau_attack[infop].lev);
                } 
                
                printf("Bangunan yang digunakan untuk menyerang: ");
                scanf("%d\n", diserang);
                printf("Daftar bangunan yang dapat diserang");
                /* fungsi lewat graph
                
                
                
                
                */ if (!(IsEmpty(L1))){
            P2 = First(L1);
            P2_next = next(First(L1));
            for (int i =1 ; i<= NbElmtList(L1); i++){
                printf("%d. ", i);  
                if (i == 1){
                    DelFirst(&L1, &P_player2att);
                    infop2 = info(&P_player2att);
                    arr2_temp[i] = &P_player2att;

                }
                else {
                    DelAfter(L1,P2_next,P2);
                    infoP2 = info(P2_next);
                     arr2_temp[i] = P2_next;
                }
                    if (mau_attack2[infop].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack2[infop].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack2[infop].type == 'v'){
                        printf("Village ");
                    }
                    printf("(%d,%d) ", mau_attack2[infop].letak);
                    printf("%d ", mau_attack2[infop].jum)
                    printf("lv. ");
                    printf("%d\n",mau_attack2[infop]. lev);

                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                    mau_attack[diserang].jum - jum_pasukan;
                    if (jum_pasukan >= mau_attack2[jum_pasukan].jum){
                        mau_attack2[jum_pasukan].jum = jum_pasukan - mau_attack2[jum_pasukan].jum;
                        printf("Bangunan menjadi milikmu");
                        DelP(*L1,pindah_pemilik );
                        InsertVFirst(*L2, pindah_pemilik);

                    }
                    else if (jum_pasukan < mau_attack2[jum_pasukan].jum){
                        mau_attack2[jum_pasukan].jum = mau_attack2[jum_pasukan].jum - jum_pasukan;
                        printf("Bangunan gagal direbut");

                    }
        
        } 
        }} 
    }



}