#include <stdio.h>
#define SIZE 20
int gaseste_N(unsigned int instructiune);
void char_print_vector(char v[SIZE], int n);
void gaseste_operatii(char vector_de_operatii[8], int size, unsigned int instructiune);
int gaseste_dim(int N, unsigned int instructiune);
void afisare_elemente_task1_checker(int N, int dim, char operatii[8]);
int main()
{
    /*interpretarea unei instructiuni date avand 
    in vedere regulile din task1 al temei 1: 
    https://ocw.cs.pub.ro/courses/programare/teme_2021/tema1_2021_cbd*/

    unsigned int masca = 1 << 31;
    unsigned int instructiune;
    int N, dim = 1;
    char operatii[8];


    printf("Dati o instrctiune: ");
    scanf("%u", &instructiune);

    N = gaseste_N(instructiune);
    gaseste_operatii(operatii, N, instructiune);
    dim = gaseste_dim(N, instructiune);

    afisare_elemente_task1_checker(N ,dim, operatii);

    return 0;
}
int gaseste_N(unsigned int instructiune)
{
    /*returneaza valoarea intreaga determinata de cei mai significtivi
    3 biti ai instructiunii*/
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

void char_print_vector(char v[SIZE], int n)
{
    //afiseaza valorile dintr-un vector de char
    int i;

    for (i = 0; i < n; i++) {
        printf("%c ", v[i]);
    }
}

void gaseste_operatii(char vector_de_operatii[8], int size, unsigned int instructiune)
{
    //interpreteaza urmatorii 2 * N biti ai intructiunii dupa regula data

    instructiune <<= 3;//trecem peste primii 3 biti
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
        /*regula operatie:
            0 = '+' (00)
            1 = '-' (01)
            2 = '*' (10)
            3 = '/' (11)
        */
        vector_de_operatii[i] = operatori[operatie];
        instructiune <<= 2;
    }
}

int gaseste_dim(int N, unsigned int instructiune)
{
    /*returneaza valoarea intreaga determinata de cei mai putin significativ
    4 biti ai instructiunii*/

    int permutare_biti = 3 + 2 * N;//unde se afla cei mai putin semnificativi 4 biti
    unsigned int i, masca = 1 << 31, dim = 1;
    instructiune <<= permutare_biti; //aliniem instructiunea cu masca

    //transformare binar pe 4 biti in decimal
    for (i = 0; i < 4; i++) {
        if (masca & instructiune) {
            switch (i) {
            case 0:
                dim += 8;
                break;
            case 1:
                dim += 4;
                break;
            case 2:
                dim += 2;
                break;
            case 3:
                dim += 1;
                break;
            }

        }
        instructiune <<= 1;
    }
    return dim;
}

void afisare_elemente_task1_checker(int N, int dim, char operatii[8]) 
{
    printf("%d ", N);
    char_print_vector(operatii, N);
    printf("%d ", dim);
}
