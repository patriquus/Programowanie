#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

int a;
int *p;

p=(int*)malloc(sizeof(int));
a = 4;
p = &a;

printf("Wartosc a: %4d \n", a);
printf("Adres a: %4d \n\n", &a);
printf("Wartosc *p: %4d \n", *p);
printf("Adres przechowywany w p: %4d \n\n", p);
printf("Adres p: %4d \n\n", &p);

    system("PAUSE");
    return 0;
}


