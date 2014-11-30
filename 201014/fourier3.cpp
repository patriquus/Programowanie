#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Pelna Transformata Fouriera

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
    
    for(n=0;n<1024;n++) {signal[n]=0;};
    for(n=0;n<1024;n++) {
       // x=100.0*cos(n*M_PI/32.0);    
       // signal[n]=(int)x; 
       if((n>156)&&(n<159)) signal[n]=100;
      // if (n>159) signal[n]=100;         
      // if((n>259)&&(n<261)) signal[n]=100;
      // if((n>314)&&(n<317)) signal[n]=100;         
        }
        
        for(n=0;n<1024;n++){
                 DFT[n].Re = 0.0;
                 DFT[n].Im = 0.0;
            for(k=0;k<1024;k++) {
                 DFT[n].Re +=  signal[k]*cos(2*M_PI*k*n/1024);
                 DFT[n].Im += -signal[k]*sin(2*M_PI*k*n/1024);
                                }               
                             }

    for(n=0; n<1024; n++) {
             iDFT[n].Re = 0.0;
             iDFT[n].Im = 0.0;
             for(k=0; k<1024; k++) {
                 iDFT[k].Re += (DFT[k].Re*cos(2*M_PI*k*n/1024)-DFT[k].Im*sin(2*M_PI*k*n/1024));  
                 iDFT[k].Im += (DFT[k].Re*sin(2*M_PI*k*n/1024)+DFT[k].Im*cos(2*M_PI*k*n/1024));  
                      }
             }
    
    pFile = fopen ("D:\\Users\\patryk.gradys\\PROGRAMOWANIE\\201014\\prog2.txt", "wt");
    int i;     
       for(i=0;i<1024;i++) {
        printf("%5d, %4d, %12.7f  %12.7f, %12.7f, %12.7f  \n", i, signal[i], DFT[i].Re, DFT[i].Im, iDFT[i].Re,  iDFT[i].Im);  
        fprintf(pFile, "%5d, %4d, %12.7f,  %12.7f, %12.7f, %12.7f  \n", i, signal[i], DFT[i].Re, DFT[i].Im, iDFT[i].Re/1024.0, iDFT[i].Im/1024.0);         
        }
          
    system("PAUSE");
    return 0;
}


