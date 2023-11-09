#include <stdio.h>
#define SIZE 50

void insertMinHeap(int arr[], int *size, int x);
void deleteMinHeap(int arr[], int *size);
void minHeapify(int arr[], int n, int i);
void buildMinHeap(int arr[], int n);
void decreaseMaxValue(int arr[], int n, int decBy);

void insertMinHeap(int arr[], int *size, int x) {
    arr[*size] = x;
    int i = *size;
    ++*size;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (arr[parent] < arr[i]) {
            break;
        } else {
            int tmp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = tmp;
            i = parent;
        }
    }
}

void deleteMinHeap(int arr[], int *size) {
    arr[0] = arr[*size - 1];
    --*size;
    int i = 0;

    while (i < *size) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int smallestIndex = i;

        if (left < *size && arr[smallestIndex] > arr[left])
            smallestIndex = left;
        if (right < *size && arr[smallestIndex] > arr[right])
            smallestIndex = right;

        if (smallestIndex == i) {
            break;
        } else {
            int tmp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = tmp;
            i = smallestIndex;
        }
    }
}

void minHeapify(int arr[], int n, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int smallestIndex = i;

    if (left < n && arr[smallestIndex] > arr[left])
        smallestIndex = left;
    if (right < n && arr[smallestIndex] > arr[right])
        smallestIndex = right;

    if (smallestIndex != i) {
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;

        minHeapify(arr, n, smallestIndex);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i++) {
        minHeapify(arr, n, i);
    }
}

void decreaseMaxValue(int arr[], int n, int decBy) {
    int largest = n / 2;
    for (int i = n / 2; i < n; i++) {
        if (arr[largest] < arr[i])
            largest = i;
    }
    arr[largest] = arr[largest] - decBy;

    buildMinHeap(arr, n);
}

int main() {
    int arr[SIZE];
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int choice = 0;
    printf("0. Exit\n1. Insert in heap\n2. Delete in min heap\n3. Make min heap\n4. Decrease max value\n5. Display heap");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    while (choice) {
        switch (choice) {
            case 1:
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insertMinHeap(arr, &size, data);
                break;
            case 2:
                deleteMinHeap(arr, &size);
                break;
            case 3:
                buildMinHeap(arr, size);
                break;
            case 4:
                int decBy = 0;
                printf("Enter decrement by: ");
                scanf("%d", &decBy);
                decreaseMaxValue(arr, size, decBy);
                break;
            case 5:
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                break;
            default:
                printf("Enter an invalid choice\n");
                break;
        }

        printf("\nEnter choice: ");
        scanf("%d", &choice);
    }
    return 0;
}