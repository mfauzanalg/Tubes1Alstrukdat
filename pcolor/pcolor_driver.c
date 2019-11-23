/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"

int main() {
    print_red('R');
    printf("\n");
    print_green('G');
    printf("\n");
    print_magenta('M');
    printf("\n");
    print_cyan('C');
    printf("\n");
    print_yellow('Y');
    printf("\n");
    print_blue('B');
    printf("\n");

    return 0;
}
