#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    
    int signal[1024];
    double x, DFT[1024];
    
    int n,k;
    for(n=0;n<1024;n++) {
        x=100.0*cos(n*M_PI/32.0);    
        signal[n]=(int)x;            
        }
        
        for(n=0;n<1024;n++){
                 DFT[n]=0.0;
            for(k=0;k<1024;k++) {
                 DFT[n]+=signal[k]*cos(2*M_PI*k*n/1024);
                                }               
                             }
   int i;
       for(i=0;i<1024;i++) {
        printf("%5d, %4d, %20.16f \n", i, signal[i], DFT[i]);          
        }
          
    system("PAUSE");
    return 0;
}
