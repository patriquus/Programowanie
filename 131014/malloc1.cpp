#include <stdio.h>
#include <stdlib.h>

int main () {
    
    double *ptr;
    
    ptr = (double*)malloc(8192 * sizeof(double));
    ptr[0]=3.14;
    ptr[1]=6789.33;
    printf("%10.5f, %10.5f\n", ptr[0], ptr[1]);
    free(ptr);    
    
    system("PAUSE");
    return 0;
}
