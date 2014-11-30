#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int LEN=3;
       
struct Alamakota {
       double A[LEN][LEN];
       double X[LEN];
       double B[LEN];    
       };  

int main () {

Alamakota *p;

p  = (Alamakota*)malloc(sizeof(Alamakota));

p->A[0][0]=2;
p->A[0][1]=3;
p->A[0][2]=6;
p->A[1][0]=3;
p->A[1][1]=5;
p->A[1][2]=2;
p->A[2][0]=6;
p->A[2][1]=1;
p->A[2][2]=9;

p->X[0]=3;
p->X[1]=4;
p->X[2]=1;



    int i,j;
    for(i=0; i<3; i++) {
         p->B[i]=0.0;
         for(j=0; j<3; j++) {
              p->B[i] += p->A[i][j] * p->X[j];          
                 }
             }

    printf("%2.5f, %2.5f %2.5f\n", p->B[0], p->B[1], p->B[2]);
    free(p);
//B=A*X;

    system("PAUSE");
    return 0;
}


