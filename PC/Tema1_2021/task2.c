#include <stdio.h>
#include <math.h>

#define SIZE 20
/*functii task1*/
int gaseste_N(unsigned int instructiune);
void char_print_vector(char v[SIZE], int n);
void gaseste_operatii(char vector_de_operatii[8], int size, unsigned int instructiune);
int gaseste_dim(int N, unsigned int instructiune);

/*functii task2*/
void ushort_print_vector(unsigned short v[SIZE], int n);
unsigned short binar_in_decimal(unsigned short* numar, int dim, int* N);
unsigned int citeste_instructiune_checker();
int citeste_operanzi_checker(unsigned short operanzi[SIZE], int N, int dim);
void afisare_elemente_task1_checker(int N, int dim, char operatii[8]) 
{
    printf("%d ", N);
    char_print_vector(operatii, N);
    printf("%d ", dim);
}
int main()
{
    /*interpretarea unei instructiuni date avand
    in vedere regulile din task1 al temei 1:
    https://ocw.cs.pub.ro/courses/programare/teme_2021/tema1_2021_cbd*/

    unsigned int instructiune;
    int N, dim;
    char operatii[8];

    instructiune = citeste_instructiune_checker();

    N = gaseste_N(instructiune);
    gaseste_operatii(operatii, N, instructiune);
    dim = gaseste_dim(N, instructiune);

    /*task 2*/
    unsigned short operanzi[SIZE];
    int numar_de_operanzi;
    int rezultat;
    
    numar_de_operanzi = citeste_operanzi_checker(operanzi, N, dim);
    
    rezultat = operanzi[0];
    for(int i = 1; i < numar_de_operanzi; i++) {
        switch(operatii[i-1]) {
            case '+':
                rezultat += operanzi[i];
                break;
            case '-':
                rezultat -= operanzi[i];
                break;
            case '*':
                rezultat *= operanzi[i];
                break;
            case '/':
                rezultat /= operanzi[i];
        }
    }
    printf("%d", rezultat);
    return 0;

}
unsigned int citeste_instructiune_checker()
{
    /* citeste prima instructiune de la tastatura
    si o returneza*/
    unsigned int instructiune;

    printf("Dati o instrctiune: ");
    scanf("%u", &instructiune);
    return instructiune;
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

void ushort_print_vector(unsigned short v[SIZE], int n)
{
    //afiseaza valorile dintr-un vector de unsigned short
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

unsigned short binar_in_decimal(unsigned short* numar, int dim, int* N)
{
    /* Transforma primul binar din <numar> de dimensiune <dim> in unsigned short si il returneaza.
     Scadem <N> cu o unitate pt a  tine cont cate numere mai trebuie extrase din inputuri */
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

int calcul_numar_inputuri(int N, int dim)
{
    //calculeaza numarul de inputuri necesare dupa formula data
    int numar_de_inputuri = ((N + 1) * dim) / 16;

    //daca numarul este mai mare decat partea sa intreaga incrementam cu 1
    if ((float)numar_de_inputuri < (float)(((N + 1) * dim) / 16.0)) {
        numar_de_inputuri++;
    }
    return numar_de_inputuri;
}

int citeste_operanzi_checker(unsigned short operanzi[SIZE], int N, int dim)
{
    int i = 0;
    int contor_pasi = 0, pasi_in_numar = 16 / dim;//cate grupari de <dim> biti sunt in unsigned short
    unsigned short input;

    int numar_de_inputuri = calcul_numar_inputuri(N, dim);
    int contor_de_inputuri = numar_de_inputuri;

    //cat timp avem inputuri de citit
    while (contor_de_inputuri) {

        //citire input
        scanf(stdin, "%hu", &input);
        contor_de_inputuri--;

        contor_pasi = 0;
        //cat timp avem nevoie de numere extrase din input si avem numere ramase in input
        while (N >= 0 && contor_pasi < pasi_in_numar) {
            operanzi[i] = binar_in_decimal(&input, dim, &N);
            contor_pasi++;
            i++;
        }
    }
    return i;
}


