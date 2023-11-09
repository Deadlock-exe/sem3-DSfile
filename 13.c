#include <stdio.h>
#define SIZE 50

void maxHeapify(int arr[], int n, int i);
void buildMaxHeap(int arr[], int n);
void heapSort(int arr[], int n);

void maxHeapify(int arr[], int n, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int largestIndex = i;

    if (left < n && arr[largestIndex] < arr[left])
        largestIndex = left;
    if (right < n && arr[largestIndex] < arr[right])
        largestIndex = right;

    if (largestIndex != i) {
        int temp = arr[i];
        arr[i] = arr[largestIndex];
        arr[largestIndex] = temp;

        maxHeapify(arr, n, largestIndex);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = 0; i < n; i++) {
        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[0];
        arr[0] = temp;
        maxHeapify(arr, n - i - 1, 0);
    }
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

    heapSort(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}