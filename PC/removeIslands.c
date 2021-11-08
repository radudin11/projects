#include <stdio.h>
/* This algorithm transforms a given binary matrix by removing all the "islands" made of 1's. An island is a group made of 1 or more elemnts wich do not connect to the edge of the matrix.
Example:
input:
{
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0, 1],
}

output:
{
    [1, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 1],
    [0, 0, 0, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 1],
}
*/
void findAdjacentTo(int row, int column, int numberOfRows, int numberOfColumns, int matrix[20][20]);
void readMatrix(int numberOfRows, int numberOfColumns, int matrix[20][20]);
void printMatrix(int numberOfRows, int numberOfColumns, int matrix[20][20]);
int main()
{
    int numberOfRows, numberOfColumns, matrix[20][20], row, column;
    printf("Give the number of rows: ");
    scanf("%d", &numberOfRows);
    printf("Number of rows = %d", numberOfRows);
    printf("\nGive the number of columns: ");
    scanf("%d", &numberOfColumns);
    printf("Number of columns = %d", numberOfColumns);

    readMatrix(numberOfRows, numberOfColumns, matrix);
    printMatrix(numberOfRows, numberOfColumns, matrix);
    for (row = 0; row < numberOfRows; row++) {
        if (matrix[row][0] == 1) {
            findAdjacentTo(row, 0, numberOfRows, numberOfColumns, matrix);
        }
        if (matrix[row][numberOfColumns - 1] == 1) {
            findAdjacentTo(row, numberOfColumns - 1, numberOfRows, numberOfColumns, matrix);
        }
    }

    for (column = 1; column < numberOfColumns - 1; column++) {
        if (matrix[0][column] == 1) {
            findAdjacentTo(0, column, numberOfRows, numberOfColumns, matrix);
        }
        if (matrix[numberOfRows - 1][column] == 1) {
            findAdjacentTo(numberOfRows - 1, column, numberOfRows, numberOfColumns, matrix);
        }
    }
    printMatrix(numberOfRows, numberOfColumns, matrix);

    for (row = 0; row < numberOfRows; row++) {
        for (column = 0; column < numberOfColumns; column++) {
            if (matrix[row][column] == 1) matrix[row][column] = 0;
            else if (matrix[row][column] == 2) matrix[row][column] = 1;
        }
    }
    printMatrix(numberOfRows, numberOfColumns, matrix);
}


void readMatrix(int numberOfRows, int numberOfColumns, int matrix[20][20]) {
    printf("\nGive the values in the matrix\n");
    for (int i = 0; i < numberOfRows; i++)
        for (int j = 0; j < numberOfColumns; j++)
            scanf("%d", &matrix[i][j]);
}
void printMatrix(int numberOfRows, int numberOfColumns, int matrix[20][20]) {
    printf("{\n");
    char spaces4[] = "    ";
    for (int i = 0; i < numberOfRows; i++) {
        printf("%s[", spaces4);
        for (int j = 0; j < numberOfColumns; j++) {
            if(matrix[i][j] == 1)
                printf("\033[00;31m");
            if(matrix[i][j] == 2)
                printf("\033[00;32m");
            printf("%d, ", matrix[i][j]);
            printf("\033[00m");
        }
        printf("]\n");
    }
    printf("}\n\n");
}
void findAdjacentTo(int row, int column, int numberOfRows, int numberOfComlumns, int matrix[20][20]) {
    /* Finds and replaces every cell and its adjacents that has a value of 1 with the value 2 */
    int dir[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };
    if (row >= numberOfRows || row < 0) return;
    if (column >= numberOfComlumns || column < 0) return;
    matrix[row][column] = 2;
    for (int i = 0; i < 4; i++) {
        int nRow = row + dir[i][0];
        int nCol = column + dir[i][1];
        if (matrix[nRow][nCol] == 1) {
            findAdjacentTo(nRow, nCol, numberOfRows, numberOfComlumns, matrix);
        }

    }
}
