#include <stdio.h>

int main() {
    unsigned short n;  
    unsigned char *first = (unsigned char *)&n;
    unsigned char *second = (unsigned char *)&n + 1;
    printf("%u, %u\n", first, second);
    if(first < second) printf("Big-endian");
    else printf("Small-endian");
}