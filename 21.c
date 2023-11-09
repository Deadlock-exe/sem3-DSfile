#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* temp = *poly;
    struct Node* newNode = createNode(coefficient, exponent);

    if (*poly == NULL || exponent > (*poly)->exponent) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        while (temp->next != NULL && temp->next->exponent >= exponent) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            if (poly1->exponent > poly2->exponent) {
                insertTerm(&result, poly1->coefficient, poly1->exponent);
                poly1 = poly1->next;
            } else if (poly1->exponent < poly2->exponent) {
                insertTerm(&result, poly2->coefficient, poly2->exponent);
                poly2 = poly2->next;
            } else {
                insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    return result;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL) {
        struct Node* temp = poly2;
        while (temp != NULL) {
            int coefficient = poly1->coefficient * temp->coefficient;
            int exponent = poly1->exponent + temp->exponent;
            insertTerm(&result, coefficient, exponent);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Creating polynomial 1: 3x^2 + 2x + 5
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 5, 0);

    // Creating polynomial 2: 2x^2 + 4x + 1
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    printf("Polynomial 1 + Polynomial 2: ");
    result = addPolynomials(poly1, poly2);
    displayPolynomial(result);

    printf("Polynomial 1 * Polynomial 2: ");
    result = multiplyPolynomials(poly1, poly2);
    displayPolynomial(result);

    return 0;
}