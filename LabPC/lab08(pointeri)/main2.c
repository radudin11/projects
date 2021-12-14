#include <stdio.h>

int str_length(char *s) {
    int cont = 0;
    while(*s != 0) {
        cont++;
        s++;
    }
    return cont;
}

char * strdel(char *s, int pos, int n) {
    for(int i = pos; i < str_length(s); i++)
        s[i] = s[i + n];
    return s;

}

char * strins (char *s1, int pos, char *s2) {
    int s2_l = str_length(s2);
    int s1_l = str_length(s1);
    char saux[100];
    for(int i = 0; i < pos-1; i++)
        saux[i] = s1[i]; 
    pos--;
    for(int i = pos; i < s1_l; i++) {
        saux[i+s2_l] = s1[i]; // 125  34 --> 12??5\0
    }
    for(int i = 0; i < s2_l; i++) {
        saux[i+pos] = s2[i];
    }
    return saux;
}

int eq_mask(char *sir, char *masca) {
    int sir_l = str_length(sir);
    for(int i = 0; i < sir_l; i++) {
        if(masca[i] == '?') continue;
        if(masca[i] != sir[i]) return 0;
    }
    return 1; 
}

// int eqcuv(char *cuv, char **tablou) {
//     int i = 0;
//     while(tablou[i] != '\0') {
//         int cuv_l = str_length(cuv)
//     }
// }

int main() {
    char s1[100] = "abfghijklm";
    char s2[] = "cde";
    // // printf("%d\n", str_length(s));
    // // char *p = strdel(s, 1, 2);
    char *p = strins(s1, 3, s2);
    // int a = eq_mask(s1, masca);
    printf("%s", p);

    // char *tablou[100] = {"curs1", "curs2", "curs3"};
	// char *cuv1 = "curs2", *cuv2 = "curs5";
	// printf("curs2 %s in tablou\n",(eqcuv(cuv1, tablou)) ? "este" : "nu este");
	// printf("curs5 %s in tablou\n",(eqcuv(cuv2, tablou)) ? "este" : "nu este");
}