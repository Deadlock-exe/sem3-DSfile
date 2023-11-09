#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
typedef struct {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
} Term;

// Function to add two polynomials
void addPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exp > poly2[j].exp) {
            printf("%dx^%d ", poly1[i].coeff, poly1[i].exp);
            i++;
        } else if (poly1[i].exp < poly2[j].exp) {
            printf("%dx^%d ", poly2[j].coeff, poly2[j].exp);
            j++;
        } else {
            int sum = poly1[i].coeff + poly2[j].coeff;
            if (sum != 0) {
                printf("%dx^%d ", sum, poly1[i].exp);
            }
            i++;
            j++;
        }
    }

    // Print remaining terms of the first polynomial
    while (i < size1) {
        printf("%dx^%d ", poly1[i].coeff, poly1[i].exp);
        i++;
    }

    // Print remaining terms of the second polynomial
    while (j < size2) {
        printf("%dx^%d ", poly2[j].coeff, poly2[j].exp);
        j++;
    }
}

// Function to multiply two polynomials
void multiplyPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
    int maxSize = size1 + size2 - 1;
    int *result = (int *)calloc(maxSize, sizeof(int));

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[poly1[i].exp + poly2[j].exp] += poly1[i].coeff * poly2[j].coeff;
        }
    }

    printf("Result of multiplication: ");
    for (int i = 0; i < maxSize; i++) {
        if (result[i] != 0) {
            printf("%dx^%d ", result[i], i);
        }
    }

    free(result);
}

int main() {
    // Example polynomials
    Term poly1[] = {{3, 2}, {4, 1}, {5, 0}}; // 3x^2 + 4x + 5
    Term poly2[] = {{2, 3}, {1, 1}, {7, 0}}; // 2x^3 + x + 7

    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    printf("Polynomial 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%dx^%d ", poly1[i].coeff, poly1[i].exp);
    }
    printf("\n");

    printf("Polynomial 2: ");
    for (int i = 0; i < size2; i++) {
        printf("%dx^%d ", poly2[i].coeff, poly2[i].exp);
    }
    printf("\n");

    printf("Result of addition: ");
    addPolynomials(poly1, size1, poly2, size2);
    printf("\n");

    multiplyPolynomials(poly1, size1, poly2, size2);
    printf("\n");

    return 0;
}
