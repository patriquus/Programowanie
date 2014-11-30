// Pelna Transformata Fouriera z filtrem dolnoprzepustowym

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int LEN=1024; // dlugosc 

struct CMPL {
       double Re;
       double Im;
       int    p[100];
       };

int main () {

    int signal[LEN];
    double x;
    int n,k;
    
    FILE *pFile;
    CMPL *DFT[LEN], *iDFT[LEN];
    
    for(k=0; k<LEN; k++) {
        DFT[k]=(CMPL*)malloc(sizeof(CMPL));
        iDFT[k]=(CMPL*)malloc(sizeof(CMPL));
        }
    
    for(n=0;n<LEN;n++) {signal[n]=0;}; // zerowanie sygnalow
    for(n=0;n<LEN;n++) {
       if((n>156) && (n<259)) signal[n]=100;    
       if((n>314) && (n<417)) signal[n]=100;   
        }
        
        for(n=0;n<LEN;n++){
                 DFT[n]->Re = 0.0;
                 DFT[n]->Im = 0.0;
            for(k=0;k<LEN;k++) {
                 DFT[n]->Re +=  signal[k]*cos(2*M_PI*k*n/LEN);
                 DFT[n]->Im += -signal[k]*sin(2*M_PI*k*n/LEN);
                                }               
                             }
// FILTR DOLNOPRZEPUSTOWY ======================================================                            
        for(n=0;n<10;n++) {
                 DFT[512-n]->Re=0.0;
                 DFT[512+n]->Re=0.0;
                 DFT[512-n]->Im=0.0;
                 DFT[512+n]->Im=0.0;
                           }
// =============================================================================                          

    for(n=0; n<LEN; n++) {
             iDFT[n]->Re = 0.0;
             iDFT[n]->Im = 0.0;
             for(k=0; k<LEN; k++) {
                 iDFT[k]->Re += (DFT[k]->Re*cos(2*M_PI*k*n/LEN) - DFT[k]->Im*sin(2*M_PI*k*n/LEN));  
                 iDFT[k]->Im += (DFT[k]->Re*sin(2*M_PI*k*n/LEN) + DFT[k]->Im*cos(2*M_PI*k*n/LEN));  
                      }
             }
    
    pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\271014\\prog1.txt", "wt");
    fseek(pFile, 0, SEEK_SET);
    
    int i;     
       for(i=0;i<512;i++) {
        printf(            "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT[i]->Re, DFT[i]->Im, iDFT[i]->Re,        iDFT[i]->Im);  
        fprintf(pFile,     "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT[i]->Re, DFT[i]->Im, iDFT[i]->Re/(double)LEN, iDFT[i]->Im/(double)LEN);         
        }
        fclose( pFile);
        
    for (k=0;k<LEN;k++) {
        free(DFT[k]);
        free(iDFT[k]);
        } 
             
    system("PAUSE");
    return 0;
}


