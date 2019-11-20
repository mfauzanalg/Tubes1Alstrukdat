

void bangunan_sendiri() //mengeprint bangunan sendiri, fungsi utama

{   int temp_critical, temp_Attack_Up;
    List L1; //list bangunan milik p1,p2, dan tidak keduanya
    address P; //menunjuk di list bangunan
    int infop; //dari list diambil indeksnya
    array arr_temp; //buat array agar bisa ipilih bangunan ke berapa oleh user dari daftar bangunan
    int diserang, serang; //yang dipilih diserang dan menyerang kebalik

    int i;

    printf("Daftar Bangunan\n");
    if (player_serang.num == 1){//kalau player 1
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
                    Elmt(arr_temp,i) = infop;
                    P = Next(P);
                    i += 1;

                
                    if (Elmt(Arr,infop).type == 'C'){
                        printf("Castle ");
                    }
                    else if (Elmt(Arr,infop).type == 'T'){
                        printf("Tower ");
                    }

                    else if(Elmt(Arr,infop).type== 'V'){
                        printf("Village ");
                    }

                    else if(Elmt(Arr,infop).type== 'F'){
                        printf("Fort ");
                    }
                    
                    printf("(%d,%d) ", Elmt(Arr,infop).letak);
                    printf("%d ", Elmt(Arr,infop).jum;
                    printf("lv. ");
                    printf("%d\n",Elmt(Arr,infop).lev);
                } 
        }
        printf("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d\n", &diserang);
        while ((serang < 0) || (serang>k)){
            printf("Tidak ada bangunan yang dimaksud, mohon input ulang!\n");
            printf("Bangunan yang digunakan untuk menyerang: ");
            scanf("%d\n", &diserang);
        }
        printf("Daftar bangunan yang dapat diserang");
        bangunan_diserang(); //manggil fungsi bangunan yang dapat diserang
        printf("Bangunan yang diserang: ");
        scanf("%d\n", &serang);
        while ((serang < 0) || (serang>k)){
            printf("Tidak ada bangunan yang dimaksud, mohon input ulang!\n");
            printf("Bangunan yang diserang: ");
            scanf("%d\n", &serang);
        }
}


void bangunan_diserang() //fungsi ngeprint bangunana yang bisa diserang
{int k;
address P2;
boolean terserang_Valid = false;
List L2, L3; //list bangunan milik p1,p2, dan tidak keduanya
array arr_temp2; //buat array agar bisa ipilih bangunan ke berapa oleh user dari daftar bangunan

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
                    Elmt(arr_temp2,k)= infop;
                    P2 = Next(P2);
                    k += 1;
                    if (Elmt(Arr,infop).type == 'C'){
                        printf("Castle ");
                    }
                    else if (Elmt(Arr,infop).type  == 'T'){
                        printf("Tower ");
                    }

                    else if(Elmt(Arr,infop).type  == 'V'){
                        printf("Village ");
                    }

                    else if(Elmt(Arr,infop).type== 'F'){
                        printf("Fort ");
                    }

                    printf("(%d,%d) ", Elmt(Arr,infop).letak );
                    printf("%d ", Elmt(Arr,infop).jum);
                    printf("lv. ");
                    printf("%d\n",Elmt(Arr,infop).lev);
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
                    Elmt(arr_temp2,k) = infop;
                    P2 = Next(P2);
                    k += 1;
                    if (Elmt(Arr,infop).type == 'C'){
                        printf("Castle ");
                    }
                    else if (Elmt(Arr,infop).type == 'T'){
                        printf("Tower ");
                    }

                    else if(Elmt(Arr,infop).type == 'V'){
                        printf("Village ");
                    }

                    else if(Elmt(Arr,infop).type== 'F'){
                        printf("Fort ");
                    }

                    printf("(%d,%d) ", Elmt(Arr,infop).letak);
                    printf("%d ", Elmt(Arr,infop).jum);
                    printf("lv. ");
                    printf("%d\n",Elmt(Arr,infop).lev);
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
            bangunan_sendiri(); //manggil fungsi untuk serang baru
        }
        deploy(); //fungsi nyerang
}


void deploy() //fungsi untuk hasil serang-menyerang
{    int jum_pasukan; //masukan user berapa pasukan yang digunakan untuk nyerang
     infotypelist pindah_pemilik; //buat temp pindah kepemilikan
     
printf("Jumlah pasukan: ");
scanf("%d\n", &jum_pasukan);
while ((jum_pasukan > Elmt(Arr,Elmt(arr_temp,diserang)).jum) || (jum_pasukan <=0)){
    printf("Jumlah pasukan yang dimasukkan tidak sesuai dengan jumlah pasukan di bangunan anda, masukkan ulang!\n");
    printf("Jumlah pasukan: ");
    scanf("%d\n", &jum_pasukan);
}

if (Elmt(Arr,Elmt(arr_temp2,serang)).U > 0){ //untuk nyerang yang bukan punya siapa2
            if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = 0;  //biar ga dianggep bukan punya siapa2
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = jum_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).U;
            printf("Bangunan menjadi milikmu");
            DelP(*L3,pindah_pemilik );
            InsertVFirst(*L1, pindah_pemilik); //masuk ke list kepemilikan
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi

            }
            else if (jum_pasukan < Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = Elmt(Arr,Elmt(arr_temp2,serang)).U - jum_pasukan; //masih dianggap kalau diserang ngurang ga konstan
            printf("Bangunan gagal direbut");
                    }
                     Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi 
}

else if (temp_critical > 0){ //skill critical(belum selesai karena harus include semuanya)
    jum_pasukan = 2*jum_pasukan;
    temp_critical -= 1;
    
    

}

else if (Elmt(Arr,Elmt(arr_temp2,serang)).p == true){ //kalau punya shield
    jum_pasukan = (3*jum_pasukan)/4;
    
    if (Elmt(Arr,Elmt(arr_temp2,serang)).U > 0){ //untuk nyerang yang bukan punya siapa2
            if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = 0; //biar ga dianggep bukan punya siapa2
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = jum_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).U;
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = 4/3 * Elmt(Arr,Elmt(arr_temp2,serang)).jum ;
            printf("Bangunan menjadi milikmu");
            DelP(*L3,pindah_pemilik );
            InsertVFirst(*L1, pindah_pemilik); //masuk ke list kepemilikan
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi

            }
            else if (jum_pasukan < Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = Elmt(Arr,Elmt(arr_temp2,serang)).U - jum_pasukan; //masih dianggap kalau diserang ngurang ga konstan
            printf("Bangunan gagal direbut");
                    }
                     Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi 
}
    else{ //untuk nyerang pemain lain
        if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).jum){
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = jum_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).jum;
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = 4/3 * Elmt(Arr,Elmt(arr_temp2,serang)).jum ;
            printf("Bangunan menjadi milikmu");
            DelP(*L2,pindah_pemilik );
            InsertVFirst(*L1, pindah_pemilik); //masuk ke list kepemilikan
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi
            if (Elmt(Arr,Elmt(arr_temp2,serang)).lev != 1){ //kalau bangunan yang baru jadi milik pemain yang nyerang bukan level 1
                if (Elmt(Arr,Elmt(arr_temp2,serang)).type == 'C'){
                    Elmt(Arr,Elmt(arr_temp2,serang)).A = 10;
                    Elmt(Arr,Elmt(arr_temp2,serang)).M = 40;
                }

                else if (Elmt(Arr,Elmt(arr_temp2,serang)).type == 'T'){
                    Elmt(Arr,Elmt(arr_temp2,serang)).A = 5;
                    Elmt(Arr,Elmt(arr_temp2,serang)).M = 20;
                }

                else if (Elmt(Arr,Elmt(arr_temp2,serang)).type == 'F'){
                    Elmt(Arr,Elmt(arr_temp2,serang)).A = 10;
                    Elmt(Arr,Elmt(arr_temp2,serang)).M = 20;
                    Elmt(Arr,Elmt(arr_temp2,serang)).P = false;
                }

                else if (Elmt(Arr,Elmt(arr_temp2,serang)).type == 'C'){
                    Elmt(Arr,Elmt(arr_temp2,serang)).A = 5;
                    Elmt(Arr,Elmt(arr_temp2,serang)).M = 20;
                }
                }

            }
            else if (jum_pasukan < Elmt(Arr,Elmt(arr_temp2,serang)).jum){
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = Elmt(Arr,Elmt(arr_temp2,serang)).jum - jum_pasukan;
            printf("Bangunan gagal direbut");
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi 
                    }
                      

    }

}


else{ //untuk nyerang pemain lain
        if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).jum){
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = jum_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).jum;
            printf("Bangunan menjadi milikmu");
             DelP(*L2,pindah_pemilik );
            InsertVFirst(*L1, pindah_pemilik); //masuk ke list kepemilikan
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi

            }
         else if (jum_pasukan < Elmt(Arr,Elmt(arr_temp2,serang)).jum){
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = Elmt(Arr,Elmt(arr_temp2,serang)).jum - jum_pasukan;
            printf("Bangunan gagal direbut");
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi  
                    }
                     

    }
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