#include <stdio.h>
#include "functionsL3.h"

int main() {
    int x;
    printf("Introduceti un numar: ");
    scanf("%d", &x);
    int ver = este_palindorm(x);
    if (ver == 1) {
        printf("Numarul %d este palindrom", x);
    }
    else {
        printf("Numarul %d nu este palindrom", x);
    }
    return 0;


}