#include "mesinword.h"
#include <stdio.h>

int main(){
  STARTWORD();
  //membandingkan input user dengan kata "OKE"
  if (CompareTwoStrings(CWord.TabKata, "OKE") == 1){
    printf("SAMA\n");
  }
  else{
    printf("TIDAK SAMA\n");
  }
}

//belum semua fungsi, ini cuma fungsi yg compare two strings ajaa