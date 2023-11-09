#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted at the beginning.\n");
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* current = head, *prev;

    if (head->data == key) {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        free(current);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    while (current->next != head) {
        prev = current;
        current = current->next;
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            printf("Node with value %d deleted.\n", key);
            return;
        }
    }

    if (current->data != key) {
        printf("Node with value %d not found in the list.\n", key);
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Head)\n");
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display circular linked list\n");
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