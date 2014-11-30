#include <stdio.h>
#include <stdlib.h>

int main () {
    
     int A[3][3], X[3], B[3], n; //deklaracja tablicy
    
    A[0][0] = 1;
    A[0][1] = 5;
    A[0][2] = 7;
    A[1][0] = 4;
    A[1][1] = 2;
    A[1][2] = 1;
    A[2][0] = -1;
    A[2][1] = 0;
    A[2][2] = 3;
    X[0]=1;
    X[1]=2;
    X[2]=3; //wypelnienie tablicy (macierzy)
    
    int i,j;
    for(i=0; i<3;i++) {
             n=0;
             for(j=0;j<3;j++) {
                 B[i] = A[i][j] * X[j];
                 n = n+B[i];             
                 }
                 B[i] = n;
             } //mnozenie macierzy
             
    printf("%d, %d %d\n", B[0], B[1], B[2]); 
    
    
    system("PAUSE");
    return 0;
}
