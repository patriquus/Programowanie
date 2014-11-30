// Pelna Transformata Fouriera z filtrem dolnoprzepustowym

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int LEN=1024; // dlugosc 

// STRUKTURA LICZB ZESPOLONEJ ================================================== 

struct CMPL {
       double Re;
       double Im;
       };
       
// =============================================================================
// STRUKTURA FOURIER ===========================================================         

struct Fourier {
       CMPL DFT[LEN];
       CMPL iDFT[LEN];
       };  
          
// =============================================================================
// FUNKCJA GLOWNA ==============================================================

int main () {

    int signal[LEN];
    double x;
    int n,k;
    
    FILE *pFile;
    Fourier *p;
    //CMPL *DFT, *iDFT;
    p  = (Fourier*)malloc(sizeof(Fourier)); 
    //DFT  = (CMPL*)malloc(sizeof(CMPL)); // alokacja pamieci
    //iDFT = (CMPL*)malloc(sizeof(CMPL)); // alokacja pamieci
    
    for(n=0;n<LEN;n++) {signal[n]=0;}; // zerowanie sygnalow
    
// DEFINIOWANIE SYGNALU ========================================================     
    
    for(n=0;n<LEN;n++) {
       if((n>156) && (n<189)) signal[n]=100;    
//     if((n>259) && (n<261)) signal[n]=100;        
       if((n>314) && (n<337)) signal[n]=100;   
        }
        
// =============================================================================  
// LICZENIE TRANSFORMATY FOURIERA===============================================   
    
        for(n=0;n<LEN;n++){
                 p->DFT[n].Re = 0.0;
                 p->DFT[n].Im = 0.0;
                               
            for(k=0;k<LEN;k++) {
                 p->DFT[n].Re +=  signal[k]*cos(2*M_PI*k*n/LEN);
                 p->DFT[n].Im += -signal[k]*sin(2*M_PI*k*n/LEN);
                                }               
                             }
                             
// =============================================================================                             
// FILTR DOLNOPRZEPUSTOWY ======================================================                            
       
        for(n=0;n<10;n++) {
                 p->DFT[512+n].Re=0.0;
                 p->DFT[512+n].Re=0.0;
                 p->DFT[512-n].Im=0.0;
                 p->DFT[512+n].Im=0.0;
                           }
                           
// =============================================================================                          
// LICZENIE ODWROTNEJ TRANSFORMATY FOURIERA=====================================   

   for(n=0; n<LEN; n++) {
             p->iDFT[n].Re = 0.0;
             p->iDFT[n].Im = 0.0;
             for(k=0; k<LEN; k++) {
                 p->iDFT[k].Re += ( p->DFT[k].Re*cos(2*M_PI*k*n/LEN) -  p->DFT[k].Im*sin(2*M_PI*k*n/LEN));  
                 p->iDFT[k].Im += ( p->DFT[k].Re*sin(2*M_PI*k*n/LEN) +  p->DFT[k].Im*cos(2*M_PI*k*n/LEN));  
                      }
             }
             
// =============================================================================                             
// ZAPIS DO PLIKU I WYPISANIE NA EKRAN ========================================= 
    
    pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\271014\\prog1.txt", "wt");
    fseek(pFile, 0, SEEK_SET);
    
    int i;     
       for(i=0;i<512;i++) {
        printf(            "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], p->DFT[i].Re, p->DFT[i].Im, p->iDFT[i].Re,        p->iDFT[i].Im);  
        fprintf(pFile,     "%5d %4d %12.7f  %12.7f %12.7f %12.7f  \n", i, signal[i], p->DFT[i].Re, p->DFT[i].Im, p->iDFT[i].Re/(double)LEN, p->iDFT[i].Im/(double)LEN);         
        }
        fclose( pFile);
        
// =============================================================================   
        
        free(p);
             
    system("PAUSE");
    return 0;
}


