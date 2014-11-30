#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    
    int i;
    double x,z[40001];
    
    for(i=0;i<=40000;i++) {
                       x=i*M_PI/180.0;
                       z[i]=sin(x);
                       printf("%4d %20.16f \n", i, z[i]);           
                      }
    
    
    system("PAUSE");
    return 0;
}
