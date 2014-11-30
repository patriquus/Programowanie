#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// PROG2 tylko, ze na wskaznikach
//to bylo najciekawsze na tych zajeciach 
struct tab {
       double x[100];
       };

int main () {

int i;
double x,q;
double *ptr[100]; //tablica jako wskaznik
struct tab *t;

FILE *pFile;


pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\031114\\prog3.txt", "wt");
fseek(pFile, 0, SEEK_SET);

for(i=0; i<100; i++) {
           t = (tab*)malloc(sizeof(tab)); // alokacja pamieci dla tablicy
}

for(i=0; i<100; i++) {
           x = tan(i*M_PI/180.0) ;// tangens w radianach (1 rad = pi)}
           t->x[i] = x;     
           printf("%4d %8.4f %8.4f \n", i, x, t->x[i]);
           }
/*       
for(i=0; i<100; i++) {

        if (tab[i] > 0.5 && tab[i] < 1.5) {         // wyswietlanie katow z przedzialu 0.5 - 1.5
         printf(               "%4d %8.4f  \n", i, tab[i]);  
         }
         
         else {
        fprintf(pFile,        "%4d %8.4f \n", i, tab[i]); // katy spoza przedzialu - na dysk
        }         
         }
        
fclose( pFile);
*/
/*
printf("--- \n");

// Wyswietlanie danych z pliku
pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\031114\\prog1.txt", "rt");
fseek(pFile, 0, SEEK_SET);

int k;
float y;
for(i = 0; i<100; i++) {
         fscanf(pFile, "%d %f  \n", &k, &y); // referencja &
         printf("%4d %8.4f \n", i, y);      
         }

fclose( pFile);
*/

  free(p);

    system("PAUSE");
    return 0;
}


