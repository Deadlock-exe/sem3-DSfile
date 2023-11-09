#include <stdio.h>

#define MAX 100

void multiply(int mat1[][3], int mat2[][3], int result[][3]) {
    int r1 = mat1[0][0];
    int c1 = mat1[0][1];
    int r2 = mat2[0][0];
    int c2 = mat2[0][1];

    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    int size1 = mat1[0][2];
    int size2 = mat2[0][2];
    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (mat1[i][1] == mat2[j][0]) {
                temp[mat1[i][0]][mat2[j][1]] += mat1[i][2] * mat2[j][2];
            }
        }
    }

    int k = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            if (temp[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = temp[i][j];
                k++;
            }
        }
    }

    result[0][0] = r1;
    result[0][1] = c2;
    result[0][2] = k - 1;
}

void printMatrix(int mat[][3]) {
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i <= mat[0][2]; i++) {
        printf("%d\t%d\t%d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

int main() {
    int mat1[MAX][3], mat2[MAX][3], result[MAX][3];

    printf("Enter the number of rows, columns and non-zero elements in the first matrix: ");
    scanf("%d%d%d", &mat1[0][0], &mat1[0][1], &mat1[0][2]);

    printf("Enter the sparse representation (row column value) of non-zero elements:\n");
    for (int i = 1; i <= mat1[0][2]; i++) {
        scanf("%d%d%d", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }

    printf("\nFirst Matrix:");
    printMatrix(mat1);

    printf("\nEnter the number of rows, columns and non-zero elements in the second matrix: ");
    scanf("%d%d%d", &mat2[0][0], &mat2[0][1], &mat2[0][2]);

    printf("Enter the sparse representation (row column value) of non-zero elements:\n");
    for (int i = 1; i <= mat2[0][2]; i++) {
        scanf("%d%d%d", &mat2[i][0], &mat2[i][1], &mat2[i][2]);
    }

    printf("\nSecond Matrix:");
    printMatrix(mat2);

    multiply(mat1, mat2, result);

    printf("\nResultant Matrix:");
    printMatrix(result);

    return 0;
}