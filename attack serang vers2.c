

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

        if (P != NilList){
            i =1;
            while (P != NilList){

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
     if (P2 != NilList){
         
            
            while (P2 != NilList){

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

        if (!IsEmptyList(L3)){
            
            P2 = First(L3);
            while (P2 != NilList){

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
        } //ga jadi nyerang kalau ga ada bangunan yang bisa diserang oleh bangunan yang dipilih
        else{
        deploy(); //fungsi nyerang
        }
}


void deploy() //fungsi untuk hasil serang-menyerang
{    int jum_pasukan; //masukan user berapa pasukan yang digunakan untuk nyerang
     infotypelist pindah_pemilik; //buat temp pindah kepemilikan
     int temp_pasukan;
     
printf("Jumlah pasukan: ");
scanf("%d\n", &jum_pasukan);
while ((jum_pasukan > Elmt(Arr,Elmt(arr_temp,diserang)).jum) || (jum_pasukan <=0)){
    printf("Jumlah pasukan yang dimasukkan tidak sesuai dengan jumlah pasukan di bangunan anda, masukkan ulang!\n");
    printf("Jumlah pasukan: ");
    scanf("%d\n", &jum_pasukan);
}

Elmt(Arr,Elmt(arr_temp,diserang)).jum= Elmt(Arr,Elmt(arr_temp,diserang)).jum - jum_pasukan; //ngurangin pasukan di bangunan yang buat nyerang
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
            Elmt(Arr,Elmt(arr_temp2,serang)).U -=  jum_pasukan; //masih dianggap kalau diserang ngurang ga konstan
            printf("Bangunan gagal direbut");
                    }
                     Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi 
}
/*

else if (temp_critical > 0){ //skill critical(belum selesai karena harus include semuanya) agak bingung jadi di komen dulu
    temp_pasukan = jum_pasukan; //biar jumlah pasukan asli tak berpengaruh ketika serangan berhasil
    jum_pasukan = 2*jum_pasukan;
     (*Pl).IsCriticalHit = false;

     if (Elmt(Arr,Elmt(arr_temp2,serang)).U > 0){ //untuk nyerang yang bukan punya siapa2
            if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = 0;  //biar ga dianggep bukan punya siapa2
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).U;
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

    else if (Elmt(Arr,Elmt(arr_temp2,serang)).p == true){ //kalau punya shield
    jum_pasukan = (3*jum_pasukan)/4;
    
    if (Elmt(Arr,Elmt(arr_temp2,serang)).U > 0){ //untuk nyerang yang bukan punya siapa2
            if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = 0; //biar ga dianggep bukan punya siapa2
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).U;
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
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).jum;
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
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).jum;
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

    */

    
    

}

else if (Elmt(Arr,Elmt(arr_temp2,serang)).p == true){ //kalau punya shield
    temp_pasukan = jum_pasukan; //disimpan nilai asli jumlah pasukannya
    jum_pasukan = (3*jum_pasukan)/4;
    
    if (Elmt(Arr,Elmt(arr_temp2,serang)).U > 0){ //untuk nyerang yang bukan punya siapa2
            if (jum_pasukan >= Elmt(Arr,Elmt(arr_temp2,serang)).U){
            Elmt(Arr,Elmt(arr_temp2,serang)).U = 0; //biar ga dianggep bukan punya siapa2
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).U;
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
            Elmt(Arr,Elmt(arr_temp2,serang)).jum = temp_pasukan - Elmt(Arr,Elmt(arr_temp2,serang)).jum;
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
            Elmt(Arr,Elmt(arr_temp2,serang)).jum -= jum_pasukan;
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
            Elmt(Arr,Elmt(arr_temp2,serang)).jum -=  jum_pasukan;
            printf("Bangunan gagal direbut");
            Elmt(Arr,Elmt(arr_temp,diserang)).attack = false;  //bangunan tak bisa nyerang lagi  
                    }
                     

    }
}

