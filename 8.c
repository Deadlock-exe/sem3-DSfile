#include <stdio.h>
#include <stdlib.h>

void transpose(int a[][3], int b[][3], int n, int m) {
    int *row_terms = (int *)calloc(n, sizeof(int));
    int *starting_pos = (int *)malloc(n * sizeof(int));

    for (int k = 0; k < n; k++) {
        row_terms[k] = 0;
    }

    for (int k = 0; k < m; k++) {
        row_terms[a[k][1]]++;
    }

    starting_pos[0] = 0;

    for (int k = 1; k < n; k++) {
        starting_pos[k] = starting_pos[k - 1] + row_terms[k - 1];
    }

    for (int k = 0; k < m; k++) {
        int current_row = a[k][1];
        int t = starting_pos[current_row];
        b[t][0] = a[k][1];
        b[t][1] = a[k][0];
        b[t][2] = a[k][2];
        starting_pos[current_row]++;
    }

    free(row_terms);
    free(starting_pos);
}

void printSparseMatrix(int a[][3], int m) {
    for (int k = 0; k < m; k++) {
        printf("%d %d %d\n", a[k][0], a[k][1], a[k][2]);
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int (*a)[3] = malloc(m * sizeof(*a));
    
    printf("Enter the sparse matrix (row column value):\n");
    for (int k = 0; k < m; k++) {
        scanf("%d %d %d", &a[k][0], &a[k][1], &a[k][2]);
    }

    printf("Original Sparse Matrix A:\n");
    printSparseMatrix(a, m);

    int (*b)[3] = malloc(m * sizeof(*b));
    transpose(a, b, n, m);

    printf("Transpose of A (Normal Form):\n");
    printSparseMatrix(b, m);

    free(a);
    free(b);
    return 0;
}