#include <stdio.h>

#define N 100


void transpose_matrix(int m[N][N], int n)
{
	int i, j, tmp;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
}


void print_matrix(int m[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void read_matrix(int m[N][N], int* n, FILE *file) {
	int i = 0, j = 0;
	fscanf(file, "%d", n);
	printf("nr.linii si coloane: %d\n", n);

	if ((*n) > N || (*n) > N) {
		printf("Eroare: dimensiuni > %d \n", N);
		return;
	}

	for (i = 0; i < (*n); i++) {
		for (j = 0; j < (*n); j++) {
			fscanf(file, "%d", &m[i][j]);
		}
	}
}

int sum_above_primary(int m[N][N], int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i < j) sum += m[i][j]; 
		}
	}
	return sum;
}

void print_below_secondary(int m[N][N], int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if(i + j > n-1) printf("%d ", m[i][j]);
			else printf("0 ");
		}	
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int n = 0;
	FILE *file = fopen("input.txt", "r"); 
	int V[N][N];

	read_matrix(V, &n, file);

	print_matrix(V, n);
	transpose_matrix(V, n);
	print_matrix(V, n);
	printf("%d\n", sum_above_primary(V, n));
	print_below_secondary(V, n);
	fclose(file);
	return 0;
}