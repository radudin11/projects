#include <stdio.h>
#include <math.h>

#define SIZE 20

int gaseste_N(unsigned int instructiune);
void char_print_vector(char v[SIZE], int n);
void ushort_print_vector(unsigned short v[SIZE], int n);
void gaseste_operatii(char vector_de_operatii[8], int size, unsigned int instructiune);
int gaseste_dim(int N, unsigned int instructiune);  
unsigned short binar_in_decimal(unsigned short* numar, int dim, int* N);
int citeste_operanzi(FILE* file, unsigned short operanzi[SIZE], int N, int dim);

void afiseaza_intro()
{
    char anunt[] = "!!Daca doriti sa dati valorile de la tastatura introduceti orice caracter si apasati enter!!";
    char spatii4[] = "    ";
    printf("\033[0;31m");
    printf("%s%s\n", spatii4, anunt);
    printf("\033[0m");


}
void citeste_fisier(FILE* file)
{
    char nume_fisier[SIZE];
    printf("\nIntroduceti numele/calea absoluta a fisierului de test: ");
    fscanf(stdin, "%s", nume_fisier);
    file = fopen(nume_fisier, "r");
    
}

int citeste_instructiune(FILE* file)
{
    unsigned int instructiune;
    if (file == NULL) {
        printf("Nici-un fisier gasit!\n");
        printf("Dati o instrctiune: ");
        fscanf(stdin, "%u", &instructiune);
    }
    else {
        fscanf(file, "%u", &instructiune);
        printf("Instructiunea este: ");
        printf("\033[0;32m");
        printf("%u", &instructiune);
        printf("\033[0m");
    }
    return instructiune;
}

int main()
{
    /*interpretarea unei instructiuni date avand
    in vedere regulile din task1 al temei 1:
    https://ocw.cs.pub.ro/courses/programare/teme_2021/tema1_2021_cbd*/
    afiseaza_intro();
    FILE* file;
    char nume_fisier[SIZE];
    printf("\nIntroduceti numele/calea absoluta a fisierului de test: ");
    fscanf(stdin, "%s", nume_fisier);
    file = fopen(nume_fisier, "r");
    //citeste_fisier(file);

    unsigned int instructiune;
    int N, dim = 1;
    char operatii[8];

    if (file == NULL) {
        printf("Nici-un fisier gasit!\n");
        printf("Dati o instrctiune: ");
        fscanf(stdin, "%u", &instructiune);
    }
    else {
        fscanf(file, "%u", &instructiune);
        printf("Instructiunea este: ");
        printf("\033[0;32m");
        printf("%u", instructiune);
        printf("\033[0m");
    }

    //instructiune = citeste_instructiune(file);

    N = gaseste_N(instructiune);
    gaseste_operatii(operatii, N, instructiune);
    dim = gaseste_dim(N, instructiune);


    printf("\nN = ");
    printf("\033[0;32m");
    printf("%d", N);
    printf("\033[0m");

    printf("\nOperatorii sunt: ");
    printf("\033[0;32m");
    char_print_vector(operatii, N);
    printf("\033[0m");

    printf("\nDim = ");
    printf("\033[0;32m");
    printf("%d", dim);
    printf("\033[0m");

    /*task 2*/
    unsigned short operanzi[SIZE];
    int numar_de_operanzi;

    numar_de_operanzi = citeste_operanzi(file, operanzi, N, dim);
    
    printf("\nOperanzii sunt: ");
    printf("\033[0;32m");
    ushort_print_vector(operanzi, numar_de_operanzi);
    printf("\033[0m");


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
    //afiseaza valorile dintr-un vector
    int i;

    for (i = 0; i < n; i++) {
        printf("%c ", v[i]);
    }
}

void ushort_print_vector(unsigned short v[SIZE], int n)
{
    //afiseaza valorile dintr-un vector
    int i;

    for (i = 0; i < n; i++) {
        printf("%hu ", v[i]);
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
    instructiune <<= permutare_biti;

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

unsigned short binar_in_decimal(unsigned short* numar, int dim, int* N) {
    unsigned short masca = 1 << 15;
    unsigned short rez = 0;
    unsigned short copie_numar = (*numar);
    int i;

    for (i = dim - 1; i >= 0; i--) {
        if (masca & copie_numar) {
            rez += pow(2, i);
        }
        copie_numar <<= 1;
    }
    (*N)--;
    (*numar) = copie_numar;
    return rez;
}

int citeste_operanzi(FILE* file, unsigned short operanzi[SIZE], int N, int dim)
{
    /*functia citeste instrucitunile si deduce operanzii corespunzatori instructiunii din <file> sau
    <stdin>(daca file == NULL) si returneaza numarul de operanzi gasitit*/
    int i = 0;
    int contor = 0, pasi_in_numar = 16 / dim;
    unsigned short input;

    int numar_de_inputuri = ((N + 1) * dim) / 16;
    if ((float)numar_de_inputuri < (float)(((N + 1) * dim) / 16.0)) {
        numar_de_inputuri++;
    }
    int contor_de_inputuri = numar_de_inputuri;

    printf("\nNumarul de inputuri este:");
    printf("\033[0;32m");
    printf("%d", numar_de_inputuri);
    printf("\033[0m");

    while (contor_de_inputuri) {
        if (file == NULL) {
            printf("\nMai aveti de dat %d input(uri): ", contor_de_inputuri);
            fscanf(stdin, "%hu", &input);
        }
        else {
            fscanf(file, "%hu", &input);
            printf("\nInputul %d este: ", numar_de_inputuri - contor_de_inputuri + 1);
            printf("\033[0;32m");
            printf("%hu", input);
            printf("\033[0m");
        }
        contor_de_inputuri--;

        contor = 0;
        while (N >= 0 && contor < pasi_in_numar) {
            operanzi[i] = binar_in_decimal(&input, dim, &N);
            contor++;
            i++;
        }
    }
    return i;
}