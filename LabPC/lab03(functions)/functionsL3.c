#include "functionsL3.h"
#include <math.h>
#include <stdio.h>

int factorial_iterativ(int n) {
    if (n == 0) return 1;
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int factorial_recursiv(int n) {
    if (n == 0) return 1;
    return n * factorial_recursiv(n - 1);
}

int suma_cifre_iterativ(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int suma_cifre_recursiv(int n) {
    if (n == 0) return 0;
    return n % 10 + suma_cifre_recursiv(n / 10);
}

int este_prim(int n) {
    if (n == 0 || n == 1) return 0;
    int d;
    for (d = 2; d <= sqrt(n); d++) {
        if (n % d == 0) return 0;
    }
    return 1;
}

int este_palindorm(int n) {
    int cn = n;
    int mirror = 0;
    while (cn != 0) {
        mirror = mirror * 10 + cn % 10;
        cn /= 10;
    }
    if (mirror == n) return 1;
    return 0;
}

void div_palindorm(int x) {
    if (x == 0) printf("Numarul 0 nu are divizori");
    else {
        int cont = 0, d = 1;
        for (d = 1; d <= x / 2; d++) {
            if (x % d == 0) {
                if (este_palindorm(d)) {
                    printf("Numarul %d este divizor al lui x si este palindrom\n", d);
                    cont++;
                } else printf("Numarul %d este divizor al lui x\n",d);
            }
        }
        if(este_palindorm(x)) {
            printf("Numarul %d este divizor al lui x si este palindrom\n", x);
            cont++;
        } else printf("Numarul %d este divizor al lui x\n",x);
        printf("%d are %d divizori palindrom", x, cont);
    }
}
void este_prim_recursiv() {
    int x;
    static int contor = 0;
    printf("Introduceti un numar: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("Numarul de numere prime este %d", contor);
        return;
    }
    else {
        if (x > 0 && este_prim(x)) {
            contor++;
        }
    }
    este_prim_recursiv();
}




