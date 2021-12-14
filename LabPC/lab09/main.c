#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **get_matrix(int n, int m)
{
	int i, j;
	int **mat;

	mat = malloc(n * sizeof(int *));
	if (mat == NULL) {
		return NULL;
	}

	for (i = 0; i < n; i++) {
		mat[i] = calloc(m , sizeof(int));
		if (mat[i] == NULL) {
			for (j = 0; j < i; j++) {
				free(mat[j]);
			}
			
			free(mat);
			return NULL;
		}
	}

	return mat;
}


void free_matrix(int ***mat, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		free((*mat)[i]);
	}

	free(*mat);
	*mat = NULL;
}

void read_matrix(int **mat, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void sum_lines(int **mat, int n, int m)
{
	int i, j, sum;

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < m; j++) {
			sum += mat[i][j];
		}
		printf("Suma elementelor de pe linia %d este %d\n", i, sum);
	}
}

void print_matrix(int **mat, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

int *get_vector(int m) {
    int *v = malloc(m * sizeof(int));
    return v;
}

void free_vector(int **v) {
    free(*v);
}

void move_from_to_line(int **matrix, int *vector, int line, int cols, int *lines ) {
    //  print_vector(matrix[line], cols);
    memcpy(vector, matrix[line], cols * sizeof(int));
    free(matrix[line]);
    for (int i = line; i < *lines - 1; i++) {
        *(matrix + i) = *(matrix + i + 1);
    }
    *(matrix + *lines - 1) = NULL;
    (*lines)--;
}

void print_vector(int *v, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void)
{
	int n, m, line;
	int **matrix;
    int *vector;
    int *p, *c;
    p = c;

	scanf("%d%d", &n, &m);
    
	matrix = get_matrix(n, m);
    vector = get_vector(m);

	if (matrix == NULL) {
		printf("Allocation error\n");
		return 1;
	}

    if (vector == NULL) {
		printf("Allocation error\n");
		return 1;
	}


	read_matrix(matrix, n, m);
	print_matrix(matrix, n, m);
	//sum_lines(matrix, n, m);

    printf("Give the line number: ");
    scanf("%d", &line);

	move_from_to_line(matrix, vector, line, m, &n);
    print_vector(vector, m);
    print_matrix(matrix, n, m);

	free_matrix(&matrix, n);
    free_vector(&vector);
	return 0;
}
