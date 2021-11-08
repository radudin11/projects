#include <stdio.h>
#include "functionsL3.h"

int main()
{
    int x;
    printf("Introduceti un numar: ");
    scanf("%d", &x);

    printf("\nSuma cifrelor numarului %d este %d", x, suma_cifre_iterativ(x));
    
    printf("\nSuma cifrelor numarului %d este %d(in mod recursiv)\n", x, suma_cifre_recursiv(x));
}
