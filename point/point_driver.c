#include <stdio.h>
#include <math.h>
#include "../boolean/boolean.h"
#include "point.h"

int main(){
    POINT p1;
    printf("Masukkan X dan Y untuk membuat point : \n\n");
    BacaPOINT(&p1);
    printf("\n");
    printf("Hasil point yang dimaksud   :  ");
    TulisPOINT(p1);
    printf("\n");

return 0;
}
