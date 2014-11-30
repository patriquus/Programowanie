#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// PROG1 tylko, ze na tablicy

int main () {

int i;
double tab[100];
FILE *pFile;

pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\031114\\prog2.txt", "wt");
fseek(pFile, 0, SEEK_SET);

for(i=0; i<100; i++) {
           tab[i] = tan(i*M_PI/180.0);     // tangens w radianach (1 rad = pi)}
           }
        
for(i=0; i<100; i++) {

        if (tab[i] > 0.5 && tab[i] < 1.5) {         // wyswietlanie katow z przedzialu 0.5 - 1.5
         printf(               "%4d %8.4f  \n", i, tab[i]);  
         }
         
         else {
        fprintf(pFile,        "%4d %8.4f \n", i, tab[i]); // katy spoza przedzialu - na dysk
        }         
         }
         
fclose( pFile);

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
    system("PAUSE");
    return 0;
}


