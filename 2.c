/* Menu driven program to manage sorted array */
#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Key not found
}

int insertElement(int arr[], int *size, int key) {
    int index = *size;
    while (index > 0 && arr[index - 1] > key) {
        arr[index] = arr[index - 1];
        index--;
    }
    arr[index] = key;
    (*size)++;
    return index;
}

int deleteElement(int arr[], int *size, int key) {
    int index = binarySearch(arr, *size, key);
    
    if (index == -1) {
        printf("Element not found.\n");
    } else {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted successfully.\n");
    }
    
    return index;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);

    int choice;
    int key;

    while (1) {
        printf("0. Exit\n1. Binary Search\n2. Insert Element\n3. Delete Element\n4. Print array\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program.\n");
                return 0;
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int index = binarySearch(arr, size, key);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                insertElement(arr, &size, key);
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteElement(arr, &size, key);
                displayArray(arr, size);
                break;
            case 4: 
                displayArray(arr,size);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}
