#include <stdio.h>
#include "functionsL3.h"

int main()
{
    int x;
    printf("Introduceti un numar: ");
    scanf("%d", &x);

    printf("\nFactorialul numarului %d este %d", x, factorial_iterativ(x));
    
    printf("\nFactorialul numarului %d este %d(in mod recursiv)\n", x, factorial_recursiv(x));
}
 