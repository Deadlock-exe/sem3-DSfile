#include <stdio.h>
#include <math.h>

#define SIZE 50

// Function prototypes
void insertInHeap(int arr[], int *psize, int x);
void deleteMax(int arr[], int *psize);
void maxHeapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void makeHeap(int arr[], int n);
void increaseKey(int arr[], int n, int incby);

// Function to increase the minimum value
void increaseKey(int arr[], int n, int incby) {
    int smallest = n / 2;

    for (int i = n / 2; i < n; i++) {
        if (arr[i] < arr[smallest]) {
            smallest = i;
        }
    }

    arr[smallest] = incby + arr[smallest];
    makeHeap(arr, n);
}

// Function to insert an element in the heap
void insertInHeap(int arr[], int *psize, int x) {
    int n = *psize;
    arr[n] = x;
    n = n + 1;
    *psize = n;
    int i = n - 1;

    while (i > 0) {
        int p = floor((i - 1) / 2);

        if (arr[p] > arr[i]) {
            break;
        } else {
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            i = p;
        }
    }
}

// Function to delete the maximum element from the heap
void deleteMax(int arr[], int *psize) {
    int n = *psize;
    int x = arr[0];
    arr[0] = arr[n - 1];

    n = n - 1;
    *psize = n;

    int i = 0;

    while (i < n) {
        int l = 2 * i + 1, r = 2 * i + 2;
        int lindex = i;

        if (l < n && arr[l] > arr[lindex]) {
            lindex = l;
        }
        if (r < n && arr[r] > arr[lindex]) {
            lindex = r;
        }

        if (lindex != i) {
            int temp = arr[i];
            arr[i] = arr[lindex];
            arr[lindex] = temp;
            i = lindex;
        } else {
            break;
        }
    }
}

// Function to adjust the heap with a node at index 'i'
void maxHeapify(int arr[], int n, int i) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int lindex = i; // Largest index

    if (l < n && arr[l] > arr[lindex]) lindex = l;
    if (r < n && arr[r] > arr[lindex]) lindex = r;

    if (lindex != i) {
        int temp = arr[i];
        arr[i] = arr[lindex];
        arr[lindex] = temp;

        maxHeapify(arr, n, lindex);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    makeHeap(arr, n);

    for (int i = n; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i - 1];
        arr[i - 1] = temp;

        maxHeapify(arr, i - 1, 0);
    }
}

// Function to build the heap
void makeHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    int arr[SIZE];
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int choice = 0;
    printf("0. Exit\n1. Insert in heap\n2. Delete in max heap\n3. Make max heap\n4. Increase minimum value\n5. Display heap\n6. Heapsort");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    while (choice) {
        switch (choice) {
            case 1:
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insertInHeap(arr, &size, data);
                break;
            case 2:
                deleteMax(arr, &size);
                break;
            case 3:
                makeHeap(arr, size);
                break;
            case 4:
                int decby = 0;
                printf("Enter increment by: ");
                scanf("%d", &decby);
                increaseKey(arr, size, decby);
                break;
            case 5:
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6:
                heapSort(arr, size);
                break;
            default:
                printf("Entered an invalid choice\n");
                break;
        }

        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    return 0;
}