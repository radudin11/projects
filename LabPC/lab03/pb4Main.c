#include <stdio.h>
#include "functionsL3.h"

int main() {
    int x;
    printf("Introduceti un numar: ");
    scanf("%d", &x);
    int verify = este_palindorm(x);
    if (verify == 1) {
        printf("Numarul %d este palindrom", x);
    }
    else {
        printf("Numarul %d nu este palindrom", x);
    }
    return 0;


}
