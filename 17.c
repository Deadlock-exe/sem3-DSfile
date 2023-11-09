#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct HeadNode {
    int count;
    float average;
    struct Node* next;
};

struct HeadNode* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = (struct HeadNode*)malloc(sizeof(struct HeadNode));
        head->count = 1;
        head->average = data;
        head->next = newNode;
        return;
    }

    struct Node* current = head->next;
    struct Node* prev = (struct Node*)head; // Adjust pointer type to struct Node

    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    newNode->next = current;
    head->count++;
    head->average = (head->average * (head->count - 1) + data) / head->count;
}

void displayList() {
    struct Node* temp = head->next;
    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayCountAndAverage() {
    printf("Count of elements: %d\n", head->count);
    printf("Average of elements: %.2f\n", head->average);
}

int main() {
    head = (struct HeadNode*)malloc(sizeof(struct HeadNode));
    head->count = 0;
    head->average = 0.0;
    head->next = NULL;

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Display count and average\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertSorted(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                displayCountAndAverage();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}