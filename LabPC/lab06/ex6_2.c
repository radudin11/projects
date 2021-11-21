#include <stdio.h>

#define N 20
void read_matrix(int a[N][N], int *nl, int *nc, FILE *file) {
    fscanf(file, "%d", nl);
    printf("nr.linii: %d\n", *nl);
    fscanf(file, "%d", nc);
    printf("nr.coloane: %d\n", *nc);

    if ((*nl) > N || (*nc) > N) {
        printf("Eroare: dimensiuni > %d\n", N);
        return;
    }
    int i = 0, j = 0;
    for (i = 0; i < *nl; i++) {
        for (j = 0; j < *nc; j++) {
            fscanf(file, "%d", &a[i][j]);
        }
    }

}

void print_matrix(int m[N][N], int nl, int nc) {
	int i, j;

	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int matrix_product_element(int matrix1[N][N], int matrix2[N][N], int i, int j, int com) {
    int sum = 0;
    for(int k = 0; k < com; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
    }
    return sum;
}

void matrix_product(int matrix1[N][N], int nl1, int nc1, int matrxi2[N][N], int nl2, int nc2, int result_matrix[N][N]) {
    if(nc1 != nl2) {
        printf("Eroare: inmultire imposibila");
        return;
    }
    for(int i = 0; i < nl1; i++) {
        for(int j = 0 ; j < nc2; j++) {
            result_matrix[i][j] = matrix_product_element(matrix1, matrxi2, i, j, nc1);
        }
    }
}
int main() {
    int n = 0;
	FILE *file = fopen("inputE2.txt", "r"); 
	int M1[N][N], M2[N][N], M3[N][N], nl1, nc1, nl2, nc2;
    read_matrix(M1, &nl1, &nc1, file);
    read_matrix(M2, &nl2, &nc2, file);

    matrix_product(M1, nl1, nc1, M2, nl2, nc2, M3);
    print_matrix(M3, nl1, nc2);
    
}