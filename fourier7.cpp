// Pelna Transformata Fouriera z filtrem dolnoprzepustowym

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int LEN=1024; // dlugosc 

struct CMPL {
       double Re[LEN];
       double Im[LEN];
       };

int main () {

    int signal[LEN];
    double x;
    int n,k;
    
    FILE *pFile;
    CMPL *DFT, *iDFT;
    
    DFT  = (CMPL*)malloc(sizeof(CMPL)); // alokacja pamieci
    iDFT = (CMPL*)malloc(sizeof(CMPL)); // alokacja pamieci
    
    for(n=0;n<LEN;n++) {signal[n]=0;}; // zerowanie sygnalow
    
// DEFINIOWANIE SYGNALU =======================================================     
    
    for(n=0;n<LEN;n++) {
       if((n>156) && (n<189)) signal[n]=100;    
//     if((n>259) && (n<261)) signal[n]=100;        
       if((n>314) && (n<337)) signal[n]=100;   
        }
        
// =============================================================================  
// LICZENIE TRANSFORMATY FOURIERA===============================================   
    
        for(n=0;n<LEN;n++){
                 DFT->Re[n] = 0.0;
                 DFT->Im[n] = 0.0;
                               
            for(k=0;k<LEN;k++) {
                 DFT->Re[n] +=  signal[k]*cos(2*M_PI*k*n/LEN); // transformata Fouriera
                 DFT->Im[n] += -signal[k]*sin(2*M_PI*k*n/LEN); // odwrocona transformata Fouriera
                                }               
                             }
                             
// =============================================================================                             
// FILTR DOLNOPRZEPUSTOWY ======================================================                            
       
        for(n=0;n<10;n++) {
                 DFT->Re[512+n]=0.0;
                 DFT->Re[512+n]=0.0;
                 DFT->Im[512-n]=0.0;
                 DFT->Im[512+n]=0.0;
                           }
                           
// =============================================================================                          

    for(n=0; n<LEN; n++) {
             iDFT->Re[n] = 0.0;
             iDFT->Im[n] = 0.0;
             for(k=0; k<LEN; k++) {
                 iDFT->Re[k] += (DFT->Re[k]*cos(2*M_PI*k*n/LEN) - DFT->Im[k]*sin(2*M_PI*k*n/LEN));  
                 iDFT->Im[k] += (DFT->Re[k]*sin(2*M_PI*k*n/LEN) + DFT->Im[k]*cos(2*M_PI*k*n/LEN));  
                      }
             }
// =============================================================================                             
// ZAPIS DO PLIKU I WYPISANIE NA EKRAN ========================================= 
    
    pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\271014\\prog1.txt", "wt");
    fseek(pFile, 0, SEEK_SET);
    
    int i;     
       for(i=0;i<512;i++) {
        printf(            "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT->Re[i], DFT->Im[i], iDFT->Re[i],        iDFT->Im[i]);  
        fprintf(pFile,     "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], DFT->Re[i], DFT->Im[i], iDFT->Re[i]/(double)LEN, iDFT->Im[i]/(double)LEN);         
        }
        fclose( pFile);
        
// =============================================================================   
        
        free(DFT);
        free(iDFT);
             
    system("PAUSE");
    return 0;
}


