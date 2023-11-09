#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the beginning.\n");
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* tempPrev = NULL;

    do {
        if (temp->data == key) {
            if (temp == head && temp->next == head) {
                head = NULL;
            } else if (temp == head) {
                head = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            printf("Node with value %d deleted.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node with value %d not found in the list.\n", key);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");

    temp = head->prev;
    printf("Circular Doubly Linked List (Backward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(Head)\n");
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display circular doubly linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the value of node to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 3:
                displayList();
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