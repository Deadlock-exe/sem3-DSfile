#include <stdio.h>

int main(){
    int size_1;
    printf("Enter number of elements in array 1: ");
    scanf("%d", &size_1);
    int arr1[size_1];

    printf("Enter array: ");
    for(int i=0; i<size_1; i++){
        scanf("%d", &arr1[i]);
    }

    int size_2;
    printf("Enter number of elements in array 2: ");
    scanf("%d", &size_2);
    int arr2[size_2];

    printf("Enter array: ");
    for(int i=0; i<size_2; i++){
        scanf("%d", &arr2[i]);
    }

    int arr[size_1 + size_2];

    int i=0, j=0;
    int k=0;
    while (i < size_1 && j < size_2){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else if(arr1[i]>arr2[j]){
            arr[k] = arr2[j];
            j++;
            k++;
        }
        else if(arr1[i] == arr2[j]){
            arr[k] = arr1[i];
            i++;
            j++;
            k++;
        }
        
    }
    while (i < size_1){
        arr[k++] = arr1[i++];
        }

    while (j < size_2){
       arr[k++] = arr2[j++];
    }

    printf("Merged Array: ");

    for(int x=0; x<k; x++){
        printf("%d ", arr[x]);
    }

    return 0;

}