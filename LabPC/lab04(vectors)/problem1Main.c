#include <stdio.h>

#define N 100

int readVector(unsigned int v[N])
{   
    unsigned int x;
    int i = 0;
    while(scanf("%u", &x) && i < N) {
        if(x == 0) return i;
        v[i] = x;
        i++;
    }
    return i;
}

int main()
{
    unsigned int v[N];
    
}