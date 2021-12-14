#include <stdio.h>

void afisareBin(int x) {
    int masca = 1 << 31;
    int sizeInt = 32;
    int i;
    for (i = 0;i < sizeInt; i++) {
        if (masca & x)
            printf("1");
        else
            printf("0");
        x <<= 1;
    }
    printf("\n");
}

int main() {
    int n = 0;
    int x = 0, mem = 0;
    printf("Dati valoare pentru : ");
    scanf("%d", &n);
    while(n) {
        scanf("%d", &x);
        if( mem & (1 << x)) {
            mem =  mem & (~(1 << x));
            afisareBin(mem);  
        } else {
            mem = mem | (1 << x);
            afisareBin(mem); 
        }
        n--;
    }
    return 0;
}