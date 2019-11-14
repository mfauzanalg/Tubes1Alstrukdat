void attack(PLAYER player_serang){
    int temp_critical, temp_Attack_Up;
    List L1, L2, L3; //list bangunan
    address P, P2, P3;
    address P_player1att, P_player2att;
    Bangunan mau_attack;
    Bangunan mau_attack2;
    int infop;
    array arr_temp, arr_diserang;
    int diserang, serang; //yang dipilih diserang dan menyerang kebalik
    int infop2;
    array arr2_temp, arr2_diserang;
    int jum_pasukan;
    int pindah_pemilik;
    boolean Aserang;
    int i,k;
    

    
    
   


void bangunan_sendiri() //mengeprint bangunan sendiri

{address P;
int i;
infotype infop;

    printf("Daftar Bangunan\n");
    if (player_serang.num == 1){
        P = First(L1);
    }
    else //kalau player 2 listnya akan menunjuk ke list l2
    {
        P = First(L2);
    }

        if (P != Nil){
            i =1;
            while (P != Nil){

                printf("%d. ", i);  
                   
                    infop = info(P);
                    arr_temp[i] = infop;
                    P = Next(P);
                    i += 1;

                
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
        bangunan_diserang(); //manggil fungsi bangunan yang dapat diserang
}


void bangunan_diserang() //fungsi ngeprint bangunana yang bisa diserang
{int k;
infotype infop2;
address P2;
boolean terserang_Valid = false;

if (player_serang.num == 1){
        P2 = First(L2);
    }
    else //kalau player 2
    {
        P2 = First(L1);
    }

    k =1;
     if (P2 != Nil){
         
            
            while (P2 != Nil){

                printf("%d. ", k);  
                   
                    if (IsAdjacent(*arr, info(P2), diserang)){
                    infop = info(P2);
                    arr_temp[k] = infop;
                    P2 = Next(P2);
                    k += 1;
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
                    terserang_Valid = true; //kalau gavalid minta bangunan untuk menyerang lagi
                     }
                     else //tak sesuai lanjut
                     {
                        P2 = Next(P2);
                     }
                    
                } 
        }

        if (!IsEmpty(L3)){
            
            P2 = First(L3);
            while (P2 != Nil){

                printf("%d. ", k);  
                   
                    if (IsAdjacent(*arr, info(P2), diserang)){
                    infop = info(P2);
                    arr_temp[k] = infop;
                    P2 = Next(P2);
                    k += 1;
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
                    terserang_Valid = true; //kalau gavalid minta bangunan untuk menyerang lagi
                     }
                     else //tak sesuai lanjut
                     {
                        P2 = Next(P2);
                     }
                    
                } 

        }

        if (!terserang_Valid){
            printf("Tidak ada bangunan yang bisa diserang dengan bangunan yang anda pilih sekarang");
            printf("Pilih bangunan lain untuk menyerang");
            mau_attack[serang].checkserang = false;  //bangunan di set agar tak bisa dipakai untuk mennyerang
            bangunan_sendiri(); //manggil fungsi untuk serang baru
        }
        deploy(); //fungsi nyerang
}


void deploy() //fungsi untuk hasil serang-menyerang
{
printf("Jumlah pasukan: ");
scanf("%d\n", jum_pasukan);

if (temp_critical > 0){ //skill critical
    jum_pasukan = 2*jum_pasukan;
    temp_critical -= 1;

}

if (mau_attack2[serang].p == true){ //kalau punya shield
    jum_pasukan = (3*jum_pasukan)/4;
    mau_attack[diserang].jum = mau_attack[diserang].jum - jum_pasukan;
     }

        if (jum_pasukan >= mau_attack2[serang].jum){
            mau_attack2[serang].jum = jum_pasukan - mau_attack2[serang].jum;
            printf("Bangunan menjadi milikmu");
             DelP(*L2,pindah_pemilik );
            InsertVFirst(*L1, pindah_pemilik); //masuk ke list kepemilikan

            }
         else if (jum_pasukan < mau_attack2[serang].jum){
            mau_attack2[serang].jum = mau_attack2[serang].jum - jum_pasukan;
            printf("Bangunan gagal direbut");
                    }
                     mau_attack[serang].checkserang = false;  //bangunan tak bisa nyerang lagi  


}

/* if (player_serang.num == 1){
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
                fungsi lewat graph
                
                
                
                
                 if (!(IsEmpty(L2))){
                     P2 = First(L2);
                     k =1;
            
            while(P2 != Nil){
                printf("%d. ", k);

                if (IsAdjacent(*arr, info(P2), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[k] = infop2;
                     P2 = Next(P2);
                     k += 1;

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

                    if (!IsEmpty(L3)){
                    P3= First(L3);

                    while (P3 != Nil){
                    printf("%d. ", k);

                if (IsAdjacent(*arr, info(P3), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[k] = infop2;
                     P3 = Next(P3);
                     k += 1;

                  }
                  else
                  {
                      P3 = Next(P3);
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
                    }
                    }
                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                     if (mau_attack2[serang].p == true){
                        jum_pasukan = (3*jum_pasukan)/4;
                    mau_attack[diserang].jum = mau_attack[diserang].jum - jum_pasukan;
                     }
                    if (jum_pasukan >= mau_attack2[serang].jum){
                        mau_attack2[serang].jum = jum_pasukan - mau_attack2[serang].jum;
                        printf("Bangunan menjadi milikmu");
                        DelP(*L2,pindah_pemilik );
                        InsertVFirst(*L1, pindah_pemilik);

                    }
                    else if (jum_pasukan < mau_attack2[serang].jum){
                        mau_attack2[serang].jum = mau_attack2[serang].jum - jum_pasukan;
                        printf("Bangunan gagal direbut");

                    }
                     mau_attack[serang].checkserang = false;
        
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
                 fungsi lewat graph
                
                
                
                
                 if (!(IsEmpty(L1))){
                 P2 = First(L1);
                 i =1;
            
            while (P2 != Nil){
                printf("%d. ", i);  
                  if (IsAdjacent(*arr, info(P2), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[i] = infop2;
                     P2 = Next(P2);
                     i += 1;

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
            }
                if (!IsEmpty(L3)){
                    P3 = First(L3);

                    while (P3 != Nil){
                    printf("%d. ", k);

                if (IsAdjacent(*arr, info(P3), diserang)){
                    infop2 = info(&P_player2att);
                    arr2_temp[i] = infop2;
                     P3 = Next(P3);
                     i += 1;

                  }
                  else
                  {
                      P3 = Next(P3);
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
                }

                    printf("Jumlah pasukan: ");
                    scanf("%d\n", jum_pasukan);
                    if (mau_attack2[serang].p == true){
                        jum_pasukan = (3*jum_pasukan)/4;
                    }
                    mau_attack[diserang].jum = mau_attack[diserang].jum - jum_pasukan;
                    if (jum_pasukan >= mau_attack2[serang].jum){
                        mau_attack2[serang].jum = jum_pasukan - mau_attack2[serang].jum;
                        printf("Bangunan menjadi milikmu");
                        DelP(*L1,pindah_pemilik );
                        InsertVFirst(*L2, pindah_pemilik);

                    }
                    else if (jum_pasukan < mau_attack2[jum_pasukan].jum){
                        mau_attack2[serang].jum = mau_attack2[serang].jum - jum_pasukan;
                        printf("Bangunan gagal direbut");

                    }
        
        }               mau_attack[jum_pasukan].checkserang = false;
        }
    }



} 
*/