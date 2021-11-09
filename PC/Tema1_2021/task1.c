#include <stdio.h>

void afisareBin(unsigned int x) {
    unsigned int masca = 1 << 31;
    unsigned int sizeInt = 8 * sizeof(unsigned int);
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

int findN(unsigned int instructiune) {
    unsigned int masca = 1 << 31;
    unsigned int N = 1;
    int i;

    for (i = 0; i < 3; i++) {
        if (masca & instructiune) {
            switch (i) {
            case 0:
                N += 4;
                break;
            case 1:
                N += 2;
                break;
            case 2:
                N += 1;
                break;
            }
        }
        instructiune <<= 1;
    }
    return N;
}

void print_vector(char v[20], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%c ", v[i]);
    }
    printf("\n");
}

void gaseste_operatii(char vector_de_operatii[8], int size, unsigned int instructiune) 
{
    instructiune <<= 3;
    char operatori[4] = "+-*/";
    int i;
    int masca = 1 << 31;
    for (i = 0; i < size; i++) {
        int operatie = 0;
        if (masca & instructiune) {
            operatie += 2;
        }
        if (masca & (instructiune << 1)) {
            operatie += 1;
        }
        /*operatie:
            0 = '+' (00)
            1 = '-' (01)
            2 = '*' (10)
            3 = '/' (11)
        */
        vector_de_operatii[i] = operatori[operatie];
        instructiune <<= 2;
    }
}

int main()
{
    unsigned int masca = 1 << 31;
    unsigned int instructiune;
    int i, N, dim;
    char operatii[8];


    printf("Dati o instrctiune: ");
    scanf("%u", &instructiune);


    N = findN(instructiune);
    gaseste_operatii(operatii, N, instructiune);
   
    printf("\nN = %d\n", N);
    print_vector(operatii, N);



    return 0;
}