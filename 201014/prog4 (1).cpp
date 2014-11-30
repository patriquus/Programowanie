#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Pelna Transformata Fouriera
//Filtr dolnoprzepustowy

struct CMPL {
       double Re;
       double Im;
       };

int main () {
    
    int signal[1024];
    double x;
    FILE *pFile;
    CMPL DFT[1024], iDFT[1024];
    int n,k;
    
    for(n=0;n<1024;n++) {signal[n]=0;}; // zerowanie sygnalow
    for(n=0;n<1024;n++) {
       if((n>156) && (n<259)) signal[n]=100;    
       if((n>314) && (n<417)) signal[n]=100;   
        }
        
        for(n=0;n<1024;n++){
                 DFT[n].Re = 0.0;
                 DFT[n].Im = 0.0;
            for(k=0;k<1024;k++) {
                 DFT[n].Re +=  signal[k]*cos(2*M_PI*k*n/1024);
                 DFT[n].Im += -signal[k]*sin(2*M_PI*k*n/1024);
                                }               
                             }
                             
        for(n=0;n<50;n++) {
                 DFT[512-n].Re=0.0;
                 DFT[512+n].Re=0.0;
                 DFT[512-n].Im=0.0;
                 DFT[512+n].Im=0.0;
                           }       //filtr dolnoprzepustowy

    for(n=0; n<1024; n++) {
             iDFT[n].Re = 0.0;
             iDFT[n].Im = 0.0;
             for(k=0; k<1024; k++) {
                 iDFT[k].Re += (DFT[k].Re*cos(2*M_PI*k*n/1024) - DFT[k].Im*sin(2*M_PI*k*n/1024));  
                 iDFT[k].Im += (DFT[k].Re*sin(2*M_PI*k*n/1024) + DFT[k].Im*cos(2*M_PI*k*n/1024));  
                      }
             }
    
    pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\201014\\prog4.txt", "wt");
    fseek(pFile, 0, SEEK_SET);
    
    int i;     
       for(i=0;i<512;i++) {
        printf(            "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT[i].Re, DFT[i].Im, iDFT[i].Re,        iDFT[i].Im);  
        fprintf(pFile,     "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT[i].Re, DFT[i].Im, iDFT[i].Re/1024.0, iDFT[i].Im/1024.0);         
        }
          
    system("PAUSE");
    return 0;
}


