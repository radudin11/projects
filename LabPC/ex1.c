


#include <stdio.h>

#define N 100
#define INT_MAX 2147483647
#define INT_MIN -2147483648

void sum_right_neighbour(int v[N], int n)
{
    int i;

    for (i = 0; i < n - 1; i++) {
        v[i] += v[i + 1];
    }
}

void print_vector(int v[N], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void add_left(int v[N], int n)
{
    int i;

    for (i = n-1; i > 0; i--) {
        v[i] += v[i - 1];
    }
}

void exclusiveMultiplication(int v[N], int n, int xMult[N])
{
    int result = 1;
    int i;

    for (i = 0; i < n; i++) {
        result *= v[i];
    }
    for (i = 0; i < n; i++) {
        xMult[i] = result / v[i];
    }
}

void removeMin(int v[N], int *n) 
{
    int i;
    int min = INT_MAX;
    for(i = 0; i < *n; i++) {
        if(v[i] < min) min = v[i];
    }
    for(i = 0; i < *n; i++) {
        if(v[i] == min) {
            for(int j = i+1 ; j < *n-1; j++) {
                v[j] = v[j + 1];
            }
            break;
        }
    }
    (*n)--;
}

void removeMax(int v[N], int *n) 
{
    int i;
    int max = INT_MIN;
    for(i = 0; i < *n; i++) {
        if(v[i] > max) max = v[i];
    }
    for(i = 0; i < *n; i++) {
        if(v[i] == max) {
            for(int j = i+1 ; j < *n-1; j++) {
                v[j] = v[j + 1];
            }
            break;
        }
    }
    *n = *n - 1;
}

int main(void)
{
    int v[N] = { 1, 2, 3, 4, 5 };
    int xMult[N];
    char input;
    int n = 5;

    printf("Give a command:\n q - quit\nm - remove smallest value\nM - remove highest value\np - print vector\n");
    scanf("%s", &input);
    //exclusiveMultiplication(v,n,xMult);
    //print_vector(xMult, n);
    while(input != 'q') {
        switch(input)
        {
        case 'p':
            print_vector(v,n);
            break;
        case 'm':
            removeMin(v, &n);
            break;
        case 'M':
            removeMax(v, &n);
            break;
        default:
            printf("Unknown command");
            break;
        }
        printf("\nGive a command:\n q - quit\nm - remove smallest value\nM - remove highest value\np - print vector\n");
        scanf("%s", &input);
    }
    

    return 0;
}