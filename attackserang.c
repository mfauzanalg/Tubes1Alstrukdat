void attack(PLAYER player_serang){
    int temp_critical, temp_Attack_Up;
    List L1, L2, L3;
    address P, P2, P3;
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
    boolean Aserang;
    

    printf("Daftar Bangunan\n");
    
    if (player_serang.num == 1){
        if (!(IsEmpty(L1))){
            P = First(L1);
            for (int i =1 ; i<= NbElmtList(L1); i++){
                printf("%d. ", i);  
                
                    
                    infop = info(P);
                    arr_temp[i] = infop;
                    P = Next(P);

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
                    printf("%d ", mau_attack[infop].jum);
                    printf("lv. ");
                    printf("%d\n",mau_attack[infop]. lev);
                } 
        }
                printf("Bangunan yang digunakan untuk menyerang: ");
                scanf("%d\n", diserang);
                printf("Daftar bangunan yang dapat diserang");
                /* fungsi lewat graph
                
                
                
                
                */ if (!(IsEmpty(L2))){
            P2 = First(L2);
            
            for (int k =1 ; k<= NbElmtList(L2); k++){
                printf("%d. ", k);

                if (IsAdjacent(*arr, info(P2), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[k] = infop2;
                     P2 = Next(P2);

                  }
                  else
                  {
                      P2 = Next(P2);
                  }

                
                    if (mau_attack2[infop2].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack2[infop2].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack2[infop2].type == 'v'){
                        printf("Village ");
                    }
            }
                    printf("(%d,%d) ", mau_attack2[infop2].letak);
                    printf("%d ", mau_attack2[infop2].jum);
                    printf("lv. ");
                    printf("%d\n",mau_attack2[infop2]. lev);

                    P3= First(L3);


                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                     if (mau_attack2[jum_pasukan].p == true){
                        jum_pasukan = (3*jum_pasukan)/4;
                    mau_attack[diserang].jum = mau_attack[diserang].jum - jum_pasukan;
                     }
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
                     mau_attack[jum_pasukan].checkserang = false;
        
        }
    }
    else //yang nyerang pemain 2
    {   if (!(IsEmpty(L2))){
            P = First(L2);
        for (int k =1 ; k<= NbElmtList(L2); k++){
          printf("%d. ", k);  
        
           
                
                    infop = info(P);
                    arr_temp[i] = infop;
                    P = Next(P);

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
                    printf("%d ", mau_attack[infop].jum);
                    printf("lv. ");
                    printf("%d\n",mau_attack[infop]. lev);
                } 
                
                printf("Bangunan yang digunakan untuk menyerang: ");
                scanf("%d\n", diserang);
                printf("Daftar bangunan yang dapat diserang");
                /* fungsi lewat graph
                
                
                
                
                */ if (!(IsEmpty(L1))){
            P2 = First(L1);
            
            for (int i =1 ; i<= NbElmtList(L1); i++){
                printf("%d. ", i);  
                  if (IsAdjacent(*arr, info(P2), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[i] = infop2;
                     P2 = Next(P2);

                  }
                  else
                  {
                      P2 = Next(P2);
                  }
                  
           
                    if (mau_attack2[infop2].type == 'c'){
                        printf("Castle ");
                    }
                    else if (mau_attack2[infop2].type == 't'){
                        printf("Tower ");
                    }

                    else if(mau_attack2[infop2].type == 'v'){
                        printf("Village ");
                    }
                    printf("(%d,%d) ", mau_attack2[infop2].letak);
                    printf("%d ", mau_attack2[infop2].jum);
                    printf("lv. ");
                    printf("%d\n",mau_attack2[infop2]. lev);

                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                    if (mau_attack2[jum_pasukan].p == true){
                        jum_pasukan = (3*jum_pasukan)/4;
                    }
                    mau_attack[diserang].jum = mau_attack[diserang].jum - jum_pasukan;
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
        
        }               mau_attack[jum_pasukan].checkserang = false;
        }} 
    }



}